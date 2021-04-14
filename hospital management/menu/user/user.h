// Ubaydulla's code start 
// =======================//======================

#include <string>
#include <iostream>
#include "../../classes/accounts.h"
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
        // book_doctor();
        system("pause");
        goto menu;
        break;
    case 2:
        // view_active_bookings();
        system("pause");
        goto menu;
        break;
    case 3:
        // cencel_booking();
        system("pause");
        goto menu;
        break;
    case 4:
	// abou_me();
        // Olimjon's code starts
        cout << "\n\nFirst Name: " << user.getName() << "\n";
        cout << "Last Name: " << user.getLast_name() << "\n";
        cout << "Date of birth(DDMMYY): " << user.getData_of_birth() << "\n";
        cout << "Address: " << user.getAddress() << "\n\n\n";
        // Olimjon's code ends
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
