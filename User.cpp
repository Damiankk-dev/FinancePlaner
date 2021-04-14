#include "User.h"

void User::setID(int newID){
    if (newID >= 0){
        id = newID;
    }

}
void User::setUsername(string newUsername){
    username = newUsername;
}
void User::setPassword(string newPassword){
    password = newPassword;
}

int User::getID(){
    return id;
}
string User::getUsername(){
    return username;
}
string User::getPassword(){
    return password;
}
