#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include <iostream>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "RegisteredUsersFile.h"

class UserManager{
public:
    UserManager(std::string registeredUsersFilename) : registeredUsersFile(registeredUsersFilename) {
        users = registeredUsersFile.loadUsersFromFile();
    };

    void registerUser();
    void changeUserPassword();
    void signOutUser();
    bool isUserSignedIn();
    int signInUser();
    int getSignedInUserID();

private:
    int signedInUserID = 0;
    vector<User> users;
    RegisteredUsersFile registeredUsersFile;

    bool isUsernameExists(std::string);
    bool isPasswordCorrect();//optional
    int getNewUserID();
    User addNewUser();
};
#endif // USER_MANAGER_H
