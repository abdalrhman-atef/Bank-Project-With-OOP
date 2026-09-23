#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsCurrency.h"
#include <iomanip>
#include"clsInputValidate.h"
class clsFindCurrencyScreen :protected clsScreen
{
private:
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
	enum _FindOptions
	{
	ByCode=1,ByCountry=2
	};
	static short _ReadCurrenciesExchangeMenuOptions()
	{

		cout << "Find By:[1] Code Or [2] Country? ";
		short Choice = clsInputValidate::ReadDblNumberBetween(1, 2);

		return Choice;

	}
	static void _FindByCode()
	{
		string CountryCode;
		cout << "\nPlease Enter Country Code: ";
		CountryCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CountryCode))
		{
			cout << "Country Code Is Not Found, Choose Another One \n";
			CountryCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(CountryCode);;
		if (!Currency1.IsEmpty())
		{
			cout << "Currency Was Found :-)\n";
		}
		else
		{
			cout << "Currency Was Not Found :-(\n";
		}
		_PrintCurrency(Currency1);
	
	}
	static void _FindByCountry()
	{
		string CountryName;
		cout << "\nPlease Enter Country Name: ";
		CountryName = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExistByCountry(CountryName))
		{
			cout << "Country Name Is Not Found, Choose Another One \n";
			CountryName = clsInputValidate::ReadString();
		}
		clsCurrency Currency1 = clsCurrency::FindByCountry(CountryName);;
		if (!Currency1.IsEmpty())
		{
			cout << "Currency Was Found :-)\n";
		}
		else
		{
			cout << "Currency Was Not Found :-(\n";
		}
		_PrintCurrency(Currency1);

	}
	static void _PerformCurrenciesExchangeOptions(_FindOptions enFindOptions)
	{
		switch (enFindOptions)
		{
		case clsFindCurrencyScreen::ByCode:
			_FindByCode();
			break;
		case clsFindCurrencyScreen::ByCountry:
			_FindByCountry();
			break;
		default:
			break;
		}
	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");
		
		_PerformCurrenciesExchangeOptions((_FindOptions)_ReadCurrenciesExchangeMenuOptions());
	}
};
//
//#pragma once
//#include <iostream>
//#include "clsScreen.h"
//#include "clsCurrency.h"
//#include "clsInputValidate.h"
//
//class clsFindCurrencyScreen :protected clsScreen
//{
//
//private:
//	static void _PrintCurrency(clsCurrency Currency)
//	{
//		cout << "\nCurrency Card:\n";
//		cout << "_____________________________\n";
//		cout << "\nCountry    : " << Currency.Country();
//		cout << "\nCode       : " << Currency.CurrencyCode();
//		cout << "\nName       : " << Currency.CurrencyName();
//		cout << "\nRate(1$) = : " << Currency.Rate();
//
//		cout << "\n_____________________________\n";
//
//	}
//
//	static void _ShowResults(clsCurrency Currency)
//	{
//		if (!Currency.IsEmpty())
//		{
//			cout << "\nCurrency Found :-)\n";
//			_PrintCurrency(Currency);
//		}
//		else
//		{
//			cout << "\nCurrency Was not Found :-(\n";
//		}
//	}
//
//public:
//
//	static void ShowFindCurrencyScreen()
//	{
//
//		_DrawScreenHeader("\t  Find Currency Screen");
//
//		cout << "\nFind By: [1] Code or [2] Country ? ";
//		short Answer = 1;
//
//		cin >> Answer;
//
//		if (Answer == 1)
//		{
//			string CurrencyCode;
//			cout << "\nPlease Enter CurrencyCode: ";
//			CurrencyCode = clsInputValidate::ReadString();
//			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
//			_ShowResults(Currency);
//		}
//		else
//		{
//			string Country;
//			cout << "\nPlease Enter Country Name: ";
//			Country = clsInputValidate::ReadString();
//			clsCurrency Currency = clsCurrency::FindByCountry(Country);
//			_ShowResults(Currency);
//		}
//
//
//
//
//
//
//	}
//
//};
//
