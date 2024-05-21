#include "TicketsManager.h"

TicketsManager::TicketsManager(QWidget *parent)
    : QMainWindow(parent),
      stackedWidget(new QStackedWidget(this)),
      mainPage(new MainPage(this)),
      eventPage1(new EventPage(this)),
      eventPage2(new EventPage(this))
{
    ui.setupUi(this);

    resize(1100, 1000);
    setStyleSheet("QMainWindow { background-image: url(:/TicketsManager/background.jpg); background-position: center; background-repeat: no-repeat; background-size: cover; }");

    
    connect(mainPage, &MainPage::event1Selected, this, &TicketsManager::openEventPage1);
    connect(mainPage, &MainPage::event2Selected, this, &TicketsManager::openEventPage2);
    connect(eventPage1, &EventPage::goBackToMainPage, this, &TicketsManager::goBackToMainPage);
    connect(eventPage2, &EventPage::goBackToMainPage, this, &TicketsManager::goBackToMainPage);

    stackedWidget->addWidget(mainPage);
    stackedWidget->addWidget(eventPage1);
    stackedWidget->addWidget(eventPage2);

    setCentralWidget(stackedWidget);
}

void TicketsManager::openEventPage1()
{
    stackedWidget->setCurrentWidget(eventPage1);
}

void TicketsManager::openEventPage2()
{
    stackedWidget->setCurrentWidget(eventPage2);
}

void TicketsManager::goBackToMainPage()
{
    stackedWidget->setCurrentWidget(mainPage);
}

TicketsManager::~TicketsManager()
{}
