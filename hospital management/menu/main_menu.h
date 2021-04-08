#include <string>
#include <iostream>
//#include "../classes/accounts.h"
using namespace std;

void user_menu() {
    int number;
menu: 
    system("cls");
    cout << "Welcome to Hospital management system!" << endl;
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

void main_menu(){
    int type = 0;
    system("CLS");
    //cout << "Welcome to Hospital-Managment system!" << endl;
    //cout << "Your name: " << user.getName() << endl;
    //cout << "Your lastname: " << user.getLast_name() << endl;
    //cout << "Your date of birthd: " << user.getData_of_birth() << endl;
    //cout << "Your address: " << user.getAddress() << endl;
    //cout << "Type: " << user.getUser_type() << endl;
    if (type == 0) {
        user_menu();
    }
};