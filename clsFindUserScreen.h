#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsUser.h"
#include <iomanip>
#include"clsInputValidate.h"

class clsFindUserScreen :protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{

		cout << "\n User Card ";
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
public:
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen");
		string UserName;
		cout << "\nPlease Enter User Name: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User Name Is Not Found, Choose Another One \n";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(UserName);;
		if (!User1.IsEmpty())
		{
			cout << "User Was Found :-)\n";
		}
		else
		{
			cout << "User Was Not Found :-(\n";
		}
		_PrintUser(User1);

	}
};

