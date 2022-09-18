#include "Settings.h"

static const QString BOOKS_PATH = QLatin1String("books/path");
static const QString FAVOURITE_BOOK_PATH = QLatin1String("books/favourite");

Settings::Settings()
	: m_settings(QLatin1String("./settings.ini"), QSettings::IniFormat)
{}

Settings::~Settings()
{}

QString Settings::getBooksPath() const
{
	return m_settings.value(BOOKS_PATH).toString();
}

void Settings::setBooksPath(const QString& booksPath)
{
	m_settings.setValue(BOOKS_PATH, booksPath);
}

QString Settings::getFavouriteBookPath() const
{
	return m_settings.value(FAVOURITE_BOOK_PATH).toString();
}

void Settings::setFavouriteBookPath(const QString& booksPath)
{
	m_settings.setValue(FAVOURITE_BOOK_PATH, booksPath);
}
