#pragma once

#include <QWidget>
#include <QPushButton>
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

private:
    void setupButtons();
    QPushButton* createStyledButton(const QString& text);
    bool isConcert;
    std::vector<Ticket*> tickets;
};
