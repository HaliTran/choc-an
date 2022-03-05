#include "Provider.h"

Provider::Provider()
{
    total_consultations = 0;
    total_fee = 0;
}

Provider::Provider(const string &u_name, const int id, const string &st, const string &city, const string &state, const int zip) : Address(u_name, id, st, city, state, zip)
{
    total_consultations = 0;
    total_fee = 0;
}

Provider::Provider(Provider &source) : Address(source)
{

    int size = source.Service_list.size();
    for (int i = 0; i < size; ++i)
    {
        Service_list.push_back(source.Service_list[i]);
    }
    total_consultations = source.total_consultations;
    total_fee = source.total_fee;
}

Provider::~Provider()
{
    Service_list.clear();
}

int Provider::getTotalConsultations()
{
    return total_consultations;
}

int Provider::getTotalFee()
{
    return total_fee;
}