#pragma once
#include "Book.h"
#include <QVector>

class BookManager
{
public:
	static QVector<Book> getBooks();
	static QString getBookContents(const Book& book);
	static void setFavouriteBook(const Book& book);
	static Book getFavouriteBook();
};
