#include "EventPage.h"
#include "AddTicketDialog.h"
#include <QVBoxLayout>
#include <QMessageBox>

EventPage::EventPage(QWidget* parent)
    : QWidget(parent), isConcert(false)
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
