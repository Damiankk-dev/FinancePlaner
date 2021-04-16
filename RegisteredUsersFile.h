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
    void saveUsersToFile();
    vector<User> loadUsersFromFile();
    void updateUserData();
    //test zone
private:
    void createXMLUserChild();
    User getUserData();
};

#endif // REGISTERED_USERS_FILE
