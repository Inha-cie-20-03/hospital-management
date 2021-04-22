// Ubaydulla's code start 
// =======================//======================


#include <string>
#include <iostream>
#include "../../classes/accounts.h"
#pragma once
using namespace std;

void all_doc_bookings(User& user) {
    int rc; // status check variable
    string sql, id;
    sqlite3* db;
    sqlite3_stmt* stmt; // result from execution
    // connecting to DB
    rc = sqlite3_open("../hm_db.db", &db);
    //prepare the sql 
    //id = itos(user.getId());
    sql = "SELECT Accounts.name, Management.day_order, Management.date from Accounts, Management, Clinics where Management.clinic_id = 1 and Management.user_id = Accounts.id and Management.doctor_id = 4";
    //execute the information from DB
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt
    rc = sqlite3_step(stmt); // preapre the table version of the resulta
    if (rc == SQLITE_DONE) { // checking is there any row as a result was return
        //if no ->
        cout << "You don't have any bookings!" << endl;
        system("pause");
    }
    else {
        string  name;
        int order, date;
        name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        order = sqlite3_column_int(stmt, 1);
        date = sqlite3_column_int(stmt, 2);
        cout << "=================================" << endl;
        cout << "Name: " << name << endl;
        cout << "Day order: " << order << endl;
        cout << "Date of visiting: " << date << endl;
    };
}

void bookings_for_today(User &user) {
    int rc; // status check variable
    string sql, id;
    sqlite3* db;
    sqlite3_stmt* stmt; // result from execution
    // connecting to DB
    rc = sqlite3_open("../hm_db.db", &db);
    //prepare the sql 
    sql = "SELECT Accounts.name, Management.day_order, Management.date from Accounts, Management, Clinics where Management.clinic_id = 1 and Management.user_id = Accounts.id and Management.doctor_id = 4 and Management.date = 3302021";
    //execute the information from DB
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt
    rc = sqlite3_step(stmt); // preapre the table version of the resulta
    if (rc == SQLITE_DONE) { // checking is there any row as a result was return
        //if no ->
        cout << "You don't have any bookings!" << endl;
        system("pause");
    }
    else {
        string  name;
        int order, date;
        name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        order = sqlite3_column_int(stmt, 1);
        date = sqlite3_column_int(stmt, 2);
        cout << "====================================" << endl;
        cout << "Name: " << name << endl;
        cout << "Day order: " << order << endl;
        cout << "Date of visiting: " << date << endl;
    };
}

// Ubaydulla's code end
// ----------------------------------------
