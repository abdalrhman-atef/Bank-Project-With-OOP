#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsUser.h"
#include <iomanip>
#include"clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter User Name: ";
		User.UserName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone Number: ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissionsToSet();




	}
	static void _PrintUser(clsUser User)
	{

		cout << "\n Client Card ";
		cout << "\n-------------------\n ";
		cout << "\n First Name  :" << User.FirstName;
		cout << "\n Last Name   :" << User.LastName;
		cout << "\n Full Name   :" << User.FullName();
		cout << "\n Email       :" << User.Email;
		cout << "\n Phone       :" << User.Phone;
		cout << "\n User Name   :" << User.UserName;
		cout << "\n Password    :" << User.Password;
		cout << "\n Permissions :" << User.Permissions;
		cout << "\n-------------------\n ";
	}
	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';
		cout << "Do You Want To Give Full Access? Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}
		cout << "Do You Want To Give Access To: \n";
		cout << "\n Show Client List? Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}
		cout << "Do You Want To Give Access To: \n";
		cout << "\n Add New Client? Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}
		cout << "Do You Want To Give Access To: \n";
		cout << "\n Delete Client? Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}
		cout << "Do You Want To Give Access To: \n";
		cout << "\n Update Client? Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}
		cout << "Do You Want To Give Access To: \n";
		cout << "\n Find Client ? Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}
		cout << "Do You Want To Give Access To: \n";
		cout << "\n Transactions? Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}
		cout << "Do You Want To Give Access To: \n";
		cout << "\n Manage Users? Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}
		cout << "Do You Want To Give Access To: \n";
		cout << "\n Login Register? Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pShowLogInRegister;
		}

		return Permissions;


	}
public:
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\tUpdate User Screen");
		string UserName = "";
		cout << "Please Enter User Name : ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User Name Is Not Found, Choose Another One: ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);
		cout << "\n are you sure to update this user? \n";
		char Answer = 'n';
		cin >> Answer;
		if (Answer=='y'||Answer=='Y')
		{

			cout << "\n\nUpdate User Info ";
			cout << "\n----------------------\n";
			_ReadUserInfo(User1);
			clsUser::enSaveResults SaveResult;
			SaveResult = User1.Save();
			switch (SaveResult)
			{

			case clsUser::svFaildEmptyObject:
				cout << "Error Account Was Not Saved Because Its Empty \n";
				break;
			case clsUser::svSucceeded:

				cout << "\nUser Updated Successfully:-)\n";
				_PrintUser(User1);
				break;
			default:
				break;
			}

		}
		

	}

};

