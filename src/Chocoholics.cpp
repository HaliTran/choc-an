#include "Chocoholics.h"


Chocoholics::Chocoholics() {

}

int Chocoholics::getMember(const int id, Member*& mem) {
    mem = new Member("Black", 876543210, "123th", "portland", "OR", 97000);
    Service* ser;

    // getService(1234, ser);

    return 0;

    //0 = does exist
    //1 = does not exist
}

// int Chocoholics::getProvider(const int id, Provider* pro) {
//     pro = new Provider("Star", 111111111, "321th", "Portland", "OR", 97111);


// }


 int Chocoholics::getServiceData(const int id, Service*& ser) {
     string service_name = "massage";
     int service_code = id;
     double fee = 100;

     ser = new Service();

     ser -> updateServiceName(service_name);
     ser -> updateServiceNum(service_code);
     ser -> updateFee(fee);
     return 0;
 }
