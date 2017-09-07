/*
Copyright (C) 2017 Rodrigo Jose Hernandez Cordoba

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
#include <QPainter>
#include <QLabel>
#include "QNodeView.h"
#include "QNodeViewItem.h"

QNodeView::QNodeView(QWidget * parent, Qt::WindowFlags f)
{
	QNodeViewItem *label = new QNodeViewItem(this);
	label->move(10, 10);
	label->show();
	label->setAttribute(Qt::WA_DeleteOnClose);
}

QNodeView::~QNodeView()
{
}

QRect QNodeView::visualRect(const QModelIndex &) const
{
	return QRect(0,0,0,0);
}

void QNodeView::scrollTo(const QModelIndex &, QAbstractItemView::ScrollHint)
{
}

QModelIndex QNodeView::indexAt(const QPoint &) const
{
	return QModelIndex();
}

QModelIndex QNodeView::moveCursor(QAbstractItemView::CursorAction, Qt::KeyboardModifiers)
{
	return QModelIndex();
}

int QNodeView::horizontalOffset(void) const
{
	return 0;
}

int QNodeView::verticalOffset(void) const
{
	return 0;
}

bool QNodeView::isIndexHidden(const QModelIndex &) const
{
	return false;
}

void QNodeView::setSelection(const QRect &, QItemSelectionModel::SelectionFlags)
{
}

QRegion QNodeView::visualRegionForSelection(const QItemSelection &) const
{
	return QRegion(0,0,0,0);
}

void QNodeView::paintEvent(QPaintEvent * event)
{
	QWidget::paintEvent(event);
	QPainter(this);
}
