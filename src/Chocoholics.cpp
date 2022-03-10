#include "Provider.h"
#include "sqlite3.h"
#include <cstring>

using namespace std;

Chocoholics::Chocoholics() {
    path = "DATA.db";
    createTable();
}

int Chocoholics::getMember(const int id, Member*& mem) {
    mem = new Member("Black", 876543210, "123th", "portland", "OR", 97000);
    Service* ser1;
    getServiceData(1234, ser1);
    mem->recordService(*ser1);

    Service* ser = new Service;

    string service_name = "BBC";
    int service_code = id;
    double fee = 100;

    ser -> updateUserName("Apple");
    ser -> updateId(222222222);
    ser -> updateServiceName(service_name);
    ser -> updateServiceNum(service_code);
    ser -> updateFee(fee);


    mem->recordService(*ser);

    return 0;

    //0 = does exist
    //1 = does not exist
}

int Chocoholics::getProvider(const int id, Provider*& pro) {
    pro = new Provider("Star", 123123123, "321th", "Portland", "OR", 97111);
    Service* ser;
    getServiceData(123456, ser);
    pro->recordService(*ser);

    return 0;

}


 int Chocoholics::getServiceData(const int id, Service*& ser) {

    string service_name = "Massage";
    int service_code = id;
    double fee = 100;

    ser = new Service();
    ser -> updateUserName("John");
    ser -> updateId(123456);
    ser -> updateServiceName(service_name);
    ser -> updateServiceNum(service_code);
    ser -> updateFee(fee);
    return 0;

 }



 void Chocoholics::createTable() {
    sqlite3* DB;
    char* messageError;
    sqlite3_open(path.c_str(), &DB);

    string query = "CREATE TABLE IF NOT EXISTS USERS ("
	"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
	"USER_NAME TEXT NOT NULL, "
	"STREET TEXT NOT NULL, "
    "CITY TEXT NOT NULL, "
    "STATE TEXT NOT NULL, "
    "ZIP_CODE INTEGER);";

    try {
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		int exit = sqlite3_exec(DB, query.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function: "<<messageError<< endl;
			sqlite3_free(messageError);
		} else cout << "Table created Successfully" << endl;

	} catch (const exception& e) {
		cerr << e.what();
	}


    string query1 = "CREATE TABLE IF NOT EXISTS SERVICES ("
    "PARENT_ID INTEGER, "
    "ID INTERGER, "
    "USER_NAME TEXT NOT NULL, "
    "MONTH INTEGER, "
    "DAY INTEGER, "
    "YEAR INTEGER, "
    "COMP_TIME INTEGER, "
    "SERVICE_NAME TEXT NOT NULL, "
    "SERVICE_CODE INTEGER, "
    "FEE INTEGER, "
    "COMMENT TEXT, "
    "TABLE_KEY INTEGER PRIMARY KEY, "
    "UNIQUE (TABLE_KEY), "
    "FOREIGN KEY (PARENT_ID) REFERENCES USERS(ID));";

    try {
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		int exit = sqlite3_exec(DB, query1.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK) {
			cerr << "Error : createTable : "<<messageError<< endl;
			sqlite3_free(messageError);
		} else cout << "Table created Successfully" << endl;

	} catch (const exception& e) {
		cerr << e.what();
	}
    sqlite3_close(DB);
 }

 int Chocoholics::insertMember(Member*& mem) {
    char* messageError;
    sqlite3* DB;
    sqlite3_open(path.c_str(), &DB);

    string q = "PRAGMA foreign_keys = ON;";
    int exit = sqlite3_exec(DB, q.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error : insertData : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout << "Foreign key on!" << endl;
    string q1 = "INSERT OR REPLACE INTO USERS ('ID', 'USER_NAME', 'STREET', 'CITY', 'STATE','ZIP_CODE') VALUES (";
    q1 += "'"; q1 += to_string(mem->getId()); q1 += "', ";
    q1 += "'"; q1 += mem->getUserName(); q1 += "', ";
    q1 += "'"; q1 += mem->getStreet(); q1 += "', ";
    q1 += "'"; q1 += mem->getCity(); q1 += "', ";
    q1 += "'"; q1 += mem->getState(); q1 += "', ";
    q1 += "'"; q1 += to_string(mem->getZipCode()); q1 += "')";
    

	exit = sqlite3_exec(DB, q1.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error : insertData : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout << "Records inserted Successfully!" << endl;
    

    vector <Service*> ser = mem->getAllService();

    for (auto i : ser) {
        string q2 = "INSERT OR REPLACE INTO SERVICES ('PARENT_ID', 'ID', 'USER_NAME', 'MONTH', 'DAY', 'YEAR', 'COMP_TIME', 'SERVICE_NAME', 'SERVICE_CODE', 'FEE', 'COMMENT') VALUES (";
        q2 +="'"; q2 += to_string(mem->getId()); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getId()); q2 +="', ";
        q2 +="'"; q2 += i->getUserName(); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getMonth()); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getDay()); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getYear()); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getCompTime()); q2 +="', ";
        q2 +="'"; q2 += i->getServiceName(); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getServiceNumber()); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getFee()); q2 +="', ";
        q2 +="'"; q2 += i->getComment(); q2 +="'); ";
        


    exit = sqlite3_exec(DB, q2.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error : insertData : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout << "Records inserted Successfully!" << endl;

    }

    sqlite3_close(DB);
}


int Chocoholics::selectMember(const int key, Member*& mem) {

    char* messageError;
    sqlite3* DB;
    sqlite3_open(path.c_str(), &DB);

    string query= "SELECT * FROM USERS WHERE ID = ";
    query += to_string(key);
    mem = new Member;

    int exit = sqlite3_exec(DB, query.c_str(), callbackMem, mem, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error : selectData : "<<messageError<< endl;
		sqlite3_free(messageError);
	};

    string q1 = "SELECT * FROM SERVICES WHERE PARENT_ID = ";
    q1 += to_string(mem->getId());

    exit = sqlite3_exec(DB, q1.c_str(), callbackServiceMem, &mem->getAllService(), &messageError);

	if (exit != SQLITE_OK) {
		cerr << "Error : selectData : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else;

    sqlite3_close(DB);

}


int Chocoholics::callbackMem(void* mem, int argc, char** argv, char** azColName){
	for (int i = 0; i < argc; i++) {
		// column name and value
        callbackMemApp(mem, argv[i], azColName[i]);
	}
	return 0;
}
void Chocoholics::callbackMemApp(void* mem, char* argv, char* azColName) {
    Member* ptr = reinterpret_cast<Member*> (mem);
    if (strcmp(azColName, "ID") == 0 ) ptr -> updateId(atoi(argv));
    if (strcmp(azColName, "USER_NAME") == 0 ) ptr -> updateUserName(argv);
    if (strcmp(azColName, "STREET") == 0 ) ptr -> updateStreet(argv);
    if (strcmp(azColName, "CITY") == 0 ) ptr -> updateCity(argv);
    if (strcmp(azColName, "STATE") == 0 ) ptr -> updateState(argv);
    if (strcmp(azColName, "ZIP_CODE") == 0 ) ptr -> updateZipCode(atoi(argv));
}

int Chocoholics::callbackServiceMem(void* ser, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        // cout << azColName[i] << ": " << argv[i] << endl;
        callbackServiceMemApp(ser, argv[i], azColName[i], i);
    }
    return 0;
}


void Chocoholics::callbackServiceMemApp(void* ser, char* argv, char* azColName, int i) {
    vector <Service*>* ptr = reinterpret_cast<vector <Service*>*> (ser);
    if (i % 12 == 0) {
        Service* ser = new Service();
        ptr->push_back(ser);
    }
    int arr = ptr->size() - 1;

    if (strcmp(azColName, "ID") == 0) ptr->operator[](arr)->updateId(atoi(argv));
    if (strcmp(azColName, "USER_NAME") == 0) ptr->operator[](arr)->updateUserName(argv);
    if (strcmp(azColName, "MONTH") == 0) ptr->operator[](arr)->updateMonth(atoi(argv));
    if (strcmp(azColName, "DAY") == 0) ptr->operator[](arr)->updateDay(atoi(argv));
    if (strcmp(azColName, "YEAR") == 0) ptr->operator[](arr)->updateYear(atoi(argv));
    if (strcmp(azColName, "COMP_TIME") == 0) ptr->operator[](arr)->updateCompTime(atoi(argv));
    if (strcmp(azColName, "SERVICE_NAME") == 0) ptr->operator[](arr)->updateServiceName(argv);
    if (strcmp(azColName, "SERVICE_CODE") == 0) ptr->operator[](arr)->updateServiceNum(atoi(argv));
    if (strcmp(azColName, "FEE") == 0) ptr->operator[](arr)->updateFee(atoi(argv));
    if (strcmp(azColName, "COMMENT") == 0) ptr->operator[](arr)->updateComment(argv);
}




 int Chocoholics::insertProvider(Provider*& mem) {
    char* messageError;
    sqlite3* DB;
    sqlite3_open(path.c_str(), &DB);

    string q = "PRAGMA foreign_keys = ON;";
    int exit = sqlite3_exec(DB, q.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error : insertData : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout << "Foreign key on!" << endl;

    string q1 = "INSERT OR REPLACE INTO USERS ('ID', 'USER_NAME', 'STREET', 'CITY', 'STATE','ZIP_CODE') VALUES (";
    q1 += "'"; q1 += to_string(mem->getId()); q1 += "', ";
    q1 += "'"; q1 += mem->getUserName(); q1 += "', ";
    q1 += "'"; q1 += mem->getStreet(); q1 += "', ";
    q1 += "'"; q1 += mem->getCity(); q1 += "', ";
    q1 += "'"; q1 += mem->getState(); q1 += "', ";
    q1 += "'"; q1 += to_string(mem->getZipCode()); q1 += "')";
    

	exit = sqlite3_exec(DB, q1.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error : insertData : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout << "Records inserted Successfully!" << endl;
    

    vector <Service*> ser = mem->getAllService();

    for (auto i : ser) {
        string q2 = "INSERT OR REPLACE INTO SERVICES ('PARENT_ID', 'ID', 'USER_NAME', 'MONTH', 'DAY', 'YEAR', 'COMP_TIME', 'SERVICE_NAME', 'SERVICE_CODE', 'FEE', 'COMMENT') VALUES (";
        q2 +="'"; q2 += to_string(mem->getId()); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getId()); q2 +="', ";
        q2 +="'"; q2 += i->getUserName(); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getMonth()); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getDay()); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getYear()); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getCompTime()); q2 +="', ";
        q2 +="'"; q2 += i->getServiceName(); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getServiceNumber()); q2 +="', ";
        q2 +="'"; q2 += to_string(i->getFee()); q2 +="', ";
        q2 +="'"; q2 += i->getComment(); q2 +="'); ";
        


    exit = sqlite3_exec(DB, q2.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error : insertData : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout << "Records inserted Successfully!" << endl;

    }

    sqlite3_close(DB);
}



int Chocoholics::selectProvider(const int key, Provider*& pro) {
    char* messageError;
    sqlite3* DB;
    sqlite3_open(path.c_str(), &DB);

    string query= "SELECT * FROM USERS WHERE ID = ";
    query += to_string(key);

    pro = new Provider;

    int exit = sqlite3_exec(DB, query.c_str(), callbackPro, pro, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error : selectData : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout << "Records selected Successfully!" << endl;

    sqlite3_close(DB);
}


int Chocoholics::callbackPro(void* pro, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
		// column name and value
        callbackProApp(pro, argv[i], azColName[i]);
	}
	return 0;
}


void Chocoholics::callbackProApp(void* pro, char* argv, char* azColName) {
    Provider* ptr = reinterpret_cast<Provider*> (pro);
    if (strcmp(azColName, "ID") == 0 ) ptr -> updateId(atoi(argv));
    if (strcmp(azColName, "USER_NAME") == 0 ) ptr -> updateUserName(argv);
    if (strcmp(azColName, "STREET") == 0 ) ptr -> updateStreet(argv);
    if (strcmp(azColName, "CITY") == 0 ) ptr -> updateCity(argv);
    if (strcmp(azColName, "STATE") == 0 ) ptr -> updateState(argv);
    if (strcmp(azColName, "ZIP_CODE") == 0 ) ptr -> updateZipCode(atoi(argv));
}

int Chocoholics::callbackServicePro(void* ser, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
            // cout << azColName[i] << ": " << argv[i] << endl;
            callbackServiceProApp(ser, argv[i], azColName[i], i);
        }
        return 0;
}

void Chocoholics::callbackServiceProApp(void* ser, char* argv, char* azColName, int i) {
    vector <Service*>* ptr = reinterpret_cast<vector <Service*>*> (ser);
    if (i % 12 == 0) {
        Service* ser = new Service();
        ptr->push_back(ser);
    }
    int arr = ptr->size() - 1;

    if (strcmp(azColName, "ID") == 0) ptr->operator[](arr)->updateId(atoi(argv));
    if (strcmp(azColName, "USER_NAME") == 0) ptr->operator[](arr)->updateUserName(argv);
    if (strcmp(azColName, "MONTH") == 0) ptr->operator[](arr)->updateMonth(atoi(argv));
    if (strcmp(azColName, "DAY") == 0) ptr->operator[](arr)->updateDay(atoi(argv));
    if (strcmp(azColName, "YEAR") == 0) ptr->operator[](arr)->updateYear(atoi(argv));
    if (strcmp(azColName, "COMP_TIME") == 0) ptr->operator[](arr)->updateCompTime(atoi(argv));
    if (strcmp(azColName, "SERVICE_NAME") == 0) ptr->operator[](arr)->updateServiceName(argv);
    if (strcmp(azColName, "SERVICE_CODE") == 0) ptr->operator[](arr)->updateServiceNum(atoi(argv));
    if (strcmp(azColName, "FEE") == 0) ptr->operator[](arr)->updateFee(atoi(argv));
    if (strcmp(azColName, "COMMENT") == 0) ptr->operator[](arr)->updateComment(argv);  
}


int Chocoholics::deleteMember(const int key) {
    char* messageError;
    sqlite3* DB;
    sqlite3_open(path.c_str(), &DB);


    string q = "DELETE FROM USERS WHERE ID = ";
    q += to_string(key);
    int exit = sqlite3_exec(DB, q.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error : DeleteMember : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout<<key<<" Deleted"<<endl;



    string q1 = "DELETE FROM SERVICES WHERE PARENT_ID = ";
    q += to_string(key);
    if (exit != SQLITE_OK) {
		cerr << "Error : DeleteMember : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout<<key<<" Deleted"<<endl;

    sqlite3_close(DB);
} 


int Chocoholics::deleteProvider(const int key) {
    char* messageError;
    sqlite3* DB;
    sqlite3_open(path.c_str(), &DB);


    string q = "DELETE FROM USERS WHERE ID = ";
    q += to_string(key);
    int exit = sqlite3_exec(DB, q.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error : DeleteMember : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout<<key<<" Deleted"<<endl;



    string q1 = "DELETE FROM SERVICES WHERE PARENT_ID = ";
    q += to_string(key);
    if (exit != SQLITE_OK) {
		cerr << "Error : DeleteMember : "<<messageError<< endl;
		sqlite3_free(messageError);
	} else cout<<key<<" Deleted"<<endl;

    sqlite3_close(DB);
} 



int Chocoholics::insertService(Service*& ser) {

}
int Chocoholics::selectService(const int key, Service*& ser) {

}
int Chocoholics::deleteService(const int key) {

}
vector<Service*>& Chocoholics::selectAllService() {
    
}