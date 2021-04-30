//Olimjon's code starts
#include <string>
#include <iostream>
#include "../../classes/accounts.h"
#pragma once
using namespace std;

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void book_doctor(User& user) {
    int userId = user.getId();
    int rc; // status check variable
    string sql, id;
    sqlite3* db;
    sqlite3_stmt* stmt; // result from execution
    // connecting to DB
    rc = sqlite3_open_v2("../hm_db.db", &db, SQLITE_OPEN_READWRITE, NULL);
    //prepare the sql 
    //id = itos(user.getId());
    sql = "Select day_order, id from Management where user_id = " + to_string(userId) + " and date=" + to_string(3302021) + "" ;
    //execute the information from DB
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt
    rc = sqlite3_step(stmt); // preapre the table version of the resulta
    if (rc == SQLITE_DONE) { // checking is there any row as a result was return
        //if no ->
        cout << "You don't have any bookings!" << endl;
        system("pause");
    }
    else {
        char* err;
        int last_day = 0, last_id=0;
        while (sqlite3_step(stmt) != SQLITE_DONE) {
            last_day = sqlite3_column_int(stmt, 0);
            last_id = sqlite3_column_int(stmt, 1);
        }
        last_id++;
        last_day++;
        rc = sqlite3_open_v2("../hm_db.db", &db, SQLITE_OPEN_READWRITE, NULL);
        sql = "INSERT into Management VALUES ("+to_string(last_id)+",1,4,"+to_string(userId)+","+ to_string(3302021) +"," + to_string(last_day) + ")";
        rc = sqlite3_exec(db, sql.c_str(), callback, 0, &err);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", err);
            sqlite3_free(err);
        }
        else {
            fprintf(stdout, "Booked successfully\n");
        }


        sqlite3_close(db);

    };
}
//Olimjon's code ends