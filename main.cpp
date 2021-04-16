#include <iostream>

#include "Markup.h"

//#include "XMLFile.h"
#include "RegisteredUsersFile.h"
#include "User.h"

#include <vector>

using namespace std;

int main()
{
    //TODO: plik xml z uzytwkonikami
    cout << "Hello world!" << endl;
//    XMLFile newXMLFile;
//    XMLFile *newXMLFile;
//    newXMLFile =  new XMLFile("userss.xml");
    User newUser;
    newUser = User(1, "koles", "qwer");

    RegisteredUsersFile* usersFile;
    usersFile = new RegisteredUsersFile("Juzerz.xml");
    usersFile->appendUserToFile(newUser);
    newUser = User(2, "koles", "qwer");
    usersFile->appendUserToFile(newUser);
    system("pause");

    vector<User> loadedUsers;
    loadedUsers = usersFile->loadUsersFromFile();
//    newUser = usersFile->getUserData();

    cout << "ID: " << loadedUsers[0].getID() << endl;
    cout << "username: " << loadedUsers[0].getUsername() << endl;
    cout << "password: " << loadedUsers[0].getPassword() << endl;
    cout << "ID: " << loadedUsers[1].getID() << endl;
    cout << "username: " << loadedUsers[1].getUsername() << endl;
    cout << "password: " << loadedUsers[1].getPassword() << endl;

//    newXMLFile->isFileInitializedProperly();
//    newXMLFile.isFileInitializedProperly();

    return 0;
}
