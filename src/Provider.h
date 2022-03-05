#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "Service.h"
#include "Address.h"
using namespace std;

class Provider : public Address{
    public:
        Provider();
        Provider(const string& u_name, const int id, const string& st, const string& city, const string& state, const int zip);
        Provider(Provider&);
        ~Provider();

        bool deleteService(const int);
        void recordService(const Service&);
        
        int getTotalConsultations();
        int getTotalFee();
    
        bool generateReport();
        Service& getService(const int id);

    protected:
        vector<Service> Service_list;
        int total_consultations;
        int total_fee;


};