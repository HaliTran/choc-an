#include "Member.h"

Member::Member()
{
}

Member::Member(const string &u_name, const int id, const string &st, const string &city, const string &state, const int zip)
    : Address(u_name, id, st, city, state, zip)
{
}

Member::Member(Member &to_copy)
    : Address(to_copy)
{
}

Member::~Member()
{
}

bool Member::operator<(const Member &compare)
{
    return Information::operator<(compare.id);
}
bool Member::operator<=(const Member &compare)
{
    return Information::operator<(compare.id);
}
bool Member::operator>(const Member &compare)
{
    return Information::operator<(compare.id);
}
bool Member::operator>=(const Member &compare)
{
    return Information::operator<(compare.id);
}
bool Member::operator!=(const Member &compare)
{
    return Information::operator<(compare.id);
}
bool Member::operator==(const Member &compare)
{
    return Information::operator<(compare.id);
}

Service& Member::getService(const int id) {
    for (auto i : consult) {
        if (i.getId() == id) return i;
    }
    Service temp;
    return temp;
}

bool Member::generateReport()
{
    //create text file, 
    ofstream myfile;
    myfile.open ("Member_Report.txt");
    if (!myfile.is_open())
    {
        cout << "Error Generating Member Report" << endl;
        return 1;
    }
    //else open

    myfile << "Member Report" << endl;
    myfile << getUserName() << endl;    //Member name (25 characters). 
    myfile << getId() << endl;          //Member number (9 digits).
    myfile << getStreet() << endl;      //Member street address (25 characters)
    myfile << getCity() << endl;        //Member city (14 characters). 
    myfile << getState() << endl;       //Member state (2 letters). 
    myfile << getZipCode() << endl;     //Member zip code (5 digits).
    
    vector<Service> consult;
        
    for (auto i = consult.begin(); i != consult.end(); ++i)
    {
        //Date of service (MM-DD-YYYY).
        myfile << *i.getMonth() << *i.getDay() << *i.getYear() << *i.getCompTime() << endl;
        myfile << *i.getUserName() << endl;     //Provider name (25 characters)
        myfile << *i.getServiceName() << endl;   //Service name (20 characters). 
    }

    //Date of service (MM-DD-YYYY). 
    //Provider name (25 characters). 
    //Service name (20 characters). 

    //to get member name go to member->addy->information

   //For each service provided, the following details are required: 

    // Address class contain
    /*
        string street;
        string city;
        string state;
        int zip_code;

    //Member class has service vector contains
        string service_name;
        int service_code;
        double fee;
        string comment;
    // Date includes
        int month;
        int day;
        int year;
        time_t comp_time;

    */
    myfile.close(); 


}
