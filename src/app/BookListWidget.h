#pragma once
#include <QFrame>
#include <QWidget>
#include <model/Book.h>

namespace Ui {
	class BookListWidget;
}

class BookListWidget : public QFrame
{
	Q_OBJECT
public:
	BookListWidget(QWidget* parent);
	virtual ~BookListWidget();

	void setContent(const Book& book, bool isFavourite);

private slots:
	void onOpenPressed();
	void onFavouritePressed();

signals:
	void openBook(const Book& book);
	void favourited(const Book& book);

private:
	typedef QFrame super;
	Ui::BookListWidget* m_ui;
	Book m_book;
};