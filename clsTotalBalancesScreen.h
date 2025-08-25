#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClint.h"
#include <iomanip>
#include "clsUtil.h"

class clsTotalBalancesScreen:protected clsScreen
{
private:
   static void _PrintBalanceRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
public:
    static void ShowTotalBalances()
    {
        double toutal = 0;
        vector <clsBankClient> vClients = clsBankClient::GetClientList();
        _DrawScreenHeader("\t   Total Balances Screen");
        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
            toutal = clsBankClient::GetTotalBalance();
        for (clsBankClient Client : vClients)
        {

            _PrintBalanceRecordLine(Client);
            cout << endl;
        }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "The Toutal Balance Is : " << toutal << endl;
        cout << "The Text Number is : " << clsUtil::NumberToText(toutal) << endl;
    }
};

