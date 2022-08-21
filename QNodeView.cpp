/*
Copyright (C) 2017,2022 Rodrigo Jose Hernandez Cordoba

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "QNodeView.h"
#include <QMouseEvent>

void InitializeUI(QNodeView* nodeView)
{
	nodeView->setRenderHints(
		QPainter::Antialiasing |
		QPainter::TextAntialiasing |
		QPainter::SmoothPixmapTransform);
	nodeView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	nodeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	nodeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

QNodeView::QNodeView(QWidget * parent)  : QGraphicsView(parent)
{
	InitializeUI(this);
}

QNodeView::QNodeView(QGraphicsScene *scene, QWidget *parent) : QGraphicsView(scene, parent)
{
	InitializeUI(this);
}

QNodeView::~QNodeView() = default;

void QNodeView::mousePressEvent(QMouseEvent* event)
{
	switch(event->button())
	{
	case Qt::MiddleButton:
		middleMouseButtonPress(event);
		break;
	case Qt::LeftButton:
		rightMouseButtonPress(event);
		break;
	case Qt::RightButton:
		rightMouseButtonPress(event);
		break;
	default:
		QGraphicsView::mousePressEvent(event);
	}
}

void QNodeView::mouseReleaseEvent(QMouseEvent* event)
{
	switch(event->button())
	{
	case Qt::MiddleButton:
		middleMouseButtonRelease(event);
		break;
	case Qt::LeftButton:
		rightMouseButtonRelease(event);
		break;
	case Qt::RightButton:
		rightMouseButtonRelease(event);
		break;
	default:
		QGraphicsView::mouseReleaseEvent(event);
	}
}

void QNodeView::middleMouseButtonPress(QMouseEvent* event)
{
	QMouseEvent releaseEvent {
		QEvent::MouseButtonRelease,
		event->localPos(),
		event->screenPos(),
		Qt::LeftButton,
		Qt::NoButton,
		event->modifiers()
	};
	QGraphicsView::mouseReleaseEvent(&releaseEvent);
	setDragMode(QGraphicsView::ScrollHandDrag);
	QMouseEvent fakeEvent
	{
		event->type(),
		event->localPos(),
		event->screenPos(),
		Qt::LeftButton,
		event->buttons() | Qt::LeftButton, event->modifiers()
	};
	QGraphicsView::mousePressEvent(&fakeEvent);
}


void QNodeView::middleMouseButtonRelease(QMouseEvent* event)
{
	QMouseEvent fakeEvent
	{
		event->type(),
		event->localPos(),
		event->screenPos(),
		Qt::LeftButton,
		event->buttons() & ~Qt::LeftButton, event->modifiers()
	};
	QGraphicsView::mouseReleaseEvent(&fakeEvent);
	setDragMode(QGraphicsView::NoDrag);
}

void QNodeView::leftMouseButtonPress(QMouseEvent* event)
{
	QGraphicsView::mousePressEvent(event);
}
void QNodeView::leftMouseButtonRelease(QMouseEvent* event)
{
	QGraphicsView::mouseReleaseEvent(event);
}
void QNodeView::rightMouseButtonPress(QMouseEvent* event)
{
	QGraphicsView::mousePressEvent(event);
}
void QNodeView::rightMouseButtonRelease(QMouseEvent* event)
{
	QGraphicsView::mouseReleaseEvent(event);
}