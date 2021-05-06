#pragma once
#include <string>
#include <iostream>

using namespace std;


void user_bookings() {
    int rc, order, date;; // status check variable
    string sql, username;
    sqlite3* db;
    sqlite3_stmt* stmt; // result from execution
    // connecting to DB
    rc = sqlite3_open("../hm_db.db", &db);
    //prepare the sql 
    cout << "Enter username of user: "; cin >> username;
    sql = "SELECT Management.day_order, Management.date from Accounts, Management, Clinics where Management.clinic_id = 1 and Management.user_id = Accounts.id and Accounts.username ='"+ username +"'";
    //execute the information from DB
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt // preapre the table version of the resulta
        while (sqlite3_step(stmt) != SQLITE_DONE) {
            order = sqlite3_column_int(stmt, 0);
            date = sqlite3_column_int(stmt, 1);
            cout << "=================================" << endl;
            cout << "Username: " << username << endl;
            cout << "Date of visiting: " << date << endl;
            cout << "Day order: " << order << endl;
        };
        cout << "===============================" << endl;
}