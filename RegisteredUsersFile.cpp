#include "RegisteredUsersFile.h"

void RegisteredUsersFile::appendUserToFile(User savedUser)
{
    this->ResetPos();
    this->FindElem( "root" );
    this->IntoElem();
    this->AddElem( "USER" );
    this->IntoElem();
    this->AddElem( "ID", savedUser.getID() );
    this->AddElem(  "USERNAME", savedUser.getUsername() );
    this->AddElem( "PASSWORD", savedUser.getPassword() );
    this->Save(this->getFilename());
    this->ResetPos();
}
vector<User> RegisteredUsersFile::loadUsersFromFile()
{
    vector<User> loadedUsers;
    RegisteredUsersFile *loadedFile = this;
    loadedFile->Load(loadedFile->getFilename() );
    loadedFile->FindElem( "root" );
    loadedFile->IntoElem();
    while (loadedFile->FindElem( "USER" ) ){
        this->isFileEmpty = false;
        loadedFile->IntoElem();
        loadedUsers.push_back(getUserData() );
        loadedFile->OutOfElem();
    }
    return loadedUsers;
}
void RegisteredUsersFile::updateUserData(User userWithNewData)
{
    RegisteredUsersFile *loadedFile = this;
    int userID = userWithNewData.getID();
    loadedFile->resetPositionAndMoveIntoRoot();
//    loadedFile->ResetPos();
//    loadedFile->FindElem( "root" );
//    loadedFile->IntoElem();
    while (loadedFile->FindElem( "USER" ) ){
        loadedFile->IntoElem();
        loadedFile->FindElem( "ID" );
        int foundID = stoi( loadedFile->GetData() );
        if (foundID == userID){
            loadedFile->OutOfElem();
            loadedFile->RemoveElem();
        } else loadedFile->OutOfElem();
    }
    appendUserToFile(userWithNewData);
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
