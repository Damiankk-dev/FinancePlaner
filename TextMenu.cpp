#include "TextMenu.h"

void TextMenu::showMainMenu(){
    system("cls");
    std::cout << "          >>> MENU  GLOWNE <<<" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Rejestracja" << std::endl;
    std::cout << "2. Logowanie" << std::endl;
    std::cout << "9. Koniec programu" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Twoj wybor: ";
}

void showSubmenuFinanceManager(){
    system("cls");
    std::cout << "          >>> MENU  GLOWNE <<<" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1. Dodaj wydatek\n";
    std::cout << "2. Dodaj przychód\n";
    std::cout << "3. Utwórz bilans z biezacego miesiaca\n";
    std::cout << "4. Utwórz bilans z ubieg³ego miesiaca\n";
    std::cout << "5. Utwórz bilans z dowolnego okresu\n";
    std::cout << "6. Zmien haslo\n";
    std::cout << "7. Wyloguj sie\n";
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Twoj wybor: ";
}

char TextMenu::choseFromMainMenu(){
    return AuxiliaryMethods::readChar();
}

char choseFromSubmenuFinanceManager(){
    return AuxiliaryMethods::readChar();
}
