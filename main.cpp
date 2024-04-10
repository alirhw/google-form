#include "src/controllers/user.hpp"
#include "src/views/login.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string username, password;
    displayLogin(username, password);
    if (Authenticator::authenticate(username, password)) {
        system("cls");
        cout << "Login successful! Welcome, " << username << "!" << endl;
    } else {
        cout << "Invalid username, password, or role. Login failed." << endl;
    }

    return 0;
}
