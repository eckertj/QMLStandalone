#include "MainWindow.h"


MainWindow::MainWindow(QWindow *parent, QQmlEngine* qmlEngine)
	: QQuickView(qmlEngine, parent)
{
	setResizeMode(QQuickView::ResizeMode::SizeRootObjectToView);
	setGeometry(10, 10, 1600, 980);
	setObjectName(QStringLiteral("theMainWindow"));
	setColor(QColor(0, 0, 0));
	setTitle(QCoreApplication::applicationName());

	if (!qmlEngine)
	{
		QQmlEngine* qmlEngine(new QQmlEngine);
	}

	connect(qmlEngine, SIGNAL(quit()), QCoreApplication::instance(), SLOT(quit()));
	connect(this, &QQuickWindow::sceneGraphInitialized, this, &MainWindow::handleSceneGraphInitialized);
}


MainWindow::~MainWindow()
{
}


void MainWindow::handleSceneGraphInitialized()
{
	QApplication::processEvents();
	setSource(QUrl::fromLocalFile("main.qml"));
	if (status() == QQuickView::Error)
	{
		QList<QQmlError>errList = errors();
		for each (QQmlError error in errList)
		{
			qDebug() << "QML: " << error.toString();
		}
	}
}

bool MainWindow::eventFilter(QObject* obj, QEvent* e)
{

	bool ok = QObject::eventFilter(obj, e);
	if (e->type() == QEvent::UpdateRequest)
	{
		// update the quick view when the display was updated
		update();
	}
	return ok;

}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
	//if (event->key() == Qt::Key_F12){
	//	if (windowState() != Qt::WindowMaximized){
	//		showMaximized();
	//	}
	//	else{
	//		showFullScreen();
	//	}
	//}

	//if (pi::ModuleManager::getInstance()->handleKeyPress(Qt::Key(event->key()))){
	//	return;
	//}

	QQuickView::keyPressEvent(event);
}