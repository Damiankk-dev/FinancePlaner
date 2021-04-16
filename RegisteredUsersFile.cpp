#include "RegisteredUsersFile.h"

void RegisteredUsersFile::appendUserToFile(User savedUser)
{
    this->ResetPos();
    this->IntoElem();
    this->AddElem( "USER" );
    this->IntoElem();
    this->AddElem( "ID", savedUser.getID() );
    this->AddElem(  "USERNAME", savedUser.getUsername() );
    this->AddElem( "PASSWORD", savedUser.getPassword() );
    this->Save(this->getFilename());
}
void RegisteredUsersFile::saveUsersToFile()
{
}
vector<User> RegisteredUsersFile::loadUsersFromFile()
{
    vector<User> loadedUsers;
    RegisteredUsersFile *loadedFile = this;
    loadedFile->Load(loadedFile->getFilename() );
    while (loadedFile->FindElem( "USER" ) ){
        loadedFile->IntoElem();
        loadedUsers.push_back(getUserData() );
        loadedFile->OutOfElem();
    }
    return loadedUsers;
}
void RegisteredUsersFile::updateUserData()
{
}
User RegisteredUsersFile::getUserData()
{
    CMarkup *loadedFile = this;
    User loadedUser;

    loadedFile->FindElem( "ID" );
    loadedUser.setID( stoi( loadedFile->GetData() ) );
    loadedFile->FindElem( "USERNAME" );
    loadedUser.setUsername( loadedFile->GetData() );
    loadedFile->FindElem( "PASSWORD" );
    loadedUser.setPassword( loadedFile->GetData() );
    return loadedUser;
}
void RegisteredUsersFile::createXMLUserChild()
{
}
