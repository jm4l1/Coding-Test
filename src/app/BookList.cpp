#include "BookList.h"
#include "ui_BookList.h"
#include "BookListWidget.h"
#include <model/BookManager.h>
#include <model/Settings.h>

BookList::BookList(QWidget* parent)
	: super(parent)
	, m_ui(new Ui::BookList)
{
	m_ui->setupUi(this);
	refresh();
	connect(m_ui->refreshButton, &QPushButton::clicked, this, &BookList::refresh);
	connect(m_ui->openFavouriteButton, &QPushButton::clicked, this, &BookList::openFavourite);
}

BookList::~BookList()
{}

void BookList::refresh()
{
	QLayoutItem *child;
	while ((child = m_ui->bookLayout->takeAt(0)) != nullptr) {
		child->widget()->deleteLater();
		delete child;
	}

	Settings settings;
	m_books = BookManager::getBooks();
	foreach (const Book& book, m_books) {
		auto bookWidget = new BookListWidget(this);
		bool isFavourite = (book.getPath() == settings.getFavouriteBookPath());
		bookWidget->setContent(book, isFavourite);
		m_ui->bookLayout->addWidget(bookWidget);
		connect(bookWidget, &BookListWidget::openBook, this, &BookList::openBook);
		connect(bookWidget, &BookListWidget::favourited, this, &BookList::setFavourite);
	}
}

void BookList::setFavourite(const Book& book)
{
	BookListWidget* widget = qobject_cast<BookListWidget*>(sender());
	widget->setContent(book, true);
	BookManager::setFavouriteBook(book);
}

void BookList::openFavourite()
{
	auto book = BookManager::getFavouriteBook();
	emit openBook(book);
}
