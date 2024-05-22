#pragma once

#include "Ticket.h"

class NormalTicket : public Ticket {
public:
    NormalTicket(const Person& ticketHolder, double price, const std::string& sector, int seat);

    std::string showInfo() const override;
};