#pragma once
#include<iostream>
#include"clsDate.h"
#include"Global.h"
using namespace std;
class clsDateLogin
{
public:
	static void PrintDateLogin()
	{
		
		cout << "\t\t\t\t\t  User : " << CurrentUser.UserName<<endl;
		clsDate date;
		cout << "\n\t\t\t\t\t Date: ";
		date.Print();
		cout << "\n";
	}
};

