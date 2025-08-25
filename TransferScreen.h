#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClint.h"
#include <iomanip>
#include "clsInputValidate.h"
class TransferScreen:protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("Transfer Screen");
        cout << "Please Enter Account Number To Transfer From : ";
        string AccNumber = clsInputValidate::ReadString();
        vector <clsBankClient> vClients = clsBankClient::GetClientList();

        while (!clsBankClient::IsClientExist(AccNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccNumber = clsInputValidate::ReadString();
        }
        clsBankClient Clint1 = clsBankClient::Find(AccNumber);
        _PrintClient(Clint1);
        
        cout << "Please Enter Account Number To Transfer to : ";
        string AccNumber2 = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccNumber = clsInputValidate::ReadString();
        }
        clsBankClient Clint2 = clsBankClient::Find(AccNumber2);

        _PrintClient(Clint2);

        int Amount;
        cout << "\n Enter Transfer Amount: ";
        Amount=clsInputValidate::ReadDblNumber();
        while (Amount > Clint1.AccountBalance)
        {
            cout << "Account Exceeeds The Available Balance, Enter Anther Amount: ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        char Answer;
        cout << "\n Are You Sure [y/n] : ";
        cin >> Answer;
        if (Answer == 'y')
        {
            Clint1.Withdraw(Amount);
            Clint2.Deposit(Amount);
            cout << "Transfer Done..\n";
            clsBankClient::SaveTransferToFile(Clint1, Clint2, Amount);
            _PrintClient(Clint1);
            _PrintClient(Clint2);
        }
        

    }
};

