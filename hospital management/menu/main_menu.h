#include <string>
#include <iostream>
#include "../classes/accounts.h"
using namespace std;

void main_menu(User& user){
    menu_start:
    system("CLS");
    cout << "Welcome to Hospital-Managment system!" << endl;
    cout << "Your name: " << user.getName() << endl;
    cout << "Your lastname: " << user.getLast_name() << endl;
    cout << "Your date of birthd: " << user.getData_of_birth() << endl;
    cout << "Your address: " << user.getAddress() << endl;
    cout << "Type: " << user.getUser_type() << endl;
};