#include <QtCore>
#include <QtGui>
#include <QApplication>
#include <app/Application.h>
#include <app/MainWindow.h>

int main(int argc, char** argv) {
	Application app(argc, argv);

	auto mainWindow = new MainWindow;
	mainWindow->show();

	return app.exec();
}
