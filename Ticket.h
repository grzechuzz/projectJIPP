#pragma once

#include <string>
#include "Person.h"

class Ticket {

protected:
    Person ticketHolder;
    double price;
    std::string sector;
    int seat;

public:
    Ticket(const Person& tickerHolder, double price, const std::string& sector, int seat);
    virtual std::string showInfo() const;
    const Person& getTicketHolder() const;
    const std::string& getSector() const;
    int getPlace() const;
};