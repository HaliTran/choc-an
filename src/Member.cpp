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
    filename += to_string(getId());  //filename is provider_id
    filename.append(".txt");    // append ".txt" = provider_id.txt

    cout<<"Filename: "<<filename<<endl;


    myfile.open (filename);
    if (!myfile.is_open())
    {
        cout << "Error Generating Member Report" << endl;
        return true;
    }
    //else open
    myfile<<"    Chocoholics Anonymous Member Report    "<<endl;
    myfile<<"\n"<<endl;
    myfile<<getUserName() <<endl;
    myfile<<getStreet()<<endl;
    myfile<<getCity()<<", "<<getState()<<endl;
    myfile<<getZipCode()<<endl;
    myfile<<"Account number: "<<getId()<<endl;
    myfile<<"\n"<<endl;
    myfile<<"    "<<"Service consulted"<<endl;
    for (auto i : consult) {
        //Date of service (MM-DD-YYYY).
        myfile<<"    "<<"Date of Service: "<<i->getMonth()<<"-"<<i->getMonth()<<"-"<<i->getDay()<<endl;
        myfile<<"    "<<"Provider: "<<i->getUserName()<<endl;
        myfile<<"    "<<"Service: "<<i->getServiceName()<<endl;
        myfile<<"\n";
    }
    myfile.close(); 
    return false;
}

vector<Service*>& Member::getAllService() {
    return consult;
}
