#pragma once

#include "Ticket.h"

class VIPTicket : public Ticket {
public:
    VIPTicket(const Person& ticketHolder, double price, const std::string& sector, int seat);

    std::string showInfo() const override;
};