// Pulatov Ubaydulla U2010210
// Rafiev Alisher U2010213
// Olimjon Nematov U2010

#include <iostream>
#include "menu/main_menu.h"
#include "log/log.h"
#include "classes/accounts.h"
using namespace std;

int main() {
    int a;
    User* user = new User();


login:
    if (log_status() == 1) // log status will return 1 if user is registered and 0 if not
        // the user can also sign up in this step
    {
        main_menu(); //if log status 1 the user will have access to menu
    }
    else
    {
        cout << "If you want retry type 1, else 0 for exit from app." << endl;
        cin >> a;
        if (a == 1)
            goto login;
    }
    cout << "Good bye!" << endl;
    system("pause");
    return 0;
}