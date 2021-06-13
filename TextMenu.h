#ifndef TEXT_MENU_H
#define TEXT_MENU_H

#include <iostream>

#include "AuxiliaryMethods.h"

class TextMenu{
public:
    void showMainMenu();
    void showSubmenuFinanceManager();
    char choseFromMainMenu();
    char choseFromSubmenuFinanceManager();
};
#endif // TEXT_MENU_H
