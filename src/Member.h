#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "Service.h"
#include "Address.h"
using namespace std;

class Member : public Address{
    protected:
        vector<Service> consult;
    public:
        Member();
        Member(const string& u_name, const int id, const string& st, const string& city, const string& state, const int zip);
        Member(Member& to_copy);
        ~Member();

        bool operator<(const Member& compare);
        bool operator<=(const Member& compare);
        bool operator>(const Member& compare);
        bool operator>=(const Member& compare);
        bool operator!=(const Member& compare);
        bool operator==(const Member& compare);

        bool generateReport();
};