#include <iostream>

#include "Markup.h"

#include "RegisteredUsersFile.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include "UserManager.h"
#include "DateServer.h"
#include "Cashflow.h"
#include "CashflowCreator.h"
#include "CashflowFile.h"

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
//    newUserManager.signInUser();
//    newUserManager.changeUserPassword();
    if ( AuxiliaryMethods::isNumber("1234") )
        cout << "Number\n";
    else
        cout << "Not a number\n";
    DateServer dateServer;
//    if ( dateServer.isDateFormatProper("2134-43-21") )
//        cout << "Number\n";
//    else
//        cout << "Not a number\n";
//    if ( dateServer.isDateFormatProper("2134-43-211") )
//        cout << "Number\n";
//    else
//        cout << "Not a number\n";
//    if ( dateServer.isDateFormatProper("2134-4w-21") )
//        cout << "Number\n";
//    else
//        cout << "Not a number\n";
//    if ( dateServer.isDateFormatProper("2134-43.21") )
//        cout << "Number\n";
//    else
//        cout << "Not a number\n";
//    std::string newDate = dateServer.getDateInProperFormat();
//    if (dateServer.isDateAfter2000("2187-10-33") ) {std::cout << "OK\n";}
//    else {std::cout << "BAD\n"  ;}
    CashflowCreator cashflowCreator(1);
    Cashflow *newCashflow;
    Cashflow cashflow(1, 12, 12.43, "klocki", "2012-12-02");
//    cashflowCreator.addCashflow(&cashflow);
    newCashflow = &cashflow;
////    cashflow = cashflowCreator.setNewCashflowData();
    std::cout << "ID "<< newCashflow->getId() << " value "<< newCashflow->getValue() << " label "<< newCashflow->getLabel() << " date  "<< newCashflow->getDate() << std::endl;
    CashflowFile newCashflowFile("eXPENSES.xml");
    newCashflowFile.appendCasflowToFile(newCashflow);


    return 0;
}
