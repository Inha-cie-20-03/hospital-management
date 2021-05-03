//Olimjon's code starts
#include <string>
#include <iostream>
#include "../../classes/accounts.h"
#pragma once
using namespace std;

void active_bookings(User& user) {

    int userId = user.getId();

	
    int rc; // status check variable
    string sql;
    sqlite3* db;
    sqlite3_stmt* stmt; // result from execution
    // connecting to DB
    rc = sqlite3_open_v2("../hm_db.db", &db, SQLITE_OPEN_READWRITE, NULL);
    //prepare the sql 
    sql = " SELECT Management.day_order, Management.date, Doctors.type from Accounts, Management, Clinics, Doctors where Management.clinic_id = 1 and Management.user_id = "+to_string(userId)+" and Management.doctor_id=4 and Accounts.id = Management.user_id ";
    //execute the information from DB
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt
    rc = sqlite3_step(stmt); // preapre the table version of the resulta
    if (rc == SQLITE_DONE) { // checking is there any row as a result was return
        //if no ->
        cout << "You don't have any bookings!" << endl;
        system("pause");
    }
    else {
        int day_order, date;
        string doctor_type;
        system("cls");
        cout << "=======================================\n";
        while (sqlite3_step(stmt) != SQLITE_DONE) {
            day_order = sqlite3_column_int(stmt, 0);
            date = sqlite3_column_int(stmt, 1);
            doctor_type = sqlite3_column_int(stmt, 2);
            cout << "Day Order: " << day_order << "\n";
            cout << "Date: " << date << "\n\n";
        }
        cout << "=======================================\n";
        sqlite3_close(db);
    };

}
//Olimjon's code ends