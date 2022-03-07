#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "Service.h"
#include "Address.h"
#include "Member.h"
#include "Provider.h"
#include "Chocoholics.h"


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
    
        bool generateReport(int member_id);
        int getService(const int id, Service*& ser);

        void menu();


    protected:
        vector<Service*> Service_list;
        int total_consultations;
        int total_fee;

        void validateService(Member& mem); //prompts the provider for data
        void inputService(Member& mem, Service*& ser_data, int service_code, int service_year, 
        int service_month, int service_day, char* service_comment); //data gets stored


};