// Pulatov Ubaydulla U2010210
// Rafiev Alisher U2010213
// Olimjon Nematov U2010189

// Ubaydulla's code start 
// =======================//======================

#include <iostream>
#include "menu/main_menu.h"
#include "log/log.h"
#include "classes/accounts.h"
#include "classes/accounts.h"

using namespace std;

int main() {
    int a;
    User user;


login:
    a = log_status(user);
        switch(a) {
        case 1:
            main_menu(user);
            system("pause");
            break;
        case 0:
            cout << "If you want retry type 1, else 0 for exit from app." << endl;
            cin >> a;
            if (a == 1) goto login;
            break;
        case 2:
            break;
        default:
            cout << "Enter the correct symbol!" << endl;
            goto login;
            break;
        };
    return 0;
}

// Ubaydulla's code end
// ----------------------------------------