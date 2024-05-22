#pragma once

#include "Ticket.h"

class DiscountTicket : public Ticket {
public:
    DiscountTicket(const Person& ticketHolder, double price, const std::string& sector, int seat);

    std::string showInfo() const override;
};