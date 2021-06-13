#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User{
    int id;
    string username;
    string password;

public:
    User(int id = 0, std::string username = "", std::string password = "" ) {
        this->id = id;
        this->username = username;
        this->password = password;
    }

    void setID(int newID);
    void setUsername(string newUsername);
    void setPassword(string newPassword);
    int getID();
    string getUsername();
    string getPassword();
};
#endif
