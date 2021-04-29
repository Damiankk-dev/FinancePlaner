#include "UserManager.h"

void UserManager::registerUser(){
    User newlyRegisteredUser = addNewUser();

    users.push_back(newlyRegisteredUser);
    registeredUsersFile.appendUserToFile(newlyRegisteredUser);
    std::cout << std::endl << "Konto zalozono pomyslnie\n\n";
    system("pause");
}
void UserManager::changeUserPassword(){
    AuxiliaryMethods auxiliaryMethods;
    std::string newPassword= "";
    std::cout << "Podaj nowe haslo: ";
    newPassword = auxiliaryMethods.readLine();

    for (vector<User>::iterator itr = users.begin(), finish = users.end(); itr != finish; itr++){
        if (itr->getID() == signedInUserID ){
            itr->setPassword ( newPassword );
            registeredUsersFile.updateUserData(*itr);
            std::cout << "Haslo zostalo zmienione.\n\n";
            system("pause");
        }
    }
}
void UserManager::signOutUser(){
    signedInUserID = 0;
    system("cls");
    std::cout << "\nWylogowano uzytkownika\n\n";
    system("pause");
}

bool UserManager::isUserSignedIn(){
    if ( signedInUserID > 0 ) return true;
    else return false;
}

int UserManager::signInUser(){
    User user;
    AuxiliaryMethods auxiliaryMethods;
    std::string username = "", password = "";

    std::cout << "\nPodaj login: ";
    username = auxiliaryMethods.readLine();

    vector<User>::iterator itr = users.begin();
    while (itr != users.end() ) {
        if (itr->getUsername() == username) {
            for (int wrongAttemptsLeft = 3; wrongAttemptsLeft > 0; wrongAttemptsLeft--) {
                std::cout << "Podaj haslo. Pozostalo prob: " << wrongAttemptsLeft << ": ";
                password = auxiliaryMethods.readLine();
                if (itr->getPassword() == password) {
                    std::cout <<  "\nZalogowales sie.\n\n";
                    system("pause");
                    signedInUserID = itr->getID();
                    return signedInUserID;
                }
            }
            std::cout << "Wprowadzono 3 razy bledne haslo.\n";
            system("pause");
            signedInUserID = 0;
            return signedInUserID;
        }
        itr++;
    }
    std::cout << "Nie ma uzytkownika z takim loginem\n\n";
    system("pause");
    signedInUserID = 0;
    return signedInUserID;

}
int UserManager::getSignedInUserID(){
    return signedInUserID;
}
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
