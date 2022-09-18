#include "Application.h"
#include <model/Settings.h>
#include <QFileDialog>
#include <QDebug>

Application::Application(int &argc, char** argv)
	: super(argc, argv)
{
	super::setOrganizationName("Kobo");
	super::setOrganizationDomain("kobo.com");
	super::setApplicationName("Simple Reading App");

	Settings settings;
	QString booksPath = settings.getBooksPath();
	if (booksPath.isNull()) {
		QFileDialog picker(nullptr, QLatin1String("Select your books directory."), QLatin1String("./"));
		picker.setFileMode(QFileDialog::Directory);
		picker.setOptions(QFileDialog::ShowDirsOnly);
		picker.exec();
		booksPath = picker.directory().absolutePath();
		settings.setBooksPath(booksPath);
	}
	qDebug() << "Book search path:" << booksPath;
}

Application::~Application()
{}
