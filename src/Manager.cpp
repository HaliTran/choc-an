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

        cin.ignore(100,'\n');

        if(input == 1)
            add_provider_member();

        
    } while (input != 0);
    
}

//function to add member to the ChocAn Database
void Manager::add_member()
{
    string name;
    int id;
    string st;
    string city;
    string state;
    int zip;

    //getting user input regarding a member
    cout << "Member's name: ";
    getline(cin,name,'\n');
    
    cout << "Member's ID number: ";
    cin >> id;
    cin.ignore();

    cout << "Member's street address: ";
    getline(cin,st,'\n'); 
    
    cout << "Member's city: ";
    getline(cin,city,'\n');

    cout << "Member's state: ";
    getline(cin,state,'\n');

    cout << "Member's zip code: ";
    cin >> zip;
    cin.ignore(100,'\n');

    //creating member object
    Member * a_mem = new Member(name, id, st, city, state, zip);
    member_list.push_back(a_mem);
    return;
}

//function to add a provider to the ChocAn database
void Manager::add_provider()
{
    string name;
    int id;
    string st;
    string city;
    string state;
    int zip;

    //getting user input regarding a member
    cout << "Provider's name: ";
    getline(cin,name,'\n');
    
    cout << "Provider's ID number: ";
    cin >> id;
    cin.ignore();

    cout << "Provider's street address: ";
    getline(cin,st,'\n'); 
    
    cout << "Provider's city: ";
    getline(cin,city,'\n');

    cout << "Provider's state: ";
    getline(cin,state,'\n');

    cout << "Provider's zip code: ";
    cin >> zip;
    cin.ignore(100,'\n');

    //creating member object
    Provider * a_pro = new Provider(name, id, st, city, state, zip);
    provider_list.push_back(a_pro);
    return;
}
