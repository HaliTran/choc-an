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
            Member* mem;
            if (choco.getMember(mem_id, mem) == 0) {

                inputService(*mem);
            }
            else cout<<"ID not found"<<endl;

        }else if (input == '2') {

        }
    }while(input != '0');
}


void Provider::inputService(Member& mem) {
    Service* ser;
    choco.getService(123456, ser);



}

bool generateReport()
{
    ofstream myfile;

    string filename = "Reports/";
    filename.append( getId() );  //filename is provider_id
    filename.append(".txt");    // append ".txt" = provider_id.txt

    myfile.open (filename);
    if (!myfile.is_open())
    {
        cout << "Error Generating Provider Report" << endl;
        return true;
    }
    //else open

    //Provider name (25 characters)



    //Provider number (9 digits). 
    //Provider street address (25 characters). 
    //Provider city (14 characters). 
    //Provider state (2 letters). 
    //Provider zip code (5 digits). 
    //For each service provided, the following details are required: 
    //Date of service (MM-DD-YYYY). 
    //Date and time data were received by the computer (MM-DD-YYYY 

    //Member name (25 characters). 
    //Member number (9 digits). 
    //Service code (6 digits). 
    //Fee to be paid (up to $999.99). 
    //Total number of consultations with members (3 digits). 
    //Total fee for the week (up to $99,999.99). 
    /*
    myfile << "Member Report" << endl;
    myfile << getUserName() << endl;    //Member name (25 characters). 
    myfile << getId() << endl;          //Member number (9 digits).
    myfile << getStreet() << endl;      //Member street address (25 characters)
    myfile << getCity() << endl;        //Member city (14 characters). 
    myfile << getState() << endl;       //Member state (2 letters). 
    myfile << getZipCode() << endl;     //Member zip code (5 digits).

    for (auto i : consult)
    {
        //Date of service (MM-DD-YYYY).
        myfile << i.getMonth() << i.getDay() << i.getYear() << i.getCompTime() << endl;
        myfile << i.getUserName() << endl;     //Provider name (25 characters)
        myfile << i..getServiceName() << endl;   //Service name (20 characters). 
    }
    myfile.close(); 
    */
    return false;



}
