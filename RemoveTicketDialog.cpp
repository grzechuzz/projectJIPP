#include "RemoveTicketDialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

RemoveTicketDialog::RemoveTicketDialog(QWidget* parent)
    : QDialog(parent), peselLineEdit(new QLineEdit(this))
{
    setWindowTitle("Usun bilet");

    QVBoxLayout* layout = new QVBoxLayout(this);

    QRegularExpression regExp("\\d{11}");
    peselLineEdit->setValidator(new QRegularExpressionValidator(regExp, this));
    peselLineEdit->setMaxLength(11);

    QLabel* label = new QLabel("Wpisz PESEL:", this);
    layout->addWidget(label);
    layout->addWidget(peselLineEdit);

    QPushButton* okButton = new QPushButton("OK", this);
    QPushButton* cancelButton = new QPushButton("Anuluj", this);

    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    layout->addLayout(buttonLayout);

    setLayout(layout);
}

QString RemoveTicketDialog::getPesel() const
{
    return peselLineEdit->text();
}
