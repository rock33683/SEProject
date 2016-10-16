#include "stdafx.h"
#include "Database.h"

bool login(string userName, string password)
{
	return true;
	if (userName == "master" && password == "1234")
		return true;
	return false;
}