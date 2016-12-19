#pragma once

#include <QtQuick>
#include <QQuickPaintedItem>

class DummyView : public QQuickPaintedItem
{
	Q_OBJECT
	Q_PROPERTY(bool cool READ isCool WRITE setCool NOTIFY coolChanged)

public:
	DummyView(QQuickItem * parent = 0);
	~DummyView();

	void paint(QPainter *painter);

	bool isCool();
	void setCool(bool rightAligned);

private:
	bool cool;


signals:
	void coolChanged();

};

