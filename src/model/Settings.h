#pragma once
#include <QSettings>

class Settings
{
public:
	Settings();
	virtual ~Settings();

	QString getBooksPath() const;
	void setBooksPath(const QString& booksPath);

	QString getFavouriteBookPath() const;
	void setFavouriteBookPath(const QString& booksPath);

private:
	QSettings m_settings;
};