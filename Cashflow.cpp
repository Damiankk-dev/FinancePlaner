#include "Cashflow.h"

void Cashflow::setId(int newId){
    if ( newId >0 )
        id = newId;
}
void Cashflow::setValue(double newValue){
    value = newValue;
}

void Cashflow::setLabel(std::string newLabel){
    label = newLabel;
}
void Cashflow::setDate(std::string newDate){
    date = newDate;
}

int Cashflow::getSignedInUserId(){
    return SIGNED_USER_ID;
}
int Cashflow::getId(){
    return id;
}
double Cashflow::getValue(){
    return value;
}
std::string Cashflow::getLabel(){
    return label;
}
std::string Cashflow::getDate(){
    return date;
}
