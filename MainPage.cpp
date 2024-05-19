#include "MainPage.h"
#include <QPixmap>
#include <QVBoxLayout>
#include <QPushButton>

MainPage::MainPage(QWidget* parent)
	: QWidget(parent)
{

}


QLabel* MainPage::createEventDesign(const QString& backgroundPath, const QString& eventText, void (MainPage::* slot)())
{
	QLabel* backgroundLabel = new QLabel(this);
	backgroundLabel->setPixmap(QPixmap(backgroundPath));
	backgroundLabel->setFixedSize(800, 400);
	backgroundLabel->setScaledContents(true);

	QWidget* eventDesignWidget = new QWidget(backgroundLabel);
	eventDesignWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0.5); border-radius: 10px;");
	eventDesignWidget->setGeometry(0, 0, 800, 400);

	QVBoxLayout* eventLayout = new QVBoxLayout(eventDesignWidget);
	eventLayout->setContentsMargins(20, 20, 20, 20);
	eventLayout->setAlignment(Qt::AlignCenter);

	QLabel* eventLabel = new QLabel(eventDesignWidget);
	eventLabel->setText(eventText);
	eventLabel->setAlignment(Qt::AlignCenter);
	eventLabel->setStyleSheet("background-color: rgba(0, 0, 0, 0.7); padding: 10px; border-radius: 10px;");

	QPushButton* addButton = new QPushButton("WYBIERZ", eventDesignWidget);
	addButton->setStyleSheet("background-color: red; color: white; padding: 10px 20px; font-size: 18px; border: none; border-radius: 5px;");
	addButton->setCursor(Qt::PointingHandCursor);

	connect(addButton, &QPushButton::clicked, this, slot);

	eventLayout->addWidget(eventLabel);
	eventLayout->addSpacing(10);
	eventLayout->addWidget(addButton, 0, Qt::AlignCenter);

	return backgroundLabel;
}