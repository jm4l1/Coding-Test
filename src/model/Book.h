#pragma once
#include <QString>

class Book
{
public:
	Book();
	Book(const QString& path, const QString& title);
	virtual ~Book();

	void setPath(const QString& path);
	QString getPath() const;

	void setTitle(const QString& title);
	QString getTitle() const;

private:
	QString m_path;
	QString m_title;
};
