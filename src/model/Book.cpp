#include "Book.h"

Book::Book()
{}

Book::~Book()
{}

void Book::setPath(const QString& path)
{
	m_path = path;
}

QString Book::getPath() const
{
	return m_path;
}

void Book::setTitle(const QString& title)
{
	m_title = title;
}

QString Book::getTitle() const
{
	return m_title;
}
