#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsBankClient.h"
#include <iomanip>
#include"clsInputValidate.h"

class clsTransferLogRegisterScreen :protected clsScreen
{
private:

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferInfo)
    {
        cout << "| " << setw(30) << left << TransferInfo.Time;
        cout << "| " << setw(12) << left << TransferInfo.Amount;
        cout << "| " << setw(15) << left << TransferInfo.SourceClient;
        cout << "| " << setw(15) << left << TransferInfo.DestinationClient;
        cout << "| " << setw(17) << left << TransferInfo.SourceClientBalance;
        cout << "| " << setw(17) << left << TransferInfo.DestinationClientBalance;
        cout << "| " << setw(12) << left << TransferInfo.UserName;
       

    }

public:


    static void ShowTransferLogScreen()
    {
        

        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "Transfer Log Register Screen";
        
        _DrawScreenHeader(Title);


        cout << "\n______________________________________________________________________";
        cout << "________________________________________________________\n" << endl;

        cout << "| " << left << setw(30) << "Data / Time";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(15) << "s.Acct";
        cout << "| " << left << setw(15) << "d.Acct";
        cout << "| " << left << setw(17) << "s.Acct Balance";
        cout << "| " << left << setw(17) << "d.Acct Balance";
        cout << "| " << left << setw(15) << "User";
        cout << "\n_______________________________________________________";
        cout << "________________________________________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Information For This Transfer Operation Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "________________________________________________________________________\n" << endl;

    }



};

