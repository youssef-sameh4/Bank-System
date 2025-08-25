#pragma once
#include <iostream>
#include"clsMainScreen.h"
#include"clsScreen.h"
#include"clsUser.h"
#include "clsInputValidate.h"
#include"Global.h"
#include"clsDate.h"
class clsLoginScreen :protected clsScreen
{
private:
	static bool _Login()
	{
		string username, password;
		bool LoginFaild = false;
		short count = 3;
		do
		{
			if (LoginFaild)
			{
				count--;
				cout << "Invlaid UserName/Password!..\n";
				cout << "You Have " << count << " Trials To Login.\n\n";

			}
			if (count == 0)
			{
				cout << "You Are Loked After 3 Faild trials!.";
				return false;
			}
			cout << "Enter UserName ? ";
			username = clsInputValidate::ReadString();
			cout << "Enter Password ? ";
			password = clsInputValidate::ReadString();
			cout << endl;
		  CurrentUser = clsUser::Find(username, password);
			LoginFaild = CurrentUser.IsEmpty();
			
			
		} while (LoginFaild);
		  CurrentUser.RegisterLogIn();
			clsMainScreen::ShowMainMenue();
			return true;

	}
public:
	static bool ShowLogin()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();

	}
};

