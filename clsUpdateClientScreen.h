#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include"clsInputValidate.h"
class clsUpdateClientScreen:protected clsScreen
{
private:
 static	void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone Number: ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Pin Code: ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();




	}
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
 static void ShowUpdateClientScreen()
	{
	 if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
	 {
		 return;
	 }
	    _DrawScreenHeader("\tUpdate Client Screen");
		string AccountNumber = "";
		cout << "Please Enter Client Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found, Choose Another One: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		cout << "\n are you sure to update this user? \n";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Client Info ";
			cout << "\n----------------------\n";
			_ReadClientInfo(Client1);
			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client1.Save();
			switch (SaveResult)
			{
			case clsBankClient::svFaildEmptyObjict:
				cout << "Error Account Was Not Saved Because Its Empty \n";
				break;
			case clsBankClient::svSucceeded:

				cout << "\nAccount Updated Successfully:-)\n";
				_PrintClient(Client1);
				break;
			default:
				break;
			}
		
		}
		

	}


};

