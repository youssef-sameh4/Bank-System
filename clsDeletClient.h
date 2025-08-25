#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClint.h"
#include "clsInputValidate.h"

#include <iomanip>
class clsDeletClient:protected clsScreen
{
private:
    static  void _Print(clsBankClient& Clint)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Clint.FirstName;
        cout << "\nLastName    : " << Clint.LastName;
        cout << "\nFull Name   : " << Clint.FullName();
        cout << "\nEmail       : " << Clint.Email;
        cout << "\nPhone       : " << Clint.Phone;
        cout << "\nAcc. Number : " << Clint.AccountNumber();
        cout << "\nPassword    : " << Clint.PinCode;
        cout << "\nBalance     : " << Clint.AccountBalance;
        cout << "\n___________________\n";

    }
public:
    static void DeletClint()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        string AccountNumber = "";
        _DrawScreenHeader("Delet Screen");

        cout << "Enter Your Account Number ? ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number Is Already Used, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);
        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Delet())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _Print(Client);

            }
            else
            {
                cout << "\nError Client Was not Deleted\n";

            }
        }
    }
    };

