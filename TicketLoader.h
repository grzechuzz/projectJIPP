#pragma once

#include <QString>
#include <vector>
#include "Ticket.h"

class TicketLoader {
public:
    TicketLoader();
    ~TicketLoader();

    bool loadTicketsFromFile(const QString& fileName, std::vector<Ticket*>& tickets);

private:
    bool processLine(const std::string& line, std::vector<Ticket*>& tickets);
};
