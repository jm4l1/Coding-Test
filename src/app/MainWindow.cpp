#include "MainWindow.h"
#include "BookList.h"
#include "Reader.h"
#include <QDebug>

MainWindow::MainWindow()
	: super()
{
	setFixedSize(QSize(600, 800));

	m_stack = new QStackedWidget;
	setCentralWidget(m_stack);

	auto bookList = new BookList;
	m_stack->addWidget(bookList);
	connect(bookList, &BookList::openBook, this, &MainWindow::onOpenBook);
}

MainWindow::~MainWindow()
{}

void MainWindow::onOpenBook(const Book& book)
{
	auto reader = new Reader(this, book);
	connect(reader, &Reader::exit, this, &MainWindow::popView);
	m_stack->addWidget(reader);
	m_stack->setCurrentWidget(reader);
}

void MainWindow::popView()
{
	auto currentWidget = m_stack->currentWidget();
	m_stack->removeWidget(currentWidget);
	currentWidget->deleteLater();
}
