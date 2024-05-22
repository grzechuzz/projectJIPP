#include "DiscountTicket.h"

DiscountTicket::DiscountTicket(const Person& ticketHolder, double price, const std::string& sector, int seat)
    : Ticket(ticketHolder, price, sector, seat) {}

std::string DiscountTicket::showInfo() const {
    return "Bilet ulgowy\n" +
        Ticket::showInfo();
}