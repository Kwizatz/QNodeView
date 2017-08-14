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
#ifndef QNODEITEMVIEW_HPP
#define QNODEITEMVIEW_HPP
#include <QAbstractItemView>
QT_BEGIN_NAMESPACE
class
#if 0
/*Q_GUI_EXPORT*/
Q_DECL_EXPORT
#endif
QNodeItemView : public QAbstractItemView
{
public:
	QRect visualRect(const QModelIndex &) const override;
	void scrollTo(const QModelIndex &,QAbstractItemView::ScrollHint) override;
	QModelIndex indexAt(const QPoint &) const override;
	QModelIndex moveCursor(QAbstractItemView::CursorAction,Qt::KeyboardModifiers) override;
	int horizontalOffset(void) const override;
	int verticalOffset(void) const override;
	bool isIndexHidden(const QModelIndex &) const override;
	void setSelection(const QRect &,QItemSelectionModel::SelectionFlags) override;
	QRegion visualRegionForSelection(const QItemSelection &) const override;
private:
	Q_OBJECT;
};
QT_END_NAMESPACE
#endif