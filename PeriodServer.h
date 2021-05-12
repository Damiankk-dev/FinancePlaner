#ifndef PERIOD_SERVER_H
#define PERIOD_SERVER_H

#include <iostream>

#include "DateServer.h"
class PeriodServer : public DateServer{
public:
    std::string specifyPeriod();
};
#endif // PERIOD_SERVER_H
