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
bool UserManager::isUsernameExists(std::string uniqueUsername){
    for (int i = 0; i < users.size(); i++){
        if (users[i].getUsername() == uniqueUsername){
            std::cout << "Podana nazwa jest juz w uzyciu, sproboj innej\n";
            return true;
        }
    }
    return false;
}
//    bool isPasswordCorrect();//optional
//
int UserManager::getNewUserID(){
    if ( users.empty() == true ){
        return 1;
    } else{
        return 1 + users.back().getID() ;
    }
}
//
User UserManager::addNewUser(){
    User newUser;

    newUser.setID( getNewUserID() );

    AuxiliaryMethods auxiliaryMethods;

    do{
        std::cout << "Podaj login: ";
        newUser.setUsername(auxiliaryMethods.readLine() );
    } while ( isUsernameExists( newUser.getUsername() ) );

    std::cout << "Podaj haslo: ";
    newUser.setPassword( auxiliaryMethods.readLine() );

    return newUser;
}
