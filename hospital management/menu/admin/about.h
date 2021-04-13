// Ubaydulla's code start 
// =======================//======================


#include <string>
#include <iostream>
#include "../../classes/accounts.h"
#pragma once
using namespace std;

void about_me(User& user) {
	string type;
	system("cls");
	cout << "All info about user:" << endl;
	cout << "Name: " << user.getName() << endl;
	cout << "Last name: " << user.getLast_name() << endl;
	cout << "Date of birthd: " << user.getData_of_birth() << endl;
	cout << "Address: " << user.getAddress() << endl;
	cout << "Username: " << user.getUsername() << endl;
	cout << "Password: **************" << endl;
	cout << "Account type: Admin" << endl;
}


// Ubaydulla's code end
// ----------------------------------------