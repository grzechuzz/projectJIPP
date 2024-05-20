#include "EventPage.h"
#include <QVBoxLayout>

EventPage::EventPage(QWidget* parent)
	: QWidget(parent)
{
    setupButtons();
}

void EventPage::setupButtons()
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QPushButton* addTicketButton = createStyledButton(QString::fromUtf8(u8"Dodaj bilet"));
    QPushButton* ticketDatabaseButton = createStyledButton(QString::fromUtf8(u8"Lista bilet\u00F3w"));
    QPushButton* loadFromFileButton = createStyledButton(QString::fromUtf8(u8"Wczytaj z pliku"));
    QPushButton* saveToFileButton = createStyledButton(QString::fromUtf8(u8"Zapisz do pliku"));
    QPushButton* backButton = createStyledButton(QString::fromUtf8(u8"Powr\u00F3t"));

    layout->addWidget(addTicketButton);
    layout->addWidget(ticketDatabaseButton);
    layout->addWidget(loadFromFileButton);
    layout->addWidget(saveToFileButton);
    layout->addWidget(backButton); 

    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(20); 

    setLayout(layout);
}


QPushButton* EventPage::createStyledButton(const QString& text) {
    QPushButton* button = new QPushButton(text, this);
    button->setFixedSize(250, 80); 
    button->setFont(QFont("Arial", 16, QFont::Bold)); 

    button->setStyleSheet(
        "QPushButton { "
        "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ff5733, stop:1 #c70039); " // Gradient t³a
        "color: white; "
        "border: 2px solid #900C3F; " // Obramowanie
        "border-radius: 20px; " // Zaokr¹glone rogi
        "padding: 10px; " // Padding wewnêtrzny
        "box-shadow: 5px 5px 15px #888888; " // Efekt cienia
        "}"
        "QPushButton:hover { "
        "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ff8d72, stop:1 #e40058); " // Gradient t³a przy najechaniu
        "}"
        "QPushButton:pressed { "
        "background-color: #900C3F; " // Kolor t³a przy naciœniêciu
        "}"
    );

    button->setCursor(Qt::PointingHandCursor); 

    return button;
}