#include "UserManager.h"

void UserManager::registerUser(){
    User newlyRegisteredUser = addNewUser();

    users.push_back(newlyRegisteredUser);
    registeredUsersFile.appendUserToFile(newlyRegisteredUser);
    std::cout << std::endl << "Konto zalozono pomyslnie\n\n";
    system("pause");
}
//    void changeUserPassword();
//    void signOutUser();
//
//    bool isUserSignedIn();
//
//    int signInUser();
//    int getSignedInUserID();
//
//private:
//    int signedInUserID;
//    vector<User> users;
//    RegisteredUsersFile registeredUsersFile;
//
//    bool isUsernameExists(std::string);
//    bool isPasswordCorrect();//optional
//
//    int getNewUserID();
//
User UserManager::addNewUser(){
    User newUser;
    return newUser;
}
