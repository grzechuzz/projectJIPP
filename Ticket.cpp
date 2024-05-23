#include "Ticket.h"
#include <iomanip>
#include <sstream>

Ticket::Ticket(const Person& ticketHolder, double price, const std::string& sector, int seat)
    : ticketHolder(ticketHolder), price(price), sector(sector), seat(seat) {}

std::string Ticket::showInfo() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << price << " z\u0142";
    return "Cena: " + oss.str() + "\n" +
        "Sektor: " + sector + "\n" +
        "Miejsce: " + std::to_string(seat);
}


const Person& Ticket::getTicketHolder() const {
    return ticketHolder;
}

const std::string& Ticket::getSector() const {
    return sector;
}

int Ticket::getPlace() const {
    return seat;
}