#pragma once

#include <QWidget>
#include <QLabel>

class MainPage : public QWidget
{
	Q_OBJECT

public:
	explicit MainPage(QWidget* parent = nullptr);

signals:
	void event1Selected();
	void event2Selected();

private:
	QLabel* createEventDesign(const QString& backgroundPath, const QString& eventText, void (MainPage::* slot)());
};

