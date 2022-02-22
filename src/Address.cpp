// Addy CLass funcs
Address::Address()
{
    zip_code = 0;
}
Address::Address(const string& u_name, const int id, const string& st, const string& new_city, 
                        const string& new_state, const int new_zip):Information(u_name, id) , 
                                    string(st) , city(new_city) , state(new_state), zip(new_zip)

{}
Address::Address(const Information &to_copy):Information(to_copy)
{}
Address::~Address()
{}
string Address::getStreet()
{
     return street;
}
string Address::getCity()
{
    return city; 
}
string Address::getState()
{
   return State;
}
int Address::getZipCode()
{
    return zip_code;  
}
void Address::updateStreet(const int new_street): street(new_street) 
{}
void Address::updateCity(const string& new_city): city(new_city)
{}
void Address::updateState(const string&): state(new_state)
{}
void Address::updateZipCode(const int new_zip): zip_code(new_zip)
{}
        
