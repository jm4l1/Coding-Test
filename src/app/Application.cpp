#include "Application.h"
#include <model/Settings.h>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

Application::Application(int &argc, char** argv)
	: super(argc, argv)
{
	super::setOrganizationName("Kobo");
	super::setOrganizationDomain("kobo.com");
	super::setApplicationName("Simple Reading App");

	Settings settings;
	QString booksPath = settings.getBooksPath();
	if (booksPath.isNull()) {
		QString dir = QFileDialog::getExistingDirectory(nullptr,QLatin1String("Select your books directory."),QLatin1String("./"),QFileDialog::ShowDirsOnly);
		if(booksPath.isEmpty())
		{
			QMessageBox missingDirectoryMessageBox(QMessageBox::Critical,QLatin1String("Book directory not chosen."),QLatin1String("No books directory chosen. Closing application."));
			QAbstractButton *okButton = missingDirectoryMessageBox.addButton("Ok", QMessageBox::ActionRole);
			connect(okButton, &QPushButton::clicked, this, &QCoreApplication::quit, Qt::QueuedConnection);
			missingDirectoryMessageBox.exec();
			qDebug() << "No books directory chosen. Closing application.";
			return;
		}
		settings.setBooksPath(booksPath);
	}
	qDebug() << "Book search path:" << booksPath;
}

Application::~Application()
{}
