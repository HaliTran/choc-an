#include <iostream>
#include <ctime>
#include <iomanip>
#include "Address.h"
#include "Provider.h"
#include "Manager.h"
using namespace std;
void clear() {
	for (int i = 0; i < 75; i++) cout<<"\n";
}

void mainMenu() {
	char input;
	int id;
	Chocoholics choco;
	Provider* pro = NULL;
	// choco.getMember(123456789, mem);

	choco.getProvider(123456789, pro);

	Provider* test;
	// choco.insertProvider(pro);


	
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
					int flag = choco.selectProvider(id, provider);
					if (provider != NULL) {
						cout<<"Name: "<<provider->getUserName()<<endl;
						provider->menu();
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

int main(int argc, char* argv[]) {
	time_t t = time(NULL);
	struct tm * ct;
	time (&t);
	ct = localtime (&t);



	mainMenu();
	return 0;
}


