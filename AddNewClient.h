#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClint.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsUser.h"
class AddNewClient:protected clsScreen
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
 static  void _Print(clsBankClient &Clint)
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
    string Title = "\t  Client List Screen";
   static void AddNewClint()
    {
       if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
       {
           return;
       }
      

       
        string AccountNumber = "";
        cout << "Enter Your Account Number ? ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number Is Already Used, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }
        clsBankClient Client = clsBankClient::GetAddNewClient(AccountNumber);
        _ReadClint(Client);
        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client.Save();
        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _Print(Client);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }


    }
};

