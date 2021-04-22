#pragma once
#include <string>
#include <iostream>

using namespace std;


void user_bookings() {
    int rc; // status check variable
    string sql, id;
    sqlite3* db;
    sqlite3_stmt* stmt; // result from execution
    // connecting to DB
    rc = sqlite3_open("../hm_db.db", &db);
    //prepare the sql 
    //id = itos(user.getId());
    cout << "Enter username of user: "; cin >> id;
    sql = "SELECT Management.day_order, Management.date from Accounts, Management, Clinics where Management.clinic_id = 1 and Management.user_id = Accounts.id and Accounts.username ='"+id+"'";
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
        order = sqlite3_column_int(stmt, 0);
        date = sqlite3_column_int(stmt, 1);
        cout << "=================================" << endl;
        cout << "Username: " << id << endl;
        cout << "Date of visiting: " << date << endl;
        cout << "Day order: " << order << endl;
    };
}