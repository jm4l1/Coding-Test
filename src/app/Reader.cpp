#include "Reader.h"
#include "ui_Reader.h"
#include <model/BookManager.h>

Reader::Reader(QWidget* parent, const Book& book)
	: super(parent)
	, m_ui(new Ui::Reader)
	, m_book(book)
{
	m_ui->setupUi(this);
	m_ui->title->setText(book.getTitle());
	m_ui->textEdit->setReadOnly(true);
	m_ui->textEdit->document()->setHtml(BookManager::getBookContents(book));
	m_ui->textEdit->moveCursor(QTextCursor::Start);
	connect(m_ui->exitButton, &QPushButton::clicked, this, &Reader::exit);
}

Reader::~Reader()
{}
