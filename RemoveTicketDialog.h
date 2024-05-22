#pragma once

#include <QDialog>
#include <QLineEdit>

class RemoveTicketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveTicketDialog(QWidget* parent = nullptr);
    QString getPesel() const;

private:
    QLineEdit* peselLineEdit;
};