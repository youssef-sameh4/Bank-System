#pragma once
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iostream>
#include "clsScreen.h"
#include <iomanip>

class clsUpdateUserScreen:protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser& user)
    {
        cout << "\nEnter FirstName: ";
        user.FirstName = clsInputValidate::ReadString();


        cout << "\nEnter LastName: ";
        user.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        user.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        user.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        user.Password = clsInputValidate::ReadString();



        cout << "\nEnter Permissions : ";
        user.Permissions = _ReadPermissions();

    }
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
    static int _ReadPermissions()
    {
        clsUser::enPermissions permemissions;
        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;

        }
        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;


    }
  public:
      static void UpDateUser()
      {
          string UserName = "";
          _DrawScreenHeader("Update Screen");
          cout << "Enter Your Account Number ? ";
          UserName = clsInputValidate::ReadString();
          while (!clsUser::IsUserExist(UserName))
          {
              cout << "\nAccount number is not found, choose another one: ";
              UserName = clsInputValidate::ReadString();

          }
          clsUser User = clsUser::Find(UserName);
          _PrintUser(User);
          cout << "\n\nUpdate Client Info:";
          cout << "\n____________________\n";
          _ReadUserInfo(User);
          clsUser::enSaveResults SaveResult;
          SaveResult = User.Save();
          switch (SaveResult)
          {
          case  clsUser::enSaveResults::svSucceeded:
          {
              cout << "\nAccount Updated Successfully :-)\n";
              _PrintUser(User);
              break;
          }
          case clsUser::enSaveResults::svFaildEmptyObject:
          {
              cout << "\nError account was not saved because it's Empty";
              break;

          }
          }
      }
};

