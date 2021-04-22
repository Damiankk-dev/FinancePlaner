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
//    cout << "read sign is : " << AuxiliaryMethods::readChar() << endl;
//    cout << "Dodam 1111 do 2222\n" << AuxiliaryMethods::convertString2Int("1111") + AuxiliaryMethods::convertString2Int("2222");
    cout << "Float: " << endl;
    cout << AuxiliaryMethods::readFloat() << endl;
//    string s1 = "123,43";
//    AuxiliaryMethods::changeCommaToPeriod(&s1);

    return 0;
}
