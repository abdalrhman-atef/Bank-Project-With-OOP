#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
class clsManageUsersMenu:protected clsScreen
{
private:
    enum enManageUsersOptions {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenu = 6,

    };
    static short _ReadManageUsersMenuOptions()
    {

        cout << setw(37) << left << "" << "Choose What Do You Want To Do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadDblNumberBetween(1, 6);

        return Choice;

    }
    static void _ShowListUsersScreen()
    {

       // cout << "Show All Users Screen Will Be Here\n";
        clsListUsersScreen::ShowUsersList();
    }
    static void _ShowAddNewUsersScreen()
    {
       // cout << "Show Add New Users Screen Will Be Here\n";
        clsAddNewUserScreen::ShowAddNewUserScreen();

    }
    static void _ShowDeleteUsersScreen()
    {
       // cout << "Show Delete Users Screen Will Be Here\n";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }
    static void _ShowUpdateUsersScreen()
    {
       // cout << "Show Update Users Screen Will Be Here\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindUserScreen()
    {
       // cout << "Show Find User Screen Will Be Here\n";
        clsFindUserScreen::ShowFindUserScreen();
    }
    static void _GoBackToManageUsersMenu()
    {
        cout << "press any key to go back to Manage Users menu \n";
        system("pause>0");
        ShowManageUsersScreen();

    }
    static void _PerformManageUsersMenuOption(enManageUsersOptions choice)
    {
        switch (choice)
        {
        case eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        case eAddNewUser:
            system("cls");
            _ShowAddNewUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        case eDeleteUser:
            system("cls");
            _ShowDeleteUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        case eUpdateUser:
            system("cls");
            _ShowUpdateUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        case eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        case eMainMenu:
            
            break;
        default:
            break;
        }


    }

public:

    static void ShowManageUsersScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");
        cout << setw(37) << left << "" <<"===========================================\n";
        cout << setw(37) << left << "" <<"\t\t Manage Users Menu\n";
        cout << setw(37) << left << "" <<"===========================================\n";
        cout << setw(37) << left << "" <<"\t[1] Show Users List.\n";
        cout << setw(37) << left << "" <<"\t[2] Add New User.\n";
        cout << setw(37) << left << "" <<"\t[3] Delete User.\n";
        cout << setw(37) << left << "" <<"\t[4] Update User Info.\n";
        cout << setw(37) << left << "" <<"\t[5] Find User.\n";
        cout << setw(37) << left << "" <<"\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        
        _PerformManageUsersMenuOption((enManageUsersOptions)_ReadManageUsersMenuOptions());
    }
};

