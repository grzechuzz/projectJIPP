#pragma once

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

class AddTicketDialog : public QDialog
{
	Q_OBJECT

public:
	AddTicketDialog(QWidget* parent = nullptr);

private:
	QComboBox* ticketTypeComboBox;
	QLineEdit* nameLineEdit;
	QLineEdit* surnameLineEdit;
	QLineEdit* ageLineEdit;
	QLineEdit* peselLineEdit;
	QLineEdit* sectorLineEdit;
	QLineEdit* seatLineEdit;
};

