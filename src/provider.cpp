#include "Provider.h"
#include "Chocoholics.h"

Provider::Provider()
{
    total_consultations = 0;
    total_fee = 0;
}

Provider::Provider(const string &u_name, const int id, const string &st, const string &city, const string &state, const int zip) : Address(u_name, id, st, city, state, zip)
{
    total_consultations = 0;
    total_fee = 0;
}

Provider::Provider(Provider &source) : Address(source)
{

    int size = source.Service_list.size();
    for (int i = 0; i < size; ++i)
    {
        Service_list.push_back(source.Service_list[i]);
    }
    total_consultations = source.total_consultations;
    total_fee = source.total_fee;
}

Provider::~Provider()
{
    Service_list.clear();
}

int Provider::getTotalConsultations()
{
    return total_consultations;
}

int Provider::getTotalFee()
{
    return total_fee;
}

Service& Provider::getService(const int id) {
    for (auto i : Service_list) {
            if (i.getId() == id) return i;
        }
        Service temp;
        return temp;
}


void Provider::menu() {
    char input;
    do {
        cout<<"1 = Enter information about service provided to a member"<<endl;
        cout<<"2 = Request Provider dictory"<<endl;
        cout<<"0 = Exit"<<endl;
        cout<<"Enter: ";
        cin>>input;
        cin.ignore(100, '\n');

        if (input == '1') {
            int mem_id;
            cout<<"Enter Member ID number: ";

            try {
                cin>>mem_id;
                cin.ignore(100, '\n');
                throw mem_id;
            } catch (const exception& e) {
                cerr<<e.what()<<endl;
            } catch (int mem_id) {
                if (!(mem_id >= 100000000 && mem_id <= 999999999)) {
                    cout<<"Error please try again"<<endl;
                } 
            }
            Chocoholics choco;
            Member* mem;
            if (choco.getMember(mem_id, mem) == 0) {
                //else failed input
            }

        }else if (input == '2') {

        }
    }while(input != '0');
}


void Provider::inputService(Member& mem) {
    
}

bool generateReport()
{

    return true;
}
