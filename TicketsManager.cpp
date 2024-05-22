#include "TicketsManager.h"

TicketsManager::TicketsManager(QWidget* parent)
    : QMainWindow(parent),
    stackedWidget(new QStackedWidget(this)),
    mainPage(new MainPage(this)),
    eventPage(new EventPage(this))  // U¿ywamy jednego EventPage
{
    ui.setupUi(this);

    resize(1100, 1000);
    setStyleSheet("QMainWindow { background-image: url(:/TicketsManager/background.jpg); background-position: center; background-repeat: no-repeat; background-size: cover; }");

    connect(mainPage, &MainPage::event1Selected, this, &TicketsManager::openEventPage);
    connect(mainPage, &MainPage::event2Selected, this, &TicketsManager::openEventPage);

    connect(eventPage, &EventPage::goBackToMainPage, this, &TicketsManager::goBackToMainPage);

    stackedWidget->addWidget(mainPage);
    stackedWidget->addWidget(eventPage);

    setCentralWidget(stackedWidget);
}

void TicketsManager::openEventPage(bool isConcert)
{
    eventPage->setEventType(isConcert);  
    stackedWidget->setCurrentWidget(eventPage);
}

void TicketsManager::goBackToMainPage()
{
    stackedWidget->setCurrentWidget(mainPage);
}

TicketsManager::~TicketsManager()
{}
