#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsUser.h"
#include <iomanip>
#include"clsInputValidate.h"

class clsDeleteUserScreen :protected clsScreen
{
private:
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
public:
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");
        string UserName = "";

        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";

                _PrintUser(User);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }


};

