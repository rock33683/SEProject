#include "stdafx.h"
#include "Database.h"

bool login(string user_name, string password)
{
	return true;
	if (user_name == "master" && password == "1234")
		return true;
	return false;
}