#include "BookListWidget.h"
#include "ui_BookListWidget.h"

BookListWidget::BookListWidget(QWidget* parent)
	: super(parent)
	, m_ui(new Ui::BookListWidget)
{
	m_ui->setupUi(this);
	setFixedHeight(50);
	connect(m_ui->openButton, &QPushButton::clicked, this, &BookListWidget::onOpenPressed);
	connect(m_ui->favouriteButton, &QPushButton::clicked, this, &BookListWidget::onFavouritePressed);
}

BookListWidget::~BookListWidget()
{}

void BookListWidget::onOpenPressed()
{
	emit openBook(m_book);
}

void BookListWidget::onFavouritePressed()
{
	emit favourited(m_book);
}

void BookListWidget::setContent(const Book& book, bool isFavourite)
{
	m_book = book;
	QString title = m_book.getTitle();
	if (isFavourite) {
		title = QString::fromUtf8("★ ") + title;
	}
	m_ui->favouriteButton->setVisible(!isFavourite);
	m_ui->title->setText(title);
}
