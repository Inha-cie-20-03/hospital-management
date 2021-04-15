// Ubaydulla's code start 
// =======================//======================


#include <string>
#include <iostream>
#include "../../classes/accounts.h"
#include "about_admin.h"
#pragma once
using namespace std;

void admin_menu(User& user) {
    int number;
menu:
    system("cls");
    cout << "Welcome to Hospital management system " << user.getName() << " !" << endl;
    cout << "Menu (Choose any option which you want) : " << endl;
    cout << "1 See all booking for a doctors" << endl;
    cout << "2 See all booking for user " << endl;
    cout << "3 Add new user" << endl;
    cout << "4 Add booking for user" << endl;
    cout << "5 About me" << endl;
    cout << "6 Exit" << endl;
    cout << "Enter the command: "; cin >> number;
    switch (number)
    {
    case 1:
        // all_doctor_bookings();
        system("pause");
        goto menu;
        break;
    case 2:
        // all_user_bookings();
        system("pause");
        goto menu;
        break;
    case 3:
        // add_new_user();
        system("pause");
        goto menu;
        break;
    case 4:
        // add_new_user_booking();
        system("pause");
        goto menu;
        break;
    case 5:
        about_admin(user);
        system("pause");
        goto menu;
        break;
    case 6:
        cout << "Good bye, thanks for using our system)" << endl;
        break;
    default:
        cout << "You enter the wrong number, please retry" << endl;
        system("pause");
        goto menu;
        break;
    };

}

// Ubaydulla's code end
// ----------------------------------------