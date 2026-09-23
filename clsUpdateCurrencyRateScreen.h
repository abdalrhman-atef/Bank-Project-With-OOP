#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsCurrency.h"
#include <iomanip>
#include"clsInputValidate.h"
class clsUpdateCurrencyRateScreen :protected clsScreen
{
	static double _ReadCurrencyRate()
	{
		cout << "\nEnter New Rate: ";
		double Rate = 0;
		Rate= clsInputValidate::ReadDblNumber();
	

		return Rate;


	}
	static void _PrintCurrency(clsCurrency Currency)
	{

		cout << "\n Currency Card ";
		cout << "\n-------------------\n ";
		cout << "\n Country  :" << Currency.Country();
		cout << "\n Code     :" << Currency.CurrencyCode();
		cout << "\n Name     :" << Currency.CurrencyName();
		cout << "\n Rate     :" << Currency.Rate();
		cout << "\n-------------------\n ";
	}
	
public:
	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("\tUpdate Rate Screen");
		string CurrencyCode = "";
		cout << "Please Enter Country Code : ";
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency Code Is Not Found, Choose Another One: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency1);
		cout << "\n are you sure to update this Currency Rate? \n";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate Rate Info ";
			cout << "\n----------------------\n";
			Currency1.UpdateRate(_ReadCurrencyRate());
			cout << "Currency Rate Updated Successfully :-) \n";
			_PrintCurrency(Currency1);
		}


	}




};

