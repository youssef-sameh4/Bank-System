#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClint.h"
#include "clsInputValidate.h"

#include <iomanip>
class clsUpdateClient:protected clsScreen
{
private:
    static void _ReadClint(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();



        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();

    }

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
   

 static void UpDateClient()
    {
     if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
     {
         return;
     }
        string AccountNumber = "";
        _DrawScreenHeader("Update Screen");
        cout << "Enter Your Account Number ? ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _Print(Client1);
        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";
        _ReadClint(Client1);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client1.Save();
        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _Print(Client1);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        }
    }
};

