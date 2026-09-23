#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsCurrency.h"
#include <iomanip>

class clsCurrenciesListScreen:protected clsScreen
{

private:
    static void PrintCurrenciesRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(40) << left << Currency.Country();
        cout << "| " << setw(6) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(15) << left << Currency.Rate();
      
    }

public:


    static void ShowCurrenciesList()
    {


        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Country";
        cout << "| " << left << setw(6) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(15) << "Rate(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vCurrencies)
            {

                PrintCurrenciesRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;

    }
};

