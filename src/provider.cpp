#include "Provider.h"


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

int Provider::getService(const int id, Service* ser) {
    for (auto i : Service_list) {
            if (i->getId() == id) {
                ser = i;
                return 0;
            }
        }
    return 1;
}


void Provider::menu() {
    char input;
    do {
        cin.clear();
        cout<<"1 = Enter information about service provided to a member"<<endl;
        cout<<"2 = Request Provider dictory"<<endl;
        cout<<"0 = Exit"<<endl;
        cout<<"Enter: ";

        cin>>input;
        cin.ignore(100, '\n');

        if (input == '1') {
            int mem_id;
            cout<<"Enter Member ID number: ";

            if (!(cin>>mem_id)) {
                cout<<"Error not a number, please input a number"<<endl;
                continue;
            } 
            Chocoholics choco;
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
    
    char service_comment[100];
    int service_code;
    int service_year;
    int service_month;
    int service_day;
    int input;
    do {
        cout<<"Please input Service code: ";
        if (!(cin >> input)) {
            cin.ignore(100, '\n');
            cout<<"INVALID INPUT: CODE"<<endl;
            continue;
        } else {
            cin.ignore(100, '\n');
            service_code = input;
        }

        cout<<"Please input Month: ";
        if (!(cin >> input)) {
            cin.ignore(100, '\n');
            cout<<"INVALID INPUT: MONTH"<<endl;
            continue;
        }else {
            cin.ignore(100, '\n');
            service_month = input;
        }

        cout<<"Please input day: ";
        if (!(cin >> input)) {
            cin.ignore(100, '\n');
            cout<<"INVALID INPUT: DAY"<<endl;
            continue;
        }else {
            cin.ignore(100, '\n');
            service_day = input;
        }

        cout<<"Please input Year: ";
        cin>>service_year;
        cin.ignore(100, '\n');

        cout<<"Please input a comment: ";
        cin.get(service_comment, 100, '\n');
        cin.ignore(100, '\n');
        input = 0;

    } while(input != 0);

    cout<<"Service code: "<<service_code<<endl;
    cout<<"Date: "<<service_month<<"/"<<service_day<<"/"<<service_year<<endl;

    Chocoholics choco;
    Service* ser_data;
    choco.getService(123456, ser_data);

    Service* member_ser = new Service();
    member_ser->updateUserName(user_name);
    member_ser->updateId(id);
    member_ser->updateYear(service_year);
    member_ser->updateMonth(service_month);
    member_ser->updateDay(service_day);
    member_ser->updateServiceName(ser_data->getServiceName());
    member_ser->updateServiceNum(ser_data->getServiceNumber());
    member_ser->updateFee(ser_data->getFee());
    member_ser->updateComment(service_comment);
    mem.recordService(*member_ser);
    //created data for member service
  

    Service* provider_ser = new Service;
    provider_ser->updateUserName(mem.getUserName());
    provider_ser->updateId(mem.getId());
    provider_ser->updateYear(service_year);
    provider_ser->updateMonth(service_month);
    provider_ser->updateDay(service_day);
    provider_ser->updateServiceName(ser_data->getServiceName());
    provider_ser->updateServiceNum(ser_data->getServiceNumber());
    provider_ser->updateFee(ser_data->getFee());
    provider_ser->updateComment(service_comment);

    Service_list.push_back(provider_ser);
   
}

bool generateReport()
{
    // ofstream myfile;

    // string filename = "Reports/";
    // filename.append( getId() );  //filename is provider_id
    // filename.append(".txt");    // append ".txt" = provider_id.txt

    // myfile.open (filename);
    // if (!myfile.is_open())
    // {
    //     cout << "Error Generating Provider Report" << endl;
    //     return true;
    // }
    // //else open

    // //Provider name (25 characters). 
    // //Provider number (9 digits). 
    // //Provider street address (25 characters). 
    // //Provider city (14 characters). 
    // //Provider state (2 letters). 
    // //Provider zip code (5 digits). 
    // //For each service provided, the following details are required: 
    // //Date of service (MM-DD-YYYY). 
    // //Date and time data were received by the computer (MM-DD-YYYY 

    // //Member name (25 characters). 
    // //Member number (9 digits). 
    // //Service code (6 digits). 
    // //Fee to be paid (up to $999.99). 
    // //Total number of consultations with members (3 digits). 
    // //Total fee for the week (up to $99,999.99). 
    
    // myfile << "Member Report" << endl;
    // myfile << getUserName() << endl;    //Member name (25 characters). 
    // myfile << getId() << endl;          //Member number (9 digits).
    // myfile << getStreet() << endl;      //Member street address (25 characters)
    // myfile << getCity() << endl;        //Member city (14 characters). 
    // myfile << getState() << endl;       //Member state (2 letters). 
    // myfile << getZipCode() << endl;     //Member zip code (5 digits).

    // for (auto i : consult)
    // {
    //     //Date of service (MM-DD-YYYY).
    //     myfile << i.getMonth() << i.getDay() << i.getYear() << i.getCompTime() << endl;
    //     myfile << i.getUserName() << endl;     //Provider name (25 characters)
    //     myfile << i..getServiceName() << endl;   //Service name (20 characters). 
    // }
    // myfile.close(); 

    // return false;



}
