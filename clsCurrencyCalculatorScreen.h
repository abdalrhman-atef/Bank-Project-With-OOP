#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsCurrency.h"
#include <iomanip>
#include"clsInputValidate.h"
class clsCurrencyCalculatorScreen :protected clsScreen
{
private:
	static double _ReadAmount()
	{
		cout << "\nEnter Rate Do You Want To Change: ";
		double Rate = 0;
		Rate = clsInputValidate::ReadDblNumber();


		return Rate;


	}
	static void _PrintCurrencyCard(clsCurrency Currency,string Title)
	{

		cout << "\n"<< Title<<endl;
		cout << "\n-------------------\n ";
		cout << "\n Country  :" << Currency.Country();
		cout << "\n Code     :" << Currency.CurrencyCode();
		cout << "\n Name     :" << Currency.CurrencyName();
		cout << "\n Rate     :" << Currency.Rate();
		cout << "\n-------------------\n ";
	}
	static void _PrintCalculationResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		_PrintCurrencyCard(CurrencyFrom, "Convert From: ");
		float AmountInUsd = CurrencyFrom.ConvertToUSD(Amount);
		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUsd << " Usd\n";
		if (CurrencyTo.CurrencyCode()=="USD")
		{
			return;
		}
		cout << "\nConverting From Usd To :\n";
		_PrintCurrencyCard(CurrencyTo, "To: ");
		float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInCurrencyTo << CurrencyTo.CurrencyCode()<<endl;
	}
	static clsCurrency _GetCurrency(string message)
	{
		string CurrencyCode;
		cout << message << endl;
		CurrencyCode = clsInputValidate::ReadString();
		while(!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Is Not Found Choose Another One: ";
			CurrencyCode = clsInputValidate::ReadString();
		
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

public:
	static void ShowCurrencyCalculateScreen()
	{
		char Continue = 'y';
		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\tCalculate Currency Screen");
			clsCurrency CurrencyFrom = _GetCurrency("enter currency 1 code: ");
			clsCurrency CurrencyTo = _GetCurrency("enter currency 2 code: ");
			float Amount = _ReadAmount();
			_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);
			cout << "do you want to perform another calculation? y/n ?";
			cin >> Continue;

		}
	
	}



};

