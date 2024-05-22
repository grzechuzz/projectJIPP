#include "Ticket.h"

Ticket::Ticket(const Person& ticketHolder, double price, const std::string& sector, int seat)
    : ticketHolder(ticketHolder), price(price), sector(sector), seat(seat) {}

std::string Ticket::showInfo() const {
    return "W³aœciciel biletu: " + ticketHolder.getName() + " " + ticketHolder.getSurname() + "\n" +
        "Cena: " + std::to_string(price) + "\n" +
        "Sektor: " + sector + "\n" +
        "Miejsce: " + std::to_string(seat);
}

const Person& Ticket::getTicketHolder() const {
    return ticketHolder;
}