#pragma once

#include <QWidget>
#include <QPushButton>

class EventPage : public QWidget
{
	Q_OBJECT

public:
	explicit EventPage(QWidget* parent = nullptr);

signals:
	void goBackToMainPage();

private:
	void setupButtons();
	QPushButton* createStyledButton(const QString& text);

	void addTicket();

};

