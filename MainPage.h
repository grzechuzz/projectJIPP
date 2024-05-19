#pragma once

#include <QWidget>
#include <QLabel>

class MainPage : public QWidget
{
	Q_OBJECT

public:
	explicit MainPage(QWidget* parent = nullptr);

private:
	QLabel* createEventDesign(const QString& backgroundPath, const QString& eventText, void (MainPage::* slot)());
};

