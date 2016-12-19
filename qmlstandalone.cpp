#include "qmlstandalone.h"
#include "DummyView.h"


QMLStandalone::QMLStandalone() :
m_qmlEngine(new QQmlEngine),
m_mainWindow(0)
{
	setNumber("99");
	qmlRegisterType<DummyView>("DummyViews", 1, 0, "DummyView");
	m_qmlEngine->rootContext()->setContextProperty("backendController", this);
}

QMLStandalone::~QMLStandalone()
{
	delete m_mainWindow;
}


void QMLStandalone::setupUI()
{
	m_mainWindow = new MainWindow(0, m_qmlEngine);
	m_mainWindow->showMaximized();
}

void QMLStandalone::setNumber(QString const &number) {
	m_number = number;
}

QString QMLStandalone::getNumber() {
	return m_number;
}