#pragma once
#include <iostream>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tCurrent User : " << CurrentUser.UserName << "\n";
        clsDate CurrentDate=clsDate::GetSystemDate();
        cout << "\t\t\t\t\tDate : " ;  CurrentDate.Print(); cout << "\n";
        
     
    }
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t------------------------------------------------------";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact Your Admin \n";
            cout << "\n\t\t\t\t\t------------------------------------------------------\n";
            return false;
        }
        else
        {
            return true;
        }
    
    }

};

