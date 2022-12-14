#pragma once
#include <QWidget>
#include <model/Book.h>

namespace Ui 
{
	class BookList;
}

class BookList : public QWidget
{
	Q_OBJECT
public:
	BookList(QWidget* parent = nullptr);
	virtual ~BookList();

private:
	void updateUi();
	
private slots:
	void refresh();

	void setFavourite(const Book& book);
	void openFavourite();
	void setBookPath();

signals:
	void openBook(const Book& book);

private:
	typedef QWidget super;
	Ui::BookList* m_ui;
	QVector<Book> m_books;
};