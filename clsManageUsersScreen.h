#pragma once
#include <iomanip>
#include "clsInputValidate.h"
#include"clsScreen.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUser.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;
class clsManageUsersScreen:protected clsScreen
{
private:
    enum enManageUsersOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5,eMainMenue = 6
    };
    static short _ReadManageUsersMenueOption() 
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }
    static  void _GoBackToManageUsersMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowManageUsersMenue();
    }
    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowListUsers();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUser::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::DeleteUser();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::UpDateUser();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }



    static void _PerfromManageUsersMenueOption(enManageUsersOptions ManageUsersOptions)
    {
        switch (ManageUsersOptions)
        {
        case enManageUsersOptions::eListClients:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersOptions::eAddNewClient:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersOptions::eDeleteClient:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersOptions::eUpdateClient:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersOptions::eFindClient:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;

        }
        case enManageUsersOptions::eMainMenue:
        {
            break;

        }
        default:
            break;
        }

    }
public:
    static  void ShowManageUsersMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromManageUsersMenueOption((enManageUsersOptions)_ReadManageUsersMenueOption());
    }
};

