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

}
void RegisteredUsersFile::updateUserData()
{
}
User RegisteredUsersFile::getUserData()
{
    this->Load(this->getFilename() );

}
void RegisteredUsersFile::createXMLUserChild()
{
}
