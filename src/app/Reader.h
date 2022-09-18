#pragma once
#include <QWidget>
#include <model/Book.h>

namespace Ui {
	class Reader;
}

class Reader : public QWidget
{
	Q_OBJECT
public:
	Reader(QWidget* parent, const Book& book);
	virtual ~Reader();

signals:
	void exit();

private:
	typedef QWidget super;
	Ui::Reader* m_ui;
	Book m_book;
};