#include "Service.h"

Service::Service() {

}
Service::Service(const string& user_name, const int id, const Date& date, 
const string& svcs_name, const int svcs_code, const int cost) 
    :Date(user_name, id, date), service_name(svcs_name), service_code(svcs_code), fee(cost){

}
Service::Service(const Service& to_copy)
    :Date(to_copy) {

}

Service::~Service() {

}

string Service::getServiceName() {
    return service_name;

}
int Service::getServiceNumber() {
    return service_code;
}
double Service::getFee() {
    return fee;
}

void Service::updateServiceName(const string& svcs_name) {
    service_name = svcs_name;
}
void Service::updateServiceNum(const int svcs_code) {
    service_code = svcs_code;
}
double Service::updateFee(const double new_fee) {
    fee = new_fee;
}


bool Service::operator <(const Service& cp) {
}
bool Service::operator <=(const Service&) {

}
bool Service::operator >(const Service&) {

}
bool Service::operator >=(const Service&) {

}
bool Service::operator !=(const Service&) {

}
bool Service::operator ==(const Service&) {

}