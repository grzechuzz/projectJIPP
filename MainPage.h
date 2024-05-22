#pragma once

#include <QWidget>
#include <QLabel>

class MainPage : public QWidget
{
	Q_OBJECT

public:
	explicit MainPage(QWidget* parent = nullptr);

signals:
	void event1Selected(bool isConcert);
	void event2Selected(bool isConcert);

private:
	QLabel* createEventDesign(const QString& backgroundPath, const QString& eventText, bool isConcert, void (MainPage::* slot)(bool));
};

