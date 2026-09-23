#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen :protected clsScreen
{
private:
    enum eCurrencyExchangeOptions
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculater = 4, eMainMenu = 5
    };
    static short _ReadCurrenciesExchangeMenuOptions()
    {

        cout << setw(37) << left << "" << "Choose What Do You Want To Do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadDblNumberBetween(1, 5);

        return Choice;

    }
    static void _ShowListCurrenciesScreen()
    {
       // cout << "List Currencies Screen Will Be Here \n";
        clsCurrenciesListScreen::ShowCurrenciesList();
    }
    static void _ShowFindCurrencyScreen()
    {
       // cout << "Find Currencies Screen Will Be Here \n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen()
    {
        //cout << "Update Rate Screen Will Be Here \n";
        clsUpdateCurrencyRateScreen::ShowUpdateRateScreen();
    }
    static void _ShowCurrenciesCalculatorScreen()
    {
       // cout << "Currencies Calculator Screen Will Be Here \n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculateScreen();
    }

    static void _GoBackToCurrencyExchangeScreen()
    {
        cout << "press any key to go back to Currency Exchange menu \n";
        system("pause>0");
        ShowCurrenciesExchangeMenuScreen();

    }
    static void _PerformCurrenciesExchangeOptions(eCurrencyExchangeOptions enCurrencyExchangeOptions)
    {
        switch (enCurrencyExchangeOptions)
        {
        case eListCurrencies:
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        case eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        case eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        case eCurrencyCalculater:
            system("cls");
            _ShowCurrenciesCalculatorScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        case eMainMenu:
            // Do Nothing Here The Main Screen Will Handle it :-)
            break;
        default:
            break;
        }
    }
public:
    static void ShowCurrenciesExchangeMenuScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\Currency Exchange Menu Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformCurrenciesExchangeOptions((eCurrencyExchangeOptions)_ReadCurrenciesExchangeMenuOptions());
    }

};

