#include "FinanceManagerInterface.h"

void FinanceManagerInterface::showMainMenu(){
    TextMenu textMenu;
    textMenu.showMainMenu();
    mainMenuChoice = textMenu.choseFromMainMenu();
}

void FinanceManagerInterface::showSubmenuSignedInUser(){
    TextMenu textMenu;
    textMenu.showSubmenuFinanceManager();
    mainMenuChoice = textMenu.choseFromSubmenuFinanceManager();
}

void FinanceManagerInterface::registerUser(){
    userManager.registerUser();
}

void FinanceManagerInterface::signInUser(){
    userManager.signInUser();
    financeOrganizer = new FinanceOrganizer(userManager.getSignedInUserID(), INCOMES_FILENAME, EXPENSES_FILENAME);
}
void FinanceManagerInterface::signOutUser(){
    userManager.signOutUser();
    delete financeOrganizer;
    financeOrganizer = NULL;
}
void FinanceManagerInterface::changeUserPassword(){
    userManager.changeUserPassword();
}
void FinanceManagerInterface::addIncome(){

}
void FinanceManagerInterface::addExpense(){

}
void FinanceManagerInterface::createBalanceCurrentMonth(){

}
void FinanceManagerInterface::createBalancePastMonth(){

}
void FinanceManagerInterface::createBalanceAnyPeriod(){

}
bool FinanceManagerInterface::isUserRegistered(){
    return userManager.isUserSignedIn();
}
