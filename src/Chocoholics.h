#pragma once
#include "Provider.h"
#include "Member.h"
#include "Service.h"

class Chocoholics {
    public:
        Chocoholics();
        int getMember(const int id, Member* mem);
        // int getProvider(const int id, Provider* pro);

        int getService(const int id, Service* ser);
    private:
        int test;
};