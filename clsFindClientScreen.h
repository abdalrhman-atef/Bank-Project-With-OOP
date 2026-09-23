#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include"clsInputValidate.h"
class clsFindClientScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{

		cout << "\n Client Card ";
		cout << "\n-------------------\n ";
		cout << "\n First Name  :" << Client.FirstName;
		cout << "\n Last Name   :" << Client.LastName;
		cout << "\n Full Name   :" << Client.FullName();
		cout << "\n Email       :" << Client.Email;
		cout << "\n Phone       :" << Client.Phone;
		cout << "\n Acc. Number :" << Client.AccountNumber();
		cout << "\n Password    :" << Client.PinCode;
		cout << "\n Balance     :" << Client.AccountBalance;
		cout << "\n-------------------\n ";
	}
public:
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("\tFind Client Screen");
		string AccountNumber;
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while(!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found, Choose Another One \n";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);;
		if (!Client.IsEmpty())
		{
			cout << "Client Was Found :-)\n";
		}
		else
		{
			cout << "Client Was Not Found :-(\n";
		}
		_PrintClient(Client);
	
	}
};

