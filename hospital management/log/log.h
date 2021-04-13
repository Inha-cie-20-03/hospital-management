// Ubaydulla's code start 
// =======================//======================


#include <string>
#include <iostream>
#include "login.h"
#include "signup.h"
#include "../classes/accounts.h"
#pragma once
using namespace std;

int log_status(User &user){
    int los; // los = login or signup
    string username, password;

    cout << "Enter: \n 1 - to LogIn \n 2 - for SignUp \n 3 - Exit" << endl;
    cout << "Enter command: "; cin >> los;
    if (los == 1)
    {
        system("CLS");
        cout << "Welcome to login page!" << endl << endl;
        cout << "Enter username: "; cin >> username;
        cout << "Enter password: "; cin >> password;
        if (check_login(username, password) == 1) { 
            user.set_user_by_username(username);
            //lalal.set_user_by_username(username);
            return 1; } // check_login finction will return 1 if this user exist and 0 if not
        else return 0;
    }
    else if (los == 2) {
        if (sign_up() == 1) return 1;
        else return 0;
    }
    else if (los == 3) {
        return 2;
    }
    else
    {
        cout << "You enter a wrong number" << endl;
        system("pause");
        return 0;
    }
};


// Ubaydulla's code end
// ----------------------------------------