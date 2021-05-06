// Alisher's code start 
// =======================//======================

#pragma once

#include <iostream>
#include <string>
#include "../libraries/sqlite/sqlite3.h"
using namespace std;


class User {
private:
    int rc;
    string sql;
    sqlite3* db;
    sqlite3_stmt* stmt;
    char* err;
    int id, data_of_birth, user_type;
    string password, name, last_name, address, username;
public:
    User() {
        user_type = 0;
        name = "Unknown";
        last_name = "Unknown";
        address = "Unknown";
        data_of_birth = 0;
    }

    void setId(int id) {
        this->id = id;
    }
    int getId() {
        return id;
    }
    void setData_of_birth(int data) {
        this->data_of_birth = data;
    }
    int getData_of_birth() {
        return data_of_birth;
    }
    void setUser_type(int user_type) {
        this->user_type = user_type;
    }
    int getUser_type() {
        return user_type;
    }
    void setPassword(string password) {
        this->password = password;
    }
    string getPassword() {
        return password;
    }
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    void setLast_name(string last_name) {
        this->last_name = last_name;
    }
    string getLast_name() {
        return last_name;
    }
    void setAddress(string adsress) {
        this->address = adsress;
    }
    string getAddress() {
        return address;
    }
    void setUsername(string username) {
        this->username = username;
    }
    string getUsername() {
        return username;
    }

    void set_user_by_username(string username) {
        rc = sqlite3_open("../hm_db.db", &db);
        if (rc) {
            cout << "Connection problems :(" << endl;
        }
        sql = "SELECT * FROM Accounts WHERE username = '" + username + "'";
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt
        sqlite3_step(stmt);

        id = sqlite3_column_int(stmt, 0);
        this->username = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        last_name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        data_of_birth = sqlite3_column_int(stmt, 4);
        address = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        password = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        user_type = sqlite3_column_int(stmt, 7);
    }
    int check_free_username(string name) {
        int rc; // status check variable
        string sql;
        sqlite3* db;
        sqlite3_stmt* stmt; // result from execution
        // connecting to DB
        rc = sqlite3_open("../hm_db.db", &db);
        sql = "SELECT username FROM Accounts WHERE username = '" + name + "'";
        //execute the information from DB
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt // preapre the table version of the resulta
        if (sqlite3_step(stmt) == SQLITE_DONE) return 0;
        else return 1;
    }
    void saveUser() {
        char* err;
        int rc, maxId=0; // status check variable
        string sql;
        sqlite3* db;
        sqlite3_stmt* stmt; // result from execution
        // connecting to DB
        rc = sqlite3_open("../hm_db.db", &db);
        sql = "SELECT id FROM Accounts ";
        //execute the information from DB
        sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0); //placing the result to stmt // preapre the table version of the resulta
        while (sqlite3_step(stmt) != SQLITE_DONE) {
            if (maxId < sqlite3_column_int(stmt, 0)) maxId = sqlite3_column_int(stmt, 0);
        }
        maxId = maxId + 1;
        sql = "INSERT INTO Accounts VALUES (" + to_string(maxId) + ", '" + username + "', '" + name + "', '" + last_name + "', " + to_string(data_of_birth) + ", '" + address + "', '" + password + "', 0)";
        rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &err);
        cout << sql;
        if (rc != SQLITE_OK) cout << "Error: " << err;
        system("pause");
     }
};




// Alisher's code end
// ---------------------------------