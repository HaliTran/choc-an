#include "Manager.h"

//manager constructor and destructor
Manager::Manager(){}

Manager::~Manager(){}

//display menu option for user
void Manager::menu(){
    int input;
    do
    {
        cout<<"1 = Add member to the ChocAn Database"<<endl;
        cout<<"2 = Add provider to the ChocAn Database"<<endl;
        cout<<"3 = Delete member from the ChocAn Database"<<endl;
        cout <<"4 = Delete provider from the ChocAn Database" << endl;
        cout <<"5 = Update member information" << endl;
        cout <<"6 = Update provider information" << endl;
        cout <<"7 = Generate report about a member/provider" << endl;
        cout <<"0 = Exit" << endl;
        cout<<"Enter: ";
        if(!(cin >> input))
        {
            cout << "Your input was invalid, please try again!" << endl << endl;
            cin.clear();
            cin.ignore(100,'\n');
            continue;
        }
        
    } while (input != 0);
    
}

