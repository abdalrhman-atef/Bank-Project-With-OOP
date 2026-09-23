#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsDepositScreen:protected clsScreen
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
    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "Please Enter Account Number? ";
        cin >> AccountNumber;
        return AccountNumber;
    }
  
public:

   static void ShowDepositClientScreen()
    {
        _DrawScreenHeader("\t  Deposit Screen");
        string AccountNumber = _ReadAccountNumber();
        while(!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Client With [" << AccountNumber << "] Is Not Found, Choose Another One \n";
            string AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
        short Amount = 0;
        cout << "how many deposit amount? ";
        Amount = clsInputValidate::ReadDblNumber();
        char Answer = 'n';
        cout << "Are you sure you want to perform this transaction (Y/N)? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Client1.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\n New Balance Is " << Client1.AccountBalance<<endl;
           
        }
        else
        {
            cout << "Operation Was Cancelled\n";
        }

    }

};

