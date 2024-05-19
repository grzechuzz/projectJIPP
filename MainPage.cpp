#include "MainPage.h"
#include <QPixmap>
#include <QVBoxLayout>
#include <QPushButton>

MainPage::MainPage(QWidget* parent)
	: QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->setContentsMargins(0, 60, 0, 20);
	mainLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

	QString eventText1 = "<h2 style='color:white;'>Ekstraliga 2025/2026</h2>"
		"<h1 style='color:white;'>TSK <img src=':/TicketsManager/tsk.png' width='30' height='20'/> vs. <img src=':/TicketsManager/zt.png' width='30' height='20'/> ZT</h1>"
		"<h3 style='color:white;'>04.09.2025 18:00 <span style='color:lightgray;'>STADION MIEJSKI - POZNAN</span></h3>";
	QLabel* match1 = createEventDesign(":/TicketsManager/event1.png", eventText1, &MainPage::event1Selected);
	mainLayout->addWidget(match1);

	mainLayout->addSpacing(40);

	QString eventText2 = "<h2 style='color:white;'>Sentio Tour</h2>"
		"<h1 style='color:white;'>Marcin Garrix Show <img src=':/TicketsManager/sentio.jpg' width='30' height='20'/></h1>"
		"<h3 style='color:white;'>10.11.2025 21:00 <span style='color:lightgray;'>TAURON ARENA KRAKOW</span></h3>";
	QLabel* match2 = createEventDesign(":/TicketsManager/event2.png", eventText2, &MainPage::event2Selected);
	mainLayout->addWidget(match2);
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