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
#include "QNodeItemView.hpp"

QRect QNodeItemView::visualRect(const QModelIndex &) const
{
	return QRect(0,0,100,50);
}

void QNodeItemView::scrollTo(const QModelIndex &, QAbstractItemView::ScrollHint)
{
}

QModelIndex QNodeItemView::indexAt(const QPoint &) const
{
	return QModelIndex();
}

QModelIndex QNodeItemView::moveCursor(QAbstractItemView::CursorAction, Qt::KeyboardModifiers)
{
	return QModelIndex();
}

int QNodeItemView::horizontalOffset(void) const
{
	return 0;
}

int QNodeItemView::verticalOffset(void) const
{
	return 0;
}

bool QNodeItemView::isIndexHidden(const QModelIndex &) const
{
	return false;
}

void QNodeItemView::setSelection(const QRect &, QItemSelectionModel::SelectionFlags)
{
}

QRegion QNodeItemView::visualRegionForSelection(const QItemSelection &) const
{
	return QRegion(0,0,100,50);
}
