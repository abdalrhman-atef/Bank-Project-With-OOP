#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogRegisterScreen.h"
class clsTransactionsScreen :protected clsScreen
{
private:
    enum EtransactionsOptions
    {
        eDeposit = 1, ewithdraw = 2, eTotalBalance = 3,eTransfer=4 ,eShowTransferLog = 5,eMainMenu = 6
    };
    static short _ReadTransactionsMenuOption()
    {

        cout << setw(37) << left << "" << "Choose What Do You Want To Do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadDblNumberBetween(1, 6);

        return Choice;

    }
    static void _ShowDepositScreen()
    {
       // cout << "Deposit Screen Will Be Here \n";
        clsDepositScreen::ShowDepositClientScreen();
    }
    static void _ShowWithdrawScreen()
    {
      //  cout << "Withdraw Screen Will Be Here \n";
        clsWithdrawScreen::ShowWithdrawClientScreen();
    }
    static void _ShowTotalBalancesScreen()
    {
       // cout << "Total Balances Screen Will Be Here \n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }
    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
      
    }
    static void _ShowTransferLog()
    {
        clsTransferLogRegisterScreen::ShowTransferLogScreen();
    
    
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << "press any key to go back to transactions menu \n";
        system("pause>0");
        ShowTransactionsMenuScreen();


    }
   
    static void PerformTransactionsOptions(EtransactionsOptions EtransactionsOptions)
    {
        switch (EtransactionsOptions)
        {
        case eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        case ewithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;
        case eTotalBalance:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;
        case eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
            break;
        case eShowTransferLog:
            system("cls");
            _ShowTransferLog();
            _GoBackToTransactionsMenu();
            break;
        case eMainMenu:
           // Do Nothing Here The Main Screen Will Handle it :-)
            break;
        default:
            break;
        }
    }


public:
    static void ShowTransactionsMenuScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\tTransactions Menu Screen");
        cout << setw(37) << left << "" <<"===========================================\n";
        cout << setw(37) << left << "" <<"\t\tTransactions Menu Screen\n";
        cout << setw(37) << left << "" <<"===========================================\n";
        cout << setw(37) << left << "" <<"\t[1] Deposit.\n";
        cout << setw(37) << left << "" <<"\t[2] Withdraw.\n";
        cout << setw(37) << left << "" <<"\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" <<"\t[5] Transfer Log Screen.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        PerformTransactionsOptions((EtransactionsOptions)_ReadTransactionsMenuOption());
    }

};

