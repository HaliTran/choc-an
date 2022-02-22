Address::Address()
{

}
Address::Address(const string& u_name, const int id, const string& st, const string& city, 
                        const string& state, const int zip);

Address::Address(const Information &to_copy)
{

}
Address::~Address()
{


}
string Address::getStreet(){


}
string Address::getCity()
{

}
string Address::getState()
{

}
int Address::getZipCode()
{

}

        void Address::updateStreet(const int);
        void Address::updateCity(const string&);
        void Address::updateState(const string&);
        void Address::updateZipCode(const int);
        
    protected:
        string street;
        string city;
        string State;
        int zip_code;
};

//comment