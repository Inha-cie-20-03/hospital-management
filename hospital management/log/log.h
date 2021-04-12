// Ubaydulla's code start 
// =======================//======================

#include <string>
#include <iostream>
#include "login.h"
#include "signup.h"
//#include "../classes/accounts.h"

using namespace std;

int log_status(string &user, int &type){
    int los; // los = login or signup
    string username, password;

    cout << "Enter: \n 1 - to LogIn \n 2 - for SignUp" << endl;
    cout << "Enter command: "; cin >> los;
    if (los == 1)
    {
        system("CLS");
        cout << "Welcome to login page!" << endl << endl;
        cout << "Enter username: "; cin >> username;
        cout << "Enter password: "; cin >> password;
        if (check_login(username, password, type) == 1) { 
            user = username;
            return 1; } // check_login finction will return 1 if this user exist and 0 if not
        else return 0;
    }
    else if (los == 2) {
        if (sign_up() == 1) return 1;
        else return 0;
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