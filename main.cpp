#include <iostream>

#include "Markup.h"

//#include "XMLFile.h"
#include "RegisteredUsersFile.h"
#include "User.h"

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
//    newXMLFile->isFileInitializedProperly();
//    newXMLFile.isFileInitializedProperly();

    return 0;
}
