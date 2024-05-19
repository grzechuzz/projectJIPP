#include "TicketsManager.h"

TicketsManager::TicketsManager(QWidget *parent)
    : QMainWindow(parent),
      stackedWidget(new QStackedWidget(this)),
      mainPage(new MainPage(this))
{
    ui.setupUi(this);

    resize(1100, 1000);
    setStyleSheet("QMainWindow { background-image: url(:/TicketsManager/background.jpg); background-position: center; background-repeat: no-repeat; background-size: cover; }");

    stackedWidget->addWidget(mainPage);

    setCentralWidget(stackedWidget);
}

TicketsManager::~TicketsManager()
{}
