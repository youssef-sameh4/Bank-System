#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsBankClint.h"
#include"clsDeposit.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"TransferScreen.h"
#include"clsShowTransferList.h"
class clsTransactionsScreen:protected clsScreen
{
private:
	enum enTransactionMenueOptions
	{
		eDeposit = 1,eWithdraw=2,eTotalBalance=3,eTransfer=4, eTransferLog=5,eMainMenue=6
	};
	static short _ReadTransactionMenueOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _Deposit()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _Withdraw()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTransfer()
	{
		TransferScreen::ShowTransferScreen();
	}

	static void _TotalBalance()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static  void _GoBackToTransactionMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");

		ShowTransactionsMenue();

	}
	static void _showTransferList()
	{
		clsShowTransferList::ShowLoginTransferScreen();
	}
	static void _PerfromTransactionMenueOption(enTransactionMenueOptions TransactionMenueOption)
	{
		switch (TransactionMenueOption)
		{
		case clsTransactionsScreen::eDeposit:
		{
			system("cls");
			_Deposit();
			_GoBackToTransactionMenue();

			break;
		}
		case clsTransactionsScreen::eWithdraw:
		{
			system("cls");

			_Withdraw();
			_GoBackToTransactionMenue();
			break;
		}
		case clsTransactionsScreen::eTotalBalance:
		{
			system("cls");

			_TotalBalance();
			_GoBackToTransactionMenue();

			break;
		}
		case clsTransactionsScreen::eTransfer:
		{
			system("cls");

			_ShowTransfer();
			_GoBackToTransactionMenue();
			break;
		}
		case clsTransactionsScreen::eTransferLog:
		{
			system("cls");

			_showTransferList();
			_GoBackToTransactionMenue();
			break;
		}
		case clsTransactionsScreen::eMainMenue:
		{

			break;
		}
		default:
			break;
		}
	}
public:
	static  void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t\Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromTransactionMenueOption((enTransactionMenueOptions)_ReadTransactionMenueOptions());
	}

};

