#include "VIPTicket.h"

VIPTicket::VIPTicket(const Person& ticketHolder, double price, const std::string& sector, int seat)
    : Ticket(ticketHolder, price, sector, seat) {}

std::string VIPTicket::showInfo() const {
    return Ticket::showInfo() +
           "\nCatering: przekaski + napoje + alkohol";
}