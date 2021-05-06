// Ubaydulla's code start 
// =======================//======================

#pragma once
#include <iostream>
#include <string>
#include "../classes/accounts.h"

using namespace std;
 


int sign_up(User &user) {
	string var, var2;
	User new_user;
	int int_var;
	int busy = 0;
	system("cls");
	cout << "Welcome A new user to a Hospiatal bboking system!" << endl;
	cout << "Let's start set up a new account." << endl;
	cout << "Enter your name: "; cin >> var;
	new_user.setName(var);
	cout << "Enter the last name: "; cin >> var;
	new_user.setLast_name(var);
	cout << "Enter the date of birth: (DDMMYY)- only numbers: ", cin >> int_var;
	new_user.setData_of_birth(int_var);
	cout << "Enter your livving address: "; cin >> var;
	new_user.setAddress(var);
	username:
	cout << "Enter your username (it will be used to login to system): "; cin >> var;
	//new_user.Check_free_username(var) take string and return 1 if it is busy
	if (busy == 1) {
		cout << "This username already taken! Please try another one." << endl;
		goto username;
	}
	new_user.setUsername(var);
	cout << "Enter the password: "; cin >> var;
	reenter:
	cout << "Enter password again: "; cin >> var2;
	if (var != var2) {
		cout << "Incorrect!" << endl;
		goto reenter;
	}
	new_user.setPassword(var);
	new_user.setUser_type(0);

	// Verify

	cout << "Name: " << new_user.getName() << endl;
	cout << "Last name: " << new_user.getLast_name() << endl;
	cout << "Date of birthd: " << new_user.getData_of_birth() << endl;
	cout << "Address: " << new_user.getAddress() << endl;
	cout << "Username: " << new_user.getUsername() << endl;
	cout << "Password: **************" << endl;

	cout << "Is it correct (y/n): "; cin >> var;
	if (var == "y") {
		// new_user.saveUser()
		return 1;
	}
	cout << "We are sorry for dufficulties. If you have any problem just live a comment." << endl;
	return 0;
}



// Ubaydulla's code end
// ----------------------------------------