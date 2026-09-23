#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsTransferScreen:protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {

        cout << "\n Client Card ";
        cout << "\n-------------------\n ";
        cout << "\n Full Name   :" << Client.FullName();
        cout << "\n Acc. Number :" << Client.AccountNumber();
        cout << "\n Balance     :" << Client.AccountBalance;
        cout << "\n-------------------\n ";
    }
    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber = "";
        cout << Message;
        cin >> AccountNumber;
        return AccountNumber;
    }

public:
   // static void ShowTransferScreen()
   // {
   //     _DrawScreenHeader("\t Transfer Screen");
   //     //-------------------------------------------------------------------------------------------
   //     string AccountNumberFrom = _ReadAccountNumber("Please Enter Account Number To Transfer From. \n");
   //     while (!clsBankClient::IsClientExist(AccountNumberFrom))
   //     {
   //         cout << "Client With [" << AccountNumberFrom << "] Is Not Found, Choose Another One \n";
   //         AccountNumberFrom = _ReadAccountNumber("Please Enter Account Number To Transfer From. \n");
   //     }
   //     clsBankClient Client1 = clsBankClient::Find(AccountNumberFrom);
   //     _PrintClient(Client1);
   //     //-------------------------------------------------------------------------------------------
   //     string AccountNumberTo = _ReadAccountNumber("Please Enter Account Number To Transfer To. \n");
   //     
   //     while (!clsBankClient::IsClientExist(AccountNumberTo))
   //     {
   //         cout << "Client With [" << AccountNumberTo << "] Is Not Found, Choose Another One \n";
   //         AccountNumberTo = _ReadAccountNumber("Please Enter Account Number To Transfer To. \n");
   //     }
   //     clsBankClient Client2 = clsBankClient::Find(AccountNumberTo);
   //     _PrintClient(Client2);
   //     //-------------------------------------------------------------------------------------------
   //     double Amount = 0;
   //     cout << "Enter Transfer Amount? ";
   //     Amount = clsInputValidate::ReadDblNumber();
   //     //-------------------------------------------------------------------------------------------

   //     char Answer = 'n';
   //     cout << "Are you sure you want to perform this transaction (Y/N)? ";
   //     cin >> Answer;
   //     if (Answer == 'y' || Answer == 'Y')
   //     {
   //         
   //         if (Client1.Withdraw(Amount))
   //         {
   //             cout << "\nAmount Transfer Successfully.\n";
   //             cout << "\n New Balance For Client ["<<Client1.FullName() <<"] is: " << Client1.AccountBalance << endl;
   //             Client2.Deposit(Amount);
   //             cout << "\n New Balance For Client [" << Client2.FullName() << "] is: " << Client2.AccountBalance << endl;
   //         }
   //         else
   //         {
   //             cout << "Cannot Withdraw, Insufficient Balance.\n";
   //             cout << "\nAmount To Withdraw Is: " << Amount;
   //             cout << "\n Client Balance Is " << Client1.AccountBalance << endl;

   //         }

   //     }
   //     else
   //     {
   //         cout << "Operation Was Canceled\n";
   //     }

   // }
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t Transfer Screen");
        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number To Transfer From. \n"));
        _PrintClient(SourceClient);
        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Please Enter Account Number To Transfer To. \n"));
        _PrintClient(DestinationClient);
        double Amount = 0;
        cout << "Enter Transfer Amount? ";
        Amount = clsInputValidate::ReadDblNumber();
        char Answer = 'n';
        cout << "Are you sure you want to perform this transaction (Y/N)? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            if (SourceClient.Transfer(Amount,DestinationClient))
            {
                cout << "\n Transfer Done Successfully\n";

            }
            else
            {
                cout << "\nTransfer Faild \n";

            }
            _PrintClient(SourceClient);
            _PrintClient(DestinationClient);

        
        
        }
    }

};

