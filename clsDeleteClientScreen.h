#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include"clsInputValidate.h"
class clsDeleteClientScreen:protected clsScreen
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
    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        _DrawScreenHeader("\tDelete Client Screen");
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }

};

