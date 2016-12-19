
#include "qmlstandalone.h"
#include <QtWidgets/QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Hello World";
	QApplication a(argc, argv);
	QMLStandalone app;
	//app.setupUI();
	app.setupUI();
	//w.show();
	return a.exec();
}
