#include "Information.h"

//constructors
Information::Information()
{
	id = 0;
}


Information::Information(const string& string_copy, const int id_num)
{
	user_name = string_copy;
	id = id_num;
}


Information::Information(const Information &to_copy)
{
	user_name = to_copy.user_name;
	id = to_copy.id;
}


void Information::updateUserName(const string& to_update)
{
	user_name = to_update;
}


void Information::updateId(const int new_id)
{
	id = new_id;
}

int Information::getId()
{
	return id;
}


string Information::getUserName()
{
	return user_name;
}
