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
<<<<<<< HEAD
	Provider test(name, id, st, city, state, zip);
	test.menu();

	//manager tester
	
=======
	//Provider test(name, id, st, city, state, zip);
	Manager test2;
	test2.menu();
	//test.menu();
>>>>>>> 9be4b7b42eadab55913b30d075de7693925f501f
}
