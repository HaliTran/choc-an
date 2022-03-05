#include "Member.h"

Member::Member()
{
}

Member::Member(const string &u_name, const int id, const string &st, const string &city, const string &state, const int zip)
    : Address(u_name, id, st, city, state, zip)
{
}

Member::Member(Member &to_copy)
    : Address(to_copy)
{
}

Member::~Member()
{
}

bool Member::operator<(const Member &compare)
{
    return Information::operator<(compare.id);
}
bool Member::operator<=(const Member &compare)
{
    return Information::operator<(compare.id);
}
bool Member::operator>(const Member &compare)
{
    return Information::operator<(compare.id);
}
bool Member::operator>=(const Member &compare)
{
    return Information::operator<(compare.id);
}
bool Member::operator!=(const Member &compare)
{
    return Information::operator<(compare.id);
}
bool Member::operator==(const Member &compare)
{
    return Information::operator<(compare.id);
}

Service& Member::getService(const int id) {
    for (auto i : consult) {
        if (i.getId() == id) return i;
    }
    Service temp;
    return temp;
}
