// Ubaydulla's code start 
// =======================//======================

#include <string>
#include <iostream>
#include "user/user.h"
//#include "../classes/accounts.h"
using namespace std;


void main_menu(string& user, int &type){
    system("CLS");
    //cout << "Welcome to Hospital-Managment system!" << endl;
    //cout << "Your name: " << user.getName() << endl;
    //cout << "Your lastname: " << user.getLast_name() << endl;
    //cout << "Your date of birthd: " << user.getData_of_birth() << endl;
    //cout << "Your address: " << user.getAddress() << endl;
    //cout << "Type: " << user.getUser_type() << endl;
    if (type == 0) {
        user_menu(user);
    }
    if (type == 1) {
        //doctor_menu(user);
    }
    if (type == 2) {
        //admin_menu(user);
    }
};