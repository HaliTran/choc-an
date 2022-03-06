#include <iostream>
#include "Address.h"
#include "Provider.h"
#include "Manager.h"

void clear() {
	for (int i = 0; i < 75; i++) cout<<"\n";
}

int main(int argc, char* argv[]) {
	string name = "Jack";
	int id = 123456789;
	string st = "45th";
	string city = "Portland";
	string state = "OR";
	int zip = 12345;
	Provider test(name, id, st, city, state, zip);
	test.menu();
	// Manager test2;
	// test2.menu();
	//test.menu();
}
