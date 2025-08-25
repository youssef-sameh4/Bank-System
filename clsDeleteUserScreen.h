#pragma once
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
class clsDeleteUserScreen:protected clsScreen
{
private:
    static  void _PrintUser(clsUser& user)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nUser Name   : " << user.UserName;
        cout << "\nFull Name    : " << user.FullName();
        cout << "\nEmail       : " << user.Email;
        cout << "\nPhone       : " << user.Phone;
        cout << "\nPassword : " << user.Password;
        cout << "\Permissions    : " << user.Permissions;
        cout << "\n___________________\n";

    }

public:
    static void DeleteUser()
    {
        _DrawScreenHeader("Delete Screen");
        cout << "Enter UserName ? ";
        string UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);
        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (User.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintUser(User);

            }
            else
            {
                cout << "\nError Client Was not Deleted\n";

            }
        }
    }
};

