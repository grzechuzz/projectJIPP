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
	AddTicketDialog(QWidget* parent = nullptr);
	Ticket* getTicket() const;

private slots:
	void accept() override;

private:
	QComboBox* ticketTypeComboBox;
	QLineEdit* nameLineEdit;
	QLineEdit* surnameLineEdit;
	QLineEdit* ageLineEdit;
	QLineEdit* peselLineEdit;
	QLineEdit* sectorLineEdit;
	QLineEdit* seatLineEdit;

	Ticket* createdTicket;
};

