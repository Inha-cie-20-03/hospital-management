// Ubaydulla's code start 
// =======================//======================


#include <string>
#include <iostream>
#include "../../classes/accounts.h"
#pragma once
using namespace std;

void about_doctor(User& user) {
	string type;
	system("cls");
	cout << "All info about user:" << endl;
	cout << "Name: " << user.getName() << endl;
	cout << "Last name: " << user.getLast_name() << endl;
	cout << "Date of birthd: " << user.getData_of_birth() << endl;
	cout << "Address: " << user.getAddress() << endl;
	cout << "Username: " << user.getUsername() << endl;
	cout << "Password: **************" << endl;
	if (user.getUser_type() == 2) type = "admin";
	if (user.getUser_type() == 1) type = "doctor";
	if (user.getUser_type() == 0) type = "user";
	cout << "Account type:" << type << endl;
}


// Ubaydulla's code end
// ----------------------------------------
