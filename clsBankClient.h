#pragma once
#include<iostream>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>
using namespace std;
class clsBankClient : public clsPerson
{
private:
	//----------------------------------------------
	enum enMode { EmptyMod = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double  _AccountBalance;
	bool _MarkedForDelete = false;
	//----------------------------------------------
	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
	{
		vector<string>vClientData;
		vClientData = clsString::Split(Line, Separator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));

	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMod, "", "", "", "", "", "", 0);;

	}
	static string _ConvertClientObjectToOneLine(clsBankClient Client, string Separator = "#//#")
	{



		string stClientRecord = "";
		stClientRecord += Client.FirstName + Separator;
		stClientRecord += Client.LastName + Separator;
		stClientRecord += Client.Email + Separator;
		stClientRecord += Client.Phone + Separator;
		stClientRecord += Client.AccountNumber() + Separator;
		stClientRecord += Client.PinCode + Separator;
		stClientRecord += to_string(Client.AccountBalance) + Separator;

		return stClientRecord;
	}

	static vector<clsBankClient> _LoadClientDataFromFile()
	{
		vector<clsBankClient>vClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string line;

			while (getline(MyFile, line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);

				vClient.push_back(client);


			}


			MyFile.close();

		}

		return vClient;

	}


	static void _SaveClientDataToFile(vector<clsBankClient>& vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient& C : vClients)
			{
				if (C._MarkedForDelete == false)
				{
					
					DataLine = _ConvertClientObjectToOneLine(C);
					MyFile << DataLine << endl;

				}


			}

			MyFile.close();
		}


	}
	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}

	}
	void _Update()
	{
		vector<clsBankClient>_vClients;
		_vClients = _LoadClientDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToOneLine(*this));

	}
	struct stTransferLogRecord;
	
	string _PrepareTransferLogInRecord(clsBankClient DestinationClient,double Amount,string UserName,string Separator = "#//#" )
	{

		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Separator;
		TransferLogRecord += AccountNumber() + Separator;
		TransferLogRecord += DestinationClient.AccountNumber() + Separator;
		TransferLogRecord += to_string(Amount) + Separator;
		TransferLogRecord += to_string(AccountBalance) + Separator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Separator;
		TransferLogRecord += UserName + Separator;


		
		return TransferLogRecord;
	}

	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Separator = "#//#")
	{
		stTransferLogRecord TransferLogRecord;
		vector<string>vTransferLogRecord = clsString::Split(Line, Separator);
		TransferLogRecord.Time = vTransferLogRecord[0];
		TransferLogRecord.SourceClient = vTransferLogRecord[1];
		TransferLogRecord.DestinationClient = vTransferLogRecord[2];
		TransferLogRecord.Amount = stoi(vTransferLogRecord[3]);
		TransferLogRecord.SourceClientBalance = stoi(vTransferLogRecord[4]);
		TransferLogRecord.DestinationClientBalance = stoi(vTransferLogRecord[5]);
		TransferLogRecord.UserName= vTransferLogRecord[6];

		return TransferLogRecord;


	}
	void _RegisterTransferLog(clsBankClient DestinationClient, double Amount,string UserName)
	{

		string stDataLine = _PrepareTransferLogInRecord(DestinationClient, Amount,UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;


	}
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMod);
	}
	//------------------------- Property Set And Get -----------------------------
	string AccountNumber()
	{
		return _AccountNumber;
	}
	//-----------------------------------------------------------------------
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	_declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	//-----------------------------------------------------------------------
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	_declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;
	//-----------------------------------------------------------------------
	/*void Print()
	{
	**************NO UI Related Code Inside Object**************
		cout << "\n Client Card ";
		cout << "\n-------------------\n ";
		cout << "\n First Name  :" << FirstName;
		cout << "\n Last Name   :" << LastName;
		cout << "\n Full Name   :" << FullName();
		cout << "\n Email       :" << Email;
		cout << "\n Phone       :" << Phone;
		cout << "\n Acc. Number :" << _AccountNumber;
		cout << "\n Password    :" << _PinCode;
		cout << "\n Balance     :" << _AccountBalance;
		cout << "\n-------------------\n ";
	}*/
	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			
			}
			MyFile.close();
		}
		

			return _GetEmptyClientObject();
	
		

	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector<clsBankClient> vClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClient.push_back(Client);

			}
			MyFile.close();
		}
		return _GetEmptyClientObject();

	}
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());

	}
	enum enSaveResults { svFaildEmptyObjict = 0, svSucceeded = 1, svFaildAccountNumberExist = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMod:
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObjict;
			}
			break;
		case clsBankClient::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
			break;
		case clsBankClient::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExist;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		default:
			break;
		}

	}
	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{

		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	bool Delete()
	{
		vector<clsBankClient>_vClients;
		_vClients = _LoadClientDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}

		}
		_SaveClientDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;



	}
	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}
	static double GetTotalBalances()
	{
		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
		double TotalBalances = 0;
		for(clsBankClient Clients: vClients)
		{
			TotalBalances += Clients.AccountBalance;
		
		}
		return TotalBalances;
	}
	 void Deposit(double Amount)
	{
		 _AccountBalance += Amount;
		 Save();
	}
	 bool Withdraw(double Amount)
	 {
		/* while(Amount > _AccountBalance)
		 {
			 cout << "Cannot Withdraw, Insufficient Balance.\n";
			 cout << "\nAmount To Withdraw Is: " << Amount;
			 cout << "\n Client Balance Is " << AccountBalance << endl;
			 cout << "Enter Amount? ";
			 Amount = clsInputValidate::ReadDblNumber();

		 
		 }*/
		 if (Amount > _AccountBalance)
		 {
			 return false;
		 }
		 if (Amount < _AccountBalance)
		 {
			 _AccountBalance -= Amount;
			 Save();

			 return true;
		 }

		
		 
	 }
	
	 struct stTransferLogRecord
	 {
		 string SourceClient;
		 string DestinationClient;
		 double Amount;
		 string Time;
		 double SourceClientBalance;
		 double DestinationClientBalance;
		 string UserName;

	 };

	 bool Transfer(float Amount, clsBankClient& DestinationClient)
	 {
		 if (Amount>AccountBalance)
		 {
			 return false;
		 }
		 Withdraw(Amount);
		 DestinationClient.Deposit(Amount);
		 _RegisterTransferLog(DestinationClient,Amount,CurrentUser.UserName);
		 return true;
	 }
	  

	 static vector<stTransferLogRecord>GetTransferLogList()
	 {
		 vector<stTransferLogRecord>vTransferLogRecord;
		 fstream MyFile;
		 MyFile.open("TransferLog.txt", ios::in);
		 if (MyFile.is_open())
		 {
			 string Line;
			 stTransferLogRecord TransferLogRecord;
			 while (getline(MyFile, Line))
			 {
				 TransferLogRecord = _ConvertTransferLogLineToRecord(Line);
				 vTransferLogRecord.push_back(TransferLogRecord);
			 }
			 MyFile.close();
		 }
		 return vTransferLogRecord;
	 }

};

