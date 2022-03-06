#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <list>
#include "Provider.h"
#include "Member.h"
#include <vector>
using namespace std;

class Manager {
    public:
        Manager();
        ~Manager();
    
        void menu();
        void add_provider_member();

    protected:
        vector<Provider*> provider_list;
        vector<Member*> member_list;

};