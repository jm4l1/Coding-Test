TEMPLATE = app
TARGET = reader

QT += core gui widgets

INCLUDEPATH += src

SOURCES = \
	src/main.cpp \
	src/app/Application.cpp \
	src/app/MainWindow.cpp \
	src/app/BookList.cpp \
	src/app/BookListWidget.cpp \
	src/app/Reader.cpp \
	src/model/Settings.cpp \
	src/model/Book.cpp \
	src/model/BookManager.cpp \

HEADERS = \
	src/app/Application.h \
	src/app/MainWindow.h \
	src/app/BookList.h \
	src/app/BookListWidget.h \
	src/app/Reader.h \
	src/model/Settings.h \
	src/model/Book.h \
	src/model/BookManager.h \

FORMS += \
	src/app/BookList.ui \
	src/app/BookListWidget.ui \
	src/app/Reader.ui \
