#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <model/Book.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();
	virtual ~MainWindow();

private slots:
	void onOpenBook(const Book& book);
	void popView();

private:
	typedef QMainWindow super;

	QStackedWidget* m_stack;
};
