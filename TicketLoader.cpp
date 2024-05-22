#include "TicketLoader.h"
#include <QMessageBox>
#include <fstream>
#include <sstream>
#include "VIPTicket.h"
#include "NormalTicket.h"
#include "DiscountTicket.h"
#include <stdexcept>

TicketLoader::TicketLoader() {}

TicketLoader::~TicketLoader() {}

bool TicketLoader::loadTicketsFromFile(const QString& fileName, std::vector<Ticket*>& tickets) {
    try {
        std::ifstream file(fileName.toStdString());
        if (!file.is_open()) {
            throw std::runtime_error("Nie mozna otworzyc pliku");
        }

        if (file.peek() == std::ifstream::traits_type::eof()) {
            throw std::runtime_error("Plik jest pusty");
        }

        std::string line;
        while (std::getline(file, line)) {
            if (!processLine(line, tickets)) {
                continue;
            }
        }

        file.close();
        return true;
    }
    catch (const std::runtime_error& e) {
        QMessageBox::warning(nullptr, "Blad", e.what());
        return false;
    }
}

bool TicketLoader::processLine(const std::string& line, std::vector<Ticket*>& tickets) {
    std::istringstream iss(line);
    std::string name, surname, pesel, ticketType, sector;
    int age, place;

    if (!(iss >> name >> surname >> age >> pesel >> ticketType >> sector >> place)) {
        return false;
    }

    Person person(name, surname, age, pesel);
    Ticket* ticket = nullptr;

    if (ticketType == "VIP") {
        ticket = new VIPTicket(person, 400.0, sector, place);
    }
    else if (ticketType == "Normalny") {
        ticket = new NormalTicket(person, 120.0, sector, place);
    }
    else if (ticketType == "Ulgowy") {
        ticket = new DiscountTicket(person, 60.0, sector, place);
    }

    if (ticket) {
        tickets.push_back(ticket);
        return true;
    }

    return false;
}