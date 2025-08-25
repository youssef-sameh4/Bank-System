#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClint.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsFindClient:protected clsScreen
{
private:
    static  void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
public:
    static  void ShowFindClientList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        vector <clsBankClient> vClients = clsBankClient::GetClientList();

        string Title = "\t  Find List Screen";

        _DrawScreenHeader(Title);
        string AccountNumber;
        cout << "Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();

        }      
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
        {
            
            for (clsBankClient Client : vClients)
            {
                if (Client.AccountNumber() == AccountNumber)

                {
                    _PrintClientRecordLine(Client);
                    cout << endl;
                }
            }

            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
        }
    }

};

