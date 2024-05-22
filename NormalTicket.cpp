#include "NormalTicket.h"

NormalTicket::NormalTicket(const Person& ticketHolder, double price, const std::string& sector, int seat)
    : Ticket(ticketHolder, price, sector, seat) {}

std::string NormalTicket::showInfo() const {
    return Ticket::showInfo();
}