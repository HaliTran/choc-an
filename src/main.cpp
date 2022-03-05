#include <iostream>
#include "Address.h"

int main(int argc, char* argv[]) {
	string name = "Jack";
	string st = "45th";
	string city = "Portland";
	string state = "OR";


	Address test;
	test.updateUserName(name);

	cout<<test.getUserName()<<endl;

	name = "jake";
	test.updateUserName(name);
	cout<<test.getUserName()<<endl;
}
