#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <list>
#include "Provider.h"
#include "Member.h"

class Manager {
    public:
        Manager();
        ~Manager();
    
        void menu();
    protected:
        vector<Provider> provider_list;
        vector<Member> member_list;

};