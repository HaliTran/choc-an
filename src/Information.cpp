#include "Information.h"

//constructors
Information::Information()
{
	user_name = NULL;
	id = 0;
}


Information::Information(const string&, const int id_num)
{
	user_name = string;
	id = id_num;
}


Information::Information(const Information &to_copy)
{
	user_name = to_copy.user_name;
	id = to_copy.id;
}
