#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <list>
#include <ctime>
#include "Information.h"
#include "Date.h"
using namespace std;


class Service : public Date{
    public:
        Service();
        Service(const string& user_name, const int id, const Date&, 
        const string& svcs_name, const int svcs_code, const int cost);
        Service(const Service& to_copy);
        ~Service();

        string getServiceName();
        int getServiceNumber();
        double getFee();

        void updateServiceName(const string&);
        void updateServiceNum(const int);
        double updateFee(const double);


        bool operator <(const Service&);
        bool operator <=(const Service&);
        bool operator >(const Service&);
        bool operator >=(const Service&);
        bool operator !=(const Service&);
        bool operator ==(const Service&);

    protected:
        string service_name;
        int service_code;
        double fee;
};