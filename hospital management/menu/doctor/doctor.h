// Ubaydulla's code start 
// =======================//======================


#include <string>
#include <iostream>
#include "../../classes/accounts.h"
#include "about_doctor.h"
#pragma once
using namespace std;

void doctor_menu(User& user) {
    int number;
menu:
    system("cls");
    cout << "Welcome to Hospital management system " << user.getName() << " !" << endl;
    cout << "Menu (Choose any option which you want) : " << endl;
    cout << "1 See all bookings" << endl;
    cout << "2 View bookings for today" << endl;
    cout << "3 About me" << endl;
    cout << "4 Exit" << endl;
    cout << "Enter the command: "; cin >> number;
    switch (number)
    {
    case 1:
        // all_bookings();
        system("pause");
        goto menu;
        break;
    case 2:
        // bookings_for_today();
        system("pause");
        goto menu;
        break;
    case 3:
        about_doctor(user);
        system("pause");
        goto menu;
        break;
    case 4:
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