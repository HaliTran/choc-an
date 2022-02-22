#include "Member.h"

Member::Member() {
}

Member::Member(const string& u_name, const int id, const string& st, const string& city, const string& state, const int zip) 
    :Address(u_name, id, st, city, state, zip) {

}

Member::Member(Member& to_copy) 
    :Address(to_copy.u_name, to_copy.id, to_copy.st, to_copy.city, to_copy.state, to_copy.zip_code) {

}

Member::~Member() {

}

bool Member::operator<(const Member& compare) {
    return Information<(compare.id);
}
bool Member::operator<=(const Member& compare) {
    return Information<=(compare.id);
}
bool Member::operator>(const Member& compare) {
    return Information>(compare.id);
}
bool Member::operator>=(const Member& compare) {
    return Information>=(compare.id);
}
bool Member::operator!=(const Member& compare) {
    return Information!=(compare.id);
}
bool Member::operator==(const Member& compare) {
    return Information==(compare.id);
}
