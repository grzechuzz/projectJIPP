#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TicketsManager.h"

class TicketsManager : public QMainWindow
{
    Q_OBJECT

public:
    TicketsManager(QWidget *parent = nullptr);
    ~TicketsManager();

private:
    Ui::TicketsManagerClass ui;
};
