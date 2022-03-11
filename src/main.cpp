#include <iostream>
#include <ctime>
#include <iomanip>
#include "Address.h"
#include "Provider.h"
#include "Manager.h"
using namespace std;

void addData();
void clear() {
	for (int i = 0; i < 75; i++) cout<<"\n";
}


void mainMenu() {
	char input;
	int id;
	Chocoholics choco;

	Provider* provider = NULL;
	Manager* manager;
	do {
        cout << "------------------------------------------" << endl;
		cout<<"1 = Provider"<<endl;
		cout<<"2 = Manager"<<endl;
		cout<<"0 = Exit"<<endl;
        cout << "------------------------------------------" << endl;
		cout<<"Enter: ";
		cin>>input;
		cin.ignore(100, '\n');

		if (input == '0') return ;

		cout<<"Please enter your ID Number: ";

		if (!(cin>>id)) {
                cout<<"Error not a number, please input a number"<<endl;
				cin.ignore(100, '\n');
            } else if (id < 100000000 || id > 999999999) {
				cout<<"Error Invalid Number"<<endl;
				cin.ignore(100, '\n');
			} else {
				cin.ignore(100, '\n');
				if (input == '1') {
					choco.selectProvider(id, provider);
					if (provider != NULL) {
						cout<<"Name: "<<provider->getUserName()<<endl;
						provider->menu();
						choco.deleteProvider(provider->getId());
						choco.insertProvider(provider);
					}
				}

				if (input == '2') {
					manager = new Manager;
					manager -> menu();
					delete manager;
				}
			}
		
	}while(input != '0');
}



//for testing purpose
//Provider = 123123123 or 456456456
//Member = 100000000 or 200000000 or 300000000
//for more data look line 80

int main() {
	//addData(); //only use when the database is empty
	// Chocoholics ch;

	// Provider* test = NULL;
	// ch.selectProvider(23453535, test);
	// if (test != NULL) {
	// 	test->generateReport();
	// } else cout<<"test is NULL"<<endl;
	mainMenu();

	return 0;
}




void addData() { //adds data to database for testing
	Chocoholics choco;

	Service* ser1 = new Service;
	Service* ser2 = new Service;
	Service* ser3 = new Service;
	Service* ser4 = new Service;

	ser1->updateServiceName("Therapy");
	ser1->updateServiceNum(999999);
	ser1->updateFee(299);
	choco.deleteService(999999);
	choco.insertService(ser1);

	ser2->updateServiceName("Chiropractor");
	ser2->updateServiceNum(888888);
	ser2->updateFee(120);
	choco.deleteService(888888);
	choco.insertService(ser2);
	


	ser3->updateServiceName("Counseling");
	ser3->updateServiceNum(777777);
	ser3->updateFee(199);
	choco.deleteService(777777);
	choco.insertService(ser3);

	ser4->updateServiceName("Massage");
	ser4->updateServiceNum(666666);
	ser4->updateFee(70);
	choco.deleteService(666666);
	choco.insertService(ser4);

	Member* m1 = new Member("John Smith", 100000000, "123 NE Glison ST", "Portland", "OR", 97000);
	Member* m2 = new Member("Natnael Yohannes", 200000000, "1111 N 456TH St", "Seattle", "WA", 98200);
	Member* m3 = new Member("Black Jesus", 300000000, "00000 SKY", "Heaven", "HV", 0);

	choco.deleteMember(100000000);
	choco.deleteMember(200000000);
	choco.deleteMember(300000000);

	choco.insertMember(m1);
	choco.insertMember(m2);
	choco.insertMember(m3);
	

	Provider* p1 = new Provider("Kaiser Permanente", 123123123, "500 NE Multnomah St", "Portland", "OR", 97232);
	Provider* p2 = new Provider("KingSong", 456456456, "456 SW Stark St", "Portland", "OR", 97069);

	choco.deleteProvider(123123123);
	choco.deleteProvider(456456456);

	choco.insertProvider(p1);
	choco.insertProvider(p2);

}