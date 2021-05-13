#ifndef CASHFLOW_H
#define CASHFLOW_H

#include <iostream>

#include "DateServer.h"

class Cashflow{
    int SIGNED_USER_ID;
    int id;
    double value;
    std::string label;
    std::string date;
public:
    Cashflow(int signedUserID, int id = 0, double value = 0.0, std::string label = "", std::string date = ""):SIGNED_USER_ID(signedUserID){
        this->id = id;
        this->value = value;
        this->label = label;
        this->date = date;
    }
    void setId(int newId);
    void setValue(double newValue);
    void setLabel(std::string newLabel);
    void setDate(std::string newDate);

    int getSignedInUserId();
    int getId();
    double getValue();
    std::string getLabel();
    std::string getDate();

};
#endif // CASHFLOW_H
