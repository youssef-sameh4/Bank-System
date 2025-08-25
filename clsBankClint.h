#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include"clsDate.h"
#include"Global.h"
using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1,AddNewMode=3,DeletMode=4 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelet = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#||#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#||#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Client1.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }
    static void _SaveCleintsDataToFile(vector <clsBankClient>& vClients)
    {

        fstream MyFile;
        MyFile.open("Client1.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C._MarkForDelet == false)
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }

            }

            MyFile.close();

        }

    }
    static string _ConverTransferToLine(clsBankClient Clint1,clsBankClient Clint2,double Amount,string Seperator = "#||#")
    {
        string Line = "";
        Line += clsDate::GetSystemDateTimeString() + Seperator;
        Line += Clint1.AccountNumber() + Seperator;
        Line += Clint2.AccountNumber() + Seperator;
        Line += to_string(  Amount )+ Seperator;
        Line += to_string(Clint1.AccountBalance) + Seperator;
        Line += to_string(Clint2.AccountBalance) + Seperator;
        Line += CurrentUser.UserName ;
        return Line;
    }
    struct stLoginTransferRecord;

    static stLoginTransferRecord _ConvertLoginTransferLineToRecord(string Line, string Seperator = "#||#")
    {
        vector<string> vClientData;
        stLoginTransferRecord transfer;

        vClientData = clsString::Split(Line,Seperator);
        transfer.DateTime = vClientData[0];
        transfer.SourceAccountNumber = vClientData[1];
        transfer.DestinationAccountNumber = vClientData[2];
        transfer.Amount =stod( vClientData[3]);
        transfer.srcBalanceAfter = stod(vClientData[4]);
        transfer.destBalanceAfter = stod(vClientData[5]);
        transfer.Username = vClientData[6];

        return transfer;

    }
    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Client1.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    void _AddNew()
    {
        return _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    
public:
   


    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Client1.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Client1.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 , svFaildAccountNumberExists = 2};

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {

            return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }
        case enMode::AddNewMode:
        {
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;

            }
            break;
        }
        
            
        }

        



    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

  static  clsBankClient GetAddNewClient(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

  bool Delet()
  {
      vector<clsBankClient>vClient = _LoadClientsDataFromFile();
      for (clsBankClient C : vClient)
      {
          if (AccountNumber() == _AccountNumber)
          {
              C._MarkForDelet = true;
              break;
          }
      }
      _SaveCleintsDataToFile(vClient);
      *this = _GetEmptyClientObject();
      return true;
  }
  static vector<clsBankClient>GetClientList()
  {
      return _LoadClientsDataFromFile();
  }
  static int GetTotalBalance()
  {
      int toutal = 0;
      vector<clsBankClient>vClients = _LoadClientsDataFromFile();
            for (clsBankClient Client : vClients)
            {

                toutal += Client.AccountBalance;
            }
      return toutal;
  }
  void Deposit(double amount)
  {
      _AccountBalance += amount;
      Save();
  }
  bool Withdraw(double amount)
  {
      if (amount > _AccountBalance)
      {
          return false;
      }
      else
      {
          _AccountBalance -= amount;
          Save();
      }
  }
  static void SaveTransferToFile(clsBankClient Clint1, clsBankClient Clint2, double Amount)
  {
      fstream MyFile;
      MyFile.open("transfer.text", ios::out | ios::app);
      if (MyFile.is_open())
      {
          MyFile << _ConverTransferToLine(Clint1, Clint2,Amount) << endl;
          MyFile.close();
      }
  }
  struct stLoginTransferRecord
  {
      string DateTime;
      string SourceAccountNumber;
      
      string DestinationAccountNumber;
      double Amount;
      double srcBalanceAfter;
      double destBalanceAfter;
      string Username;
      
  };
  static  vector <stLoginTransferRecord> GetLoginTransferList()
  {
      vector <stLoginTransferRecord> vLoginTransferRecord;

      fstream MyFile;
      MyFile.open("transfer.text", ios::in);//read Mode

      if (MyFile.is_open())
      {

          string Line;

          stLoginTransferRecord LoginTransferList;

          while (getline(MyFile, Line))
          {

              LoginTransferList = _ConvertLoginTransferLineToRecord(Line);

              vLoginTransferRecord.push_back(LoginTransferList);

          }

          MyFile.close();

      }

      return vLoginTransferRecord;

  }

};
