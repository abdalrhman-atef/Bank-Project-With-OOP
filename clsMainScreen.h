#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersMenu.h"
#include"clsLoginScreen.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeScreen.h"
using namespace std;

class clsMainScreen :protected clsScreen
{
private:
   static short _ReadMainMenuOption()
    {
       
        cout << setw(37) << left << "" << "Choose What Do You Want To Do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadDblNumberBetween(1, 10);
        
        return Choice;

    }
   static void _ShowAllClientsScreen()
    {
       clsClientListScreen::ShowClientsList();
    }
   static void _ShowAddNewClientsScreen()
    {
       clsAddNewClientScreen::ShowAddNewClientScreen();
    }
   static void _ShowDeleteClientScreen()
    {
       clsDeleteClientScreen::ShowDeleteClientScreen();
    }
   static void _ShowUpdateClientScreen()
    {
       clsUpdateClientScreen::ShowUpdateClientScreen();
    }
   static void _ShowFindClientScreen()
    {
       // cout << "Find Client Screen Will Be Here \n";
       clsFindClientScreen::ShowFindClientScreen();
    }
   static void _ShowTransactionsScreen()
    {
       // cout << "Transactions Screen Will Be Here \n";
       clsTransactionsScreen::ShowTransactionsMenuScreen();
    }
   static void _ShowManageUsersScreen()
    {
       clsManageUsersMenu::ShowManageUsersScreen();
    }
   static void _ShowCurrencyExchangeScreen()
   {
      // cout << "Currency Exchange Will Be Here \n ";
       clsCurrencyExchangeScreen::ShowCurrenciesExchangeMenuScreen();
   }
   static void _ShowLoginRegisterScreen()
   {
       clsLoginRegisterScreen::ShowLoginRegisterScreen();
      // cout << "Login Screen Will Be Here \n";
   }
   //static void _ShowEndScreen()
   // {
   //     cout << "End Screen Will Be Here \n";
   // }
   static void _LogOut()
   {
       CurrentUser = clsUser::Find("", "");
       // then it will back to main function.
       
   }
   static void _GoBackToMainMenu()
    {
        cout << "press any key to go back to main menu \n";
        system("pause>0");
        ShowMainMenu();


    }
   enum enMainMenueOptions {
      eListClients = 1,
      eAddNewClient = 2,
      eDeleteClient = 3,
      eUpdateClient = 4,
      eFindClient = 5,
      eShowTransactionsMenu = 6,
      eManageUsers = 7,
      eLoginRegisterScreen = 8,
      eCurrencyExchangeScreen=9,
      eExit=10
    };
   static void _PerformMainMenuOptions(enMainMenueOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case clsMainScreen::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eShowTransactionsMenu:
            system("cls");
            _ShowTransactionsScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eManageUsers:
            system("cls");
            _ShowManageUsersScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eLoginRegisterScreen:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eCurrencyExchangeScreen:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenu();
            break;
        case clsMainScreen::eExit:
            system("cls");
            _LogOut();
           
            break;
        default:
            break;
        }
    }
public:
   static void ShowMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\t Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register Screen.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Exist.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformMainMenuOptions((enMainMenueOptions)_ReadMainMenuOption());
    }

};

