#include "EventPage.h"
#include "AddTicketDialog.h"
#include "DiscountTicket.h"
#include "NormalTicket.h"
#include "VIPTicket.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QHeaderView>
#include <QDialog>
#include <QFileDialog>
#include <fstream>
#include <sstream>


EventPage::EventPage(QWidget* parent)
    : QWidget(parent), 
      isConcert(false),
      tableWidget(nullptr)
{
    setupButtons();
}

void EventPage::setupButtons()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QPushButton* addTicketButton = createStyledButton(QString::fromUtf8(u8"Dodaj bilet"));
    QPushButton* ticketListButton = createStyledButton(QString::fromUtf8(u8"Lista biletow"));
    QPushButton* loadFromFileButton = createStyledButton(QString::fromUtf8(u8"Wczytaj z pliku"));
    QPushButton* saveToFileButton = createStyledButton(QString::fromUtf8(u8"Zapisz do pliku"));
    QPushButton* backButton = createStyledButton(QString::fromUtf8(u8"Powrot"));

    connect(addTicketButton, &QPushButton::clicked, this, &EventPage::addTicket);
    connect(ticketListButton, &QPushButton::clicked, this, &EventPage::showTicketsList);
    connect(loadFromFileButton, &QPushButton::clicked, this, &EventPage::loadTicketsFromFile);
    connect(saveToFileButton, &QPushButton::clicked, this, &EventPage::saveTicketsToFile);
    connect(backButton, &QPushButton::clicked, this, &EventPage::goBackToMainPage);

    layout->addWidget(addTicketButton);
    layout->addWidget(ticketListButton);
    layout->addWidget(loadFromFileButton);
    layout->addWidget(saveToFileButton);
    layout->addWidget(backButton);

    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(20);

    setLayout(layout);
}

void EventPage::setEventType(bool isConcert)
{
    this->isConcert = isConcert;
}

QPushButton* EventPage::createStyledButton(const QString& text)
{
    QPushButton* button = new QPushButton(text, this);
    button->setFixedSize(250, 80);
    button->setFont(QFont("Arial", 16, QFont::Bold));

    button->setStyleSheet(
        "QPushButton { "
        "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ff5733, stop:1 #c70039); "
        "color: white; "
        "border: 2px solid #900C3F; "
        "border-radius: 20px; "
        "padding: 10px; "
        "box-shadow: 5px 5px 15px #888888; "
        "}"
        "QPushButton:hover { "
        "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ff8d72, stop:1 #e40058); "
        "}"
        "QPushButton:pressed { "
        "background-color: #900C3F; "
        "}"
    );

    button->setCursor(Qt::PointingHandCursor);

    return button;
}

void EventPage::addTicket()
{
    AddTicketDialog dialog(this, isConcert);
    if (dialog.exec() == QDialog::Accepted) {
        Ticket* ticket = dialog.getTicket();
        if (ticket) {
            tickets.push_back(ticket);
            const Person& holder = ticket->getTicketHolder();
            QMessageBox::information(this, "Bilet dodany", "Dodano bilet dla " + QString::fromStdString(holder.getName()) + " " + QString::fromStdString(holder.getSurname()));
        }
    }
}

void EventPage::showTicketsList()
{
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Lista biletow");
    dialog->resize(800, 600);

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QTableWidget* tableWidget = new QTableWidget(dialog);
    tableWidget->setColumnCount(6); 
    tableWidget->setHorizontalHeaderLabels({ "Imie", "Nazwisko", "PESEL", "Wiek", "Typ biletu", "Opis biletu" });
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    tableWidget->setRowCount(tickets.size());

    for (int i = 0; i < tickets.size(); ++i) {
        const Ticket* ticket = tickets[i];
        const Person& holder = ticket->getTicketHolder();

        tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(holder.getName())));
        tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(holder.getSurname())));
        tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(holder.getPesel())));
        tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(holder.getAge())));

        QString ticketType;
        if (dynamic_cast<const DiscountTicket*>(ticket)) {
            ticketType = "Ulgowy";
        }
        else if (dynamic_cast<const NormalTicket*>(ticket)) {
            ticketType = "Normalny";
        }
        else if (dynamic_cast<const VIPTicket*>(ticket)) {
            ticketType = "VIP";
        }

        tableWidget->setItem(i, 4, new QTableWidgetItem(ticketType));
        QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(ticket->showInfo()));
        item->setTextAlignment(Qt::AlignTop | Qt::AlignLeft);
        tableWidget->setItem(i, 5, item);
    }

    tableWidget->resizeColumnsToContents();
    tableWidget->resizeRowsToContents();

    layout->addWidget(tableWidget);
    dialog->setLayout(layout);
    dialog->exec();
}

void EventPage::loadTicketsFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Wybierz plik", "", "Pliki tekstowe (*.txt);;Wszystkie pliki (*.*)");
    if (fileName.isEmpty()) {
        return;
    }

    std::ifstream file(fileName.toStdString());
    if (!file.is_open()) {
        QMessageBox::warning(this, "Blad", "Nie mozna otworzyc pliku");
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, surname, pesel, ticketType;
        int age;

        if (!(iss >> name >> surname >> age >> pesel >> ticketType)) {
            continue; 
        }

        Person person(name, surname, age, pesel);
        Ticket* ticket = nullptr;

        if (ticketType == "VIP") {
            ticket = new VIPTicket(person, 400.0, "unknown", 0);
        }
        else if (ticketType == "Normalny") {
            ticket = new NormalTicket(person, 120.0, "unknown", 0);
        }
        else if (ticketType == "Ulgowy") {
            ticket = new DiscountTicket(person, 60.0, "unknown", 0);
        }

        if (ticket) {
            tickets.push_back(ticket);
        }
    }

    file.close();
    QMessageBox::information(this, "Wczytano bilety", "Bilety zostaly wczytane z pliku.");
}

void EventPage::saveTicketsToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Zapisz plik", "", "Pliki tekstowe (*.txt);;Wszystkie pliki (*.*)");
    if (fileName.isEmpty()) {
        return;
    }

    std::ofstream file(fileName.toStdString());
    if (!file.is_open()) {
        QMessageBox::warning(this, "Blad", "Nie mozna zapisac pliku");
        return;
    }

    for (const Ticket* ticket : tickets) {
        const Person& holder = ticket->getTicketHolder();
        std::string ticketType;

        if (dynamic_cast<const VIPTicket*>(ticket)) {
            ticketType = "VIP";
        }
        else if (dynamic_cast<const NormalTicket*>(ticket)) {
            ticketType = "Normalny";
        }
        else if (dynamic_cast<const DiscountTicket*>(ticket)) {
            ticketType = "Ulgowy";
        }

        file << holder.getName() << " "
            << holder.getSurname() << " "
            << holder.getAge() << " "
            << holder.getPesel() << " "
            << ticketType << "\n";
    }

    file.close();
    QMessageBox::information(this, "Zapisano bilety", "Bilety zostaly zapisane do pliku.");
}