#pragma once

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <vector>
#include "Ticket.h"

class EventPage : public QWidget
{
    Q_OBJECT

public:
    explicit EventPage(QWidget* parent = nullptr);
    void setEventType(bool isConcert);

signals:
    void goBackToMainPage();

private slots:
    void addTicket();
    void loadTicketsFromFile();
    void saveTicketsToFile();
    void showTicketsList();
    void removeTicket();

private:
    void setupButtons();
    QPushButton* createStyledButton(const QString& text);
    bool isConcert;
    std::vector<Ticket*> tickets;
    QTableWidget* tableWidget;
};
