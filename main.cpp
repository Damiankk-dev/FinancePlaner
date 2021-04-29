#include <iostream>

#include "Markup.h"

#include "RegisteredUsersFile.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include "UserManager.h"

#include <vector>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
//    cout << "read sign is : " << AuxiliaryMethods::readChar() << endl;
//    cout << "Dodam 1111 do 2222\n" << AuxiliaryMethods::convertString2Int("1111") + AuxiliaryMethods::convertString2Int("2222");
    cout << "Float: " << endl;
    UserManager newUserManager("juzerzy.xml");

    cout << AuxiliaryMethods::convertString2Date("1978-03-15") << endl;
    cout << AuxiliaryMethods::convertDate2String(AuxiliaryMethods::convertString2Date("1978-03-15"))<< endl;

//    newUserManager.registerUser();
    newUserManager.signInUser();
    newUserManager.changeUserPassword();
//    string s1 = "123,43";
//    AuxiliaryMethods::changeCommaToPeriod(&s1);

    return 0;
}
