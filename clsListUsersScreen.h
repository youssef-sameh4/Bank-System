#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsUser.h"
#include <iomanip>
#include<vector>
class clsListUsersScreen:protected clsScreen
{
private:
    static  void _PrintUserRecordLine(clsUser user)
    {
        cout << "| " << setw(15) << left << user.UserName;

        cout << "| " << setw(20) << left << user.FullName();
        cout << "| " << setw(12) << left << user.Phone;
        cout << "| " << setw(20) << left << user.Email;
        cout << "| " << setw(10) << left << user.Password;
        cout << "| " << setw(12) << left << user.Permissions;

    }
public:
    static void ShowListUsers()
    {
        vector< clsUser>vUser;
        vUser = clsUser::GetUsersList();
        string Titel = "List Users Screen";
        int SubTital = vUser.size();
        _DrawScreenHeader(Titel, to_string(SubTital));
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUser.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";


        for (clsUser U : vUser)
        {
            _PrintUserRecordLine(U);
            cout << endl;
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

    }
    
};

