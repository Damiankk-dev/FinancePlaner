#ifndef REGISTERED_USERS_FILE_H
#define REGISTERED_USERS_FILE_H

#include <iostream>
#include <vector>

#include "XMLFile.h"
#include "User.h"


class RegisteredUsersFile : public XMLFile{
public:
    RegisteredUsersFile() : XMLFile("defaultFileName.xml"){}
    RegisteredUsersFile(std::string registeredUsersFilename) : XMLFile(registeredUsersFilename) {
    isFileInitializedProperly();
    }
    void appendUserToFile(User savedUser);
    vector<User> loadUsersFromFile();
    void updateUserData(User);
    //test zone
private:
    User getUserData();
    vector<User> registeredUsers;
};

#endif // REGISTERED_USERS_FILE
