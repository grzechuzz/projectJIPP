#include "AddTicketDialog.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

AddTicketDialog::AddTicketDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Dodaj bilet");

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    ticketTypeComboBox = new QComboBox(this);
    ticketTypeComboBox->addItem("Ulgowy");
    ticketTypeComboBox->addItem("Normalny");
    ticketTypeComboBox->addItem("VIP");

    nameLineEdit = new QLineEdit(this);
    surnameLineEdit = new QLineEdit(this);
    ageLineEdit = new QLineEdit(this);
    peselLineEdit = new QLineEdit(this);
    sectorLineEdit = new QLineEdit(this);
    seatLineEdit = new QLineEdit(this);

    QRegularExpression regExp("\\d{11}");
    peselLineEdit->setValidator(new QRegularExpressionValidator(regExp, this));
    peselLineEdit->setMaxLength(11);

    QRegularExpression ageRegExp("\\d{1,3}"); 
    ageLineEdit->setValidator(new QRegularExpressionValidator(ageRegExp, this));

    QRegularExpression seatRegExp("\\d{1,4}"); 
    seatLineEdit->setValidator(new QRegularExpressionValidator(seatRegExp, this));

    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Typ biletu:", ticketTypeComboBox);
    formLayout->addRow("Imie:", nameLineEdit);
    formLayout->addRow("Nazwisko:", surnameLineEdit);
    formLayout->addRow("Wiek:", ageLineEdit);
    formLayout->addRow("PESEL:", peselLineEdit);
    formLayout->addRow("Sektor:", sectorLineEdit);
    formLayout->addRow("Miejsce:", seatLineEdit);

    mainLayout->addLayout(formLayout);

    QPushButton* addButton = new QPushButton("Dodaj", this);
    mainLayout->addWidget(addButton);

    setFixedSize(400, 250);
}
