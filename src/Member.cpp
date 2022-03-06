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

bool generateReport()
{
    //create text file, 
    ofstream myfile;
    myfile.open ("Member_Report.txt");
    myfile << "Member Report\n";

    myfile << getUserName() << endl;

    //to get member name go to member->addy->information
//Member name (25 characters). 
   //Member number (9 digits). 
   //Member street address (25 characters). 
   //Member city (14 characters). 
   //Member state (2 letters). 
   //Member zip code (5 digits). 
   //For each service provided, the following details are required: 
   //Date of service (MM-DD-YYYY). 
   //Provider name (25 characters). 
   //Service name (20 characters). 

    
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

    //in member vector, service = provider name
    
    



}
