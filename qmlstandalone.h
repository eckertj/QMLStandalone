#ifndef QMLSTANDALONE_H
#define QMLSTANDALONE_H

#include "MainWindow.h"
#include <QObject>

class QQmlEngine;

class QMLStandalone : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString number READ getNumber WRITE setNumber NOTIFY numberChanged)

public:

	/// constructor
	QMLStandalone();

	/// destructor
	~QMLStandalone();

	/// @brief Returns the applications qml engine
	/// @details If needed, all objects should get this qml Engine, e.g. if they need
	/// @details register an qml property etc 
	QQmlEngine* getQmlEngine();

	/// Returns the applications main window/widget
	MainWindow* getMainWindow();

	/// Starts the graphical user interface
	void setupUI();

	void setNumber(QString const &number);
	QString getNumber();

signals:
	void numberChanged();

private:
	static QMLStandalone	* s_instance;		///< The global static instance
	MainWindow				* m_mainWindow;		///< The main window
	QQmlEngine				* m_qmlEngine;		///< The qml engine 
	QString					m_number;
};

#endif // QMLSTANDALONE_H
