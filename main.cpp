#include <iostream>

#include "Markup.h"

#include "RegisteredUsersFile.h"
#include "User.h"
#include "AuxiliaryMethods.h"

#include <vector>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << "read sign is : " << AuxiliaryMethods::readChar() << endl;
    string s1 = "1111", s2 = "2222";
    cout << "Dodam 1111 do 2222\n" << AuxiliaryMethods::convertString2Int("1111") + AuxiliaryMethods::convertString2Int("2222");
    return 0;
}
