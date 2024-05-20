#pragma once

#include <QtWidgets/QMainWindow>
#include <QStackedWidget>
#include "ui_TicketsManager.h"
#include "MainPage.h"
#include "EventPage.h"

class TicketsManager : public QMainWindow
{
    Q_OBJECT

public:
    TicketsManager(QWidget *parent = nullptr);
    ~TicketsManager();
    
private slots:
    void openEventPage1();
    void openEventPage2();
    void goBackToMainPage();

private:
    Ui::TicketsManagerClass ui;
    QStackedWidget* stackedWidget;
    MainPage* mainPage;
    EventPage* eventPage1;
    EventPage* eventPage2;

};
