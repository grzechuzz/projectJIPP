#include "AddTicketDialog.h"
#include "NormalTicket.h"
#include "DiscountTicket.h"
#include "VIPTicket.h"
#include "AgeException.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

AddTicketDialog::AddTicketDialog(QWidget* parent, bool isConcert)
    : QDialog(parent), createdTicket(nullptr), isConcert(isConcert)
{
    setWindowTitle("Dodaj bilet");

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    ticketTypeComboBox = new QComboBox(this);
    ticketTypeComboBox->addItem("Ulgowy");
    ticketTypeComboBox->addItem("Normalny");
    ticketTypeComboBox->addItem("VIP");
    connect(ticketTypeComboBox, &QComboBox::currentTextChanged, this, &AddTicketDialog::updateSectors);

    sectorComboBox = new QComboBox(this);

    nameLineEdit = new QLineEdit(this);
    surnameLineEdit = new QLineEdit(this);
    ageLineEdit = new QLineEdit(this);
    peselLineEdit = new QLineEdit(this);
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
    formLayout->addRow("Sektor:", sectorComboBox);
    formLayout->addRow("Miejsce:", seatLineEdit);

    mainLayout->addLayout(formLayout);

    QPushButton* addButton = new QPushButton("Dodaj", this);
    connect(addButton, &QPushButton::clicked, this, &AddTicketDialog::accept);
    mainLayout->addWidget(addButton);

    setFixedSize(400, 300);

    updateSectors(); 
}

void AddTicketDialog::updateSectors()
{
    QString ticketType = ticketTypeComboBox->currentText();
    sectorComboBox->clear();

    if (isConcert) {
        if (ticketType == "VIP") {
            sectorComboBox->addItems({ "B", "D", "F", "H", "GroundVIP" });
        }
        else {
            sectorComboBox->addItems({ "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "Ground" });
        }
    }
    else {
        if (ticketType == "VIP") {
            sectorComboBox->addItems({ "B", "D", "F", "H" });
        }
        else {
            sectorComboBox->addItems({ "A", "B", "C", "D", "E", "F", "G", "H", "I", "J" });
        }
    }
}

void AddTicketDialog::accept()
{
    QString name = nameLineEdit->text();
    QString surname = surnameLineEdit->text();
    int age = ageLineEdit->text().toInt();
    QString pesel = peselLineEdit->text();
    QString sector = sectorComboBox->currentText();
    int seat = seatLineEdit->text().toInt();

    if (pesel.length() != 11) {
        QMessageBox::warning(this, "Blad", "PESEL musi miec dokladnie 11 cyfr.");
        return;
    }

    try {
        if (ticketTypeComboBox->currentText() == "VIP" && age < 18) {
            throw AgeException("Bilet VIP przeznaczony tylko dla pelnoletnich.");
        }

        Person person(name.toStdString(), surname.toStdString(), age, pesel.toStdString());
        std::string ticketType = ticketTypeComboBox->currentText().toStdString();

        if (ticketType == "Ulgowy") {
            createdTicket = new DiscountTicket(person, 60.0, sector.toStdString(), seat);
        }
        else if (ticketType == "Normalny") {
            createdTicket = new NormalTicket(person, 120.0, sector.toStdString(), seat);
        }
        else if (ticketType == "VIP") {
            createdTicket = new VIPTicket(person, 400.0, sector.toStdString(), seat);
        }

        QDialog::accept();
    }
    catch (const AgeException& e) {
        QMessageBox::warning(this, "Blad", e.what());
    }


    QDialog::accept();
}

Ticket* AddTicketDialog::getTicket() const
{
    return createdTicket;
}
