#include "DummyView.h"


DummyView::DummyView(QQuickItem *parent) : 
QQuickPaintedItem(parent),
cool(false)
{
}


DummyView::~DummyView()
{
}


void DummyView::paint(QPainter *painter)
{
	setFillColor(QColor("#00ff00"));
}


bool DummyView::isCool()
{
	return this->cool;
}

void DummyView::setCool(bool cool)
{
	this->cool = cool;
} 