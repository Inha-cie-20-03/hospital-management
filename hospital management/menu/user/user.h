// Ubaydulla's code start 
// =======================//======================

#include <string>
#include <iostream>
#include "../../classes/accounts.h"
#include "about_me.h"
#include "active_bookings.h"
#include "book.h"
#include "cancel_booking.h"
#pragma once
using namespace std;


void user_menu(User &user){
    int number;
menu:
    system("cls");
    cout << "Welcome to Hospital management system "<< user.getName() << " !" << endl;
    cout << "Menu (Choose any option which you want) : " << endl;
    cout << "1 Book doctor" << endl;
    cout << "2 View active bookings" << endl;
    cout << "3 Cencel booking" << endl;
    cout << "4 About me" << endl;
    cout << "5 Exit" << endl;
    cout << "Enter the command: "; cin >> number;
    switch (number)
    {
    case 1:
        book_doctor(user);
        system("pause");
        goto menu;
        break;
    case 2:
        active_bookings(user);
        system("pause");
        goto menu;
        break;
    case 3:
        cancel_booking(user);
        system("pause");
        goto menu;
        break;
    case 4:
        about_user(user);
        system("pause");
        goto menu;
        break;
    case 5:
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
