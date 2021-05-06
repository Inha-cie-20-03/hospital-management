//Olimjon's code starts
#include <string>
#include <iostream>
#include "../../classes/accounts.h"
#pragma once
using namespace std;

void book_doctor(User& user) {
    char* err;
    int date, lastOrder{}, rc;
    // status check variable
    string sql, id;
    sqlite3* db;
    sqlite3_stmt* stmt; // result from execution
    rc = sqlite3_open("../hm_db.db", &db);
   //prepare the sql 
redate:
    cout << "Enter the date of booking (mm/dd/yyyy): "; cin >> date;
    sql = "Select day_order from Management where date = " + to_string(date);
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt // preapre the table version of the resulta
    while (sqlite3_step(stmt) != SQLITE_DONE) {
        if (lastOrder <= sqlite3_column_int(stmt, 0)) lastOrder = sqlite3_column_int(stmt, 0);
    }
    if (lastOrder >= 4) {
        cout << "This day is busy, choose another day.";
        goto redate;
    }
    lastOrder = lastOrder + 1;
    sql = "INSERT INTO Management VALUES (1,4," + to_string(user.getId()) + "," + to_string(date) + "," + to_string(lastOrder) + ")";
    rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
    if (rc != SQLITE_OK) {
        cout << "Error: " << err;
        system("pause");
    }
};
//Olimjon's code ends