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

int Member::getService(const int id, Service* ser) {
    for (auto i : consult) {
        if (i->getId() == id) {
            ser = i;
            return 0;
        }
    }
    return 1;
}

void Member::recordService(Service& ser) {
    consult.push_back(&ser);
}

bool Member::generateReport()
{
    //create text file, 
    ofstream myfile;

    string filename = "Reports/";
    //filename.append( getId() );  //filename is member_id
    //filename.append(".txt");    // append ".txt" = member_id.txt

    myfile.open (filename);
    if (!myfile.is_open())
    {
        cout << "Error Generating Member Report" << endl;
        return true;
    }
    //else open
    myfile << "Member Report"   << endl;
    myfile << getUserName() << endl;    //Member name (25 characters). 
    myfile << getId()       << endl;          //Member number (9 digits).
    myfile << getStreet()   << endl;      //Member street address (25 characters)
    myfile << getCity()     << endl;        //Member city (14 characters). 
    myfile << getState()    << endl;       //Member state (2 letters). 
    myfile << getZipCode()  << endl;     //Member zip code (5 digits).

    for (auto i : consult)
    {
        //Date of service (MM-DD-YYYY).
        myfile << i->getMonth() << i->getDay() << i->getYear() << i->getCompTime() << endl;
        myfile << i->getUserName() << endl;     //Provider name (25 characters)
        myfile << i->getServiceName() << endl;   //Service name (20 characters). 
    }
    myfile.close(); 

    return false;
}
