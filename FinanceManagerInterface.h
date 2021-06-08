#ifndef FINANCE_MANAGER_INTERFACE_H
#define FINANCE_MANAGER_INTERFACE_H

#include <iostream>

#include "TextMenu.h"
#include "FinanceOrganizer.h"
#include "UserManager.h"

class FinanceManagerInterface{
    UserManager userManager;
    FinanceOrganizer *financeOrganizer;
    const std::string INCOMES_FILENAME;
    const std::string EXPENSES_FILENAME;

    void showMainMenu();
    void showSubmenuSignedInUser();
    bool isUserRegistered();

public:
    char mainMenuChoice;
    FinanceManagerInterface( std::string registeredUsersFilename, std::string incomesFilename, std::string expensesFilename)
    : userManager(registeredUsersFilename)
    , INCOMES_FILENAME(incomesFilename)
    , EXPENSES_FILENAME(expensesFilename)
    {
        financeOrganizer = NULL;
    };
    ~FinanceManagerInterface(){
        delete financeOrganizer;
        financeOrganizer = NULL;
    }
    void registerUser();
    void signInUser();
    void signOutUser();
    void changeUserPassword();
    void addIncome();
    void addExpense();
    void createBalanceCurrentMonth();
    void createBalancePastMonth();
    void createBalanceAnyPeriod();
};
#endif // FINANCE_MANAGER_INTERFACE_H
