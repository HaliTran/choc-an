#pragma once
#include "Provider.h"
#include "Member.h"

class Chocoholics {
    public:
        int getMember(const int id, Member* mem);
        int getProvider(const int id, Provider* pro);

        int getService(const int id, Service* ser);

};