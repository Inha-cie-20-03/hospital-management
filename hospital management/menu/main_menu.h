// Ubaydulla's code start 
// =======================//======================

#include <string>
#include <iostream>
#include "user/user.h"
#include "doctor/doctor.h"
#include "admin/admin.h"
#include "../classes/accounts.h"
#pragma once
using namespace std;


void main_menu(User &user){
    int type = user.getUser_type();
    if (type == 0) {
        user_menu(user);
    }
    if (type == 1) {
        doctor_menu(user);
    }
    if (type == 2) {
        admin_menu(user);
    }
};


// Ubaydulla's code end
// ----------------------------------------