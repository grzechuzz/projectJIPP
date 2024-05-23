#pragma once

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include "Ticket.h"

class AddTicketDialog : public QDialog
{
    Q_OBJECT

public:
    AddTicketDialog(QWidget* parent = nullptr, bool isConcert = false);
    Ticket* getTicket() const;

private slots:
    void accept() override;
    void updateSectors();

private:
    QComboBox* ticketTypeComboBox;
    QComboBox* sectorComboBox;
    QLineEdit* nameLineEdit;
    QLineEdit* surnameLineEdit;
    QLineEdit* ageLineEdit;
    QLineEdit* peselLineEdit;
    QLineEdit* seatLineEdit;

    Ticket* createdTicket;
    bool isConcert;  
};
