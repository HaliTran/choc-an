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
        void add_member();
        void add_provider();
        void update_member();
        void update_provider();

    protected:
        vector<Provider*> provider_list;
        vector<Member*> member_list;

};