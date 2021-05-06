//Olimjon's code starts
#include <string>
#include <iostream>
#include "../../classes/accounts.h"
#pragma once
#include "book.h"
using namespace std;

void cancel_booking(User& user) {

    int userId = user.getId();
    int last_day;
    int rc; // status check variable
    string sql;
    sqlite3* db;
    char* err;
    sqlite3_stmt* stmt; // result from execution
    // connecting to DB
    rc = sqlite3_open_v2("../hm_db.db", &db, SQLITE_OPEN_READWRITE, NULL);

    sql = "Select day_order from Management where user_id = " + to_string(userId) + " and date=" + to_string(3302021) + "";
    //execute the information from DB
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt
    rc = sqlite3_step(stmt); // preapre the table version of the resulta
    if (rc == SQLITE_DONE) { // checking is there any row as a result was return
        //if no ->
        cout << "You don't have any bookings!" << endl;
        system("pause");
    }
    else {

        while (sqlite3_step(stmt) != SQLITE_DONE) {
            last_day = sqlite3_column_int(stmt, 0);
        }
    }

    //prepare the sql 
    sql = "DELETE FROM Management WHERE date=" + to_string(3302021) + " and user_id = "+to_string(userId)+" and day_order = "+to_string(last_day)+"";
    //execute the information from DB
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &err);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
    }
    else {
        fprintf(stdout, "Canceled successfully\n");
    }

}
//Olimjon's code ends