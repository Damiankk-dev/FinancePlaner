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
#include "FinanceOrganizer.h"
#include "BalanceCreator.h"

#include <vector>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
//    cout << "read sign is : " << AuxiliaryMethods::readChar() << endl;
//    cout << "Dodam 1111 do 2222\n" << AuxiliaryMethods::convertString2Int("1111") + AuxiliaryMethods::convertString2Int("2222");
//    cout << "Float: " << endl;
//    UserManager newUserManager("juzerzy.xml");
//
//    cout << AuxiliaryMethods::convertString2Date("1978-03-15") << endl;
//    cout << AuxiliaryMethods::convertDate2String(AuxiliaryMethods::convertString2Date("1978-03-15"))<< endl;

//    newUserManager.registerUser();
//    newUserManager.signInUser();
//    newUserManager.changeUserPassword();
//    if ( AuxiliaryMethods::isNumber("1234") )
//        cout << "Number\n";
//    else
//        cout << "Not a number\n";
//    DateServer dateServer;
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
//    CashflowCreator cashflowCreator();
//    Cashflow *newCashflow;
//    cashflow = cashflowCreator.setNewCashflowData();
//    double cshfVal = 12.93;
//    Cashflow cashflow(1, 18, cshfVal, "klocki", "2012-12-02");
//    cashflowCreator.addCashflow(&cashflow);
//    newCashflow = &cashflow;
////    cashflow = cashflowCreator.setNewCashflowData();
//    std::cout << "ID "<< newCashflow->getId() << " value "<< newCashflow->getValue() << " label "<< newCashflow->getLabel() << " date  "<< newCashflow->getDate() << std::endl;
//    CashflowFile newCashflowFile("eXPENSES.xml");
//    newCashflowFile.appendCasflowToFile(newCashflow);
//    std::cout << "Last ID of user 1: "<< newCashflowFile.getLastCashflowID(1) << std::endl;
//    std::cout << "Last ID of user 2: "<< newCashflowFile.getLastCashflowID(2) << std::endl;

//    std::vector<Cashflow> cashflows;
//
//    cashflows = newCashflowFile.loadSignedInUserCashflowFromFile(1);
//    std::cout << "User 1 cashflows:\n";
//    for (std::vector<Cashflow>::iterator itr = cashflows.begin(), finish = cashflows.end();
//        itr != finish ; itr++){
//            newCashflow = &*itr;
//            std::cout << "ID "<< newCashflow->getId() << " value "<< newCashflow->getValue() << " label "<< newCashflow->getLabel() << " date  "<< newCashflow->getDate() << std::endl;
//        }
//    cashflows.clear();
//    cashflows = newCashflowFile.loadSignedInUserCashflowFromFile(2);
//    std::cout << "User 2 cashflows:\n";
//    for (std::vector<Cashflow>::iterator itr = cashflows.begin(), finish = cashflows.end();
//        itr != finish ; itr++){
//            newCashflow = &*itr;
//            std::cout << "ID "<< newCashflow->getId() << " value "<< newCashflow->getValue() << " label "<< newCashflow->getLabel() << " date  "<< newCashflow->getDate() << std::endl;
//        }
//    FinanceOrganizer financeOrganizer( 1, "incomes.xml", "eXPENSES.xml" );
//    financeOrganizer.createNewCashflow(1, "eXPENSES.xml");
    BalanceCreator newBalance(1, "incomes.xml", "eXPENSES.xml" );
    newBalance.loadCasfhlowsFromFileByGivenPeriod();
    return 0;
}
