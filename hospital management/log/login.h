// Ubaydulla's code start 
// =======================//======================

#pragma once
#include <string>
#include "../libraries/sqlite/sqlite3.h"

using namespace std;

int check_login(string username, string password, int &type){
    int rc; // status check variable
    string sql, passwordDB;
    sqlite3* db;
    sqlite3_stmt* stmt; // result from execution
    // connecting to DB
    rc = sqlite3_open("../hm_db.db", &db);
    // checking the connection status
    if (rc) {
        cout << "Connection problems :(" << endl;
        system("pause");
        // exit from login function because of connection problems
        return 0;
    }
    //prepare the sql 
    sql = "SELECT password, type FROM Accounts WHERE username = '" + username + "'";
    //execute the information from DB
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt
    rc = sqlite3_step(stmt); // preapre the table version of the resulta
    if (rc == SQLITE_DONE) { // checking is there any row as a result was return
        //if no ->
        cout << "Your login or password is incorrect, try again or signup" << endl;
        system("pause");
        return 0; // return 0 because there is no username match
    }
    else {
        passwordDB = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))); // taking the 0 row and 0 column
        if (password == passwordDB)
        {
            type = sqlite3_column_int(stmt, 1);
            return 1;
        }
        else {
            cout << "Your login or password is incorrect, try again or signup" << endl;
            system("pause");
            return 0;
        }
    }
}


// Ubaydulla's code end
// ----------------------------------------