#include "BookManager.h"
#include "Settings.h"
#include <QDir>
#include <QDebug>
#include <QRegularExpression>

static Book bookFromEntry(const QFileInfo& entry)
{
	Book book;
	book.setPath(entry.absoluteFilePath());

	auto contents = BookManager::getBookContents(book);

	QRegularExpression titleRegex(QLatin1String("<h1>(.*)</h1>"));
	auto match = titleRegex.match(contents);
	if (match.hasMatch()) {
		book.setTitle(match.captured(1));
	} else {
		book.setTitle(entry.fileName());
	}

	return book;
}

QVector<Book> BookManager::getBooks()
{
	Settings settings;
	QDir booksDir(settings.getBooksPath(), QLatin1String("*.html"));
	auto entries = booksDir.entryInfoList(QDir::Files);
	QVector<Book> books;
	foreach (const QFileInfo& entry, entries) {
		auto book = bookFromEntry(entry);
		qDebug() << "BookManager::getBooks()" << book.getPath() << book.getTitle();
		books << book;
	}
	return books;
}

QString BookManager::getBookContents(const Book& book)
{
	QFile file(book.getPath());
	file.open(QIODevice::ReadOnly);
	return QString::fromUtf8(file.readAll());
}

void BookManager::setFavouriteBook(const Book& book)
{
	Settings settings;
	settings.setFavouriteBookPath(book.getPath());
}

Book BookManager::getFavouriteBook()
{
	Settings settings;
	QString booksDir = settings.getBooksPath();
	QString favoriteBookPath = settings.getFavouriteBookPath();
	QString favoriteBookTitle = settings.getFavouriteBookPath().remove(booksDir + "/");
	return Book(favoriteBookPath,favoriteBookTitle );
}