#include <iostream>

#include "Markup.h"
#include "FinanceManagerInterface.h"

using namespace std;

int main()
{
    FinanceManagerInterface newFinanceManagerInterface("users.xml", "incomes.xml", "expenses.xml");
    while (true)
    {
        if ( !(newFinanceManagerInterface.isUserRegistered() ) )
        {
            newFinanceManagerInterface.showMainMenu();
            char choice = newFinanceManagerInterface.mainMenuChoice;

            switch (choice)
            {
            case '1':
                newFinanceManagerInterface.registerUser();
                break;
            case '2':
                newFinanceManagerInterface.signInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            newFinanceManagerInterface.showSubmenuSignedInUser();
            char choice = newFinanceManagerInterface.mainMenuChoice;

            switch (choice)
            {
            case '1':
                newFinanceManagerInterface.addExpense();
                break;
            case '2':
                newFinanceManagerInterface.addIncome();
                break;
            case '3':
                newFinanceManagerInterface.createBalanceCurrentMonth();
                break;
            case '4':
                newFinanceManagerInterface.createBalancePastMonth();
                break;
            case '5':
                newFinanceManagerInterface.createBalanceAnyPeriod();
                break;
            case '6':
                newFinanceManagerInterface.changeUserPassword();
                break;
            case '7':
                newFinanceManagerInterface.signOutUser();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
