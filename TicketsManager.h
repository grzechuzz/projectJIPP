#pragma once

#include <QtWidgets/QMainWindow>
#include <QStackedWidget>
#include "ui_TicketsManager.h"
#include "MainPage.h"

class TicketsManager : public QMainWindow
{
    Q_OBJECT

public:
    TicketsManager(QWidget *parent = nullptr);
    ~TicketsManager();

private:
    Ui::TicketsManagerClass ui;
    QStackedWidget* stackedWidget;
    MainPage* mainPage;
};
