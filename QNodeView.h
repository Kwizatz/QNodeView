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
#ifndef QNODEVIEW_H
#define QNODEVIEW_H
#include "qabstractitemview.h"
QT_BEGIN_NAMESPACE
class
#if 0
/*Q_GUI_EXPORT*/
Q_DECL_EXPORT
#endif
QNodeView : public QAbstractItemView
{
public:
	QNodeView(QWidget *parent = Q_NULLPTR);
	virtual ~QNodeView();
	QRect visualRect(const QModelIndex &) const override;
	void scrollTo(const QModelIndex &,QAbstractItemView::ScrollHint) override;
	QModelIndex indexAt(const QPoint &) const override;
	QModelIndex moveCursor(QAbstractItemView::CursorAction,Qt::KeyboardModifiers) override;
	int horizontalOffset(void) const override;
	int verticalOffset(void) const override;
	bool isIndexHidden(const QModelIndex &) const override;
	void setSelection(const QRect &,QItemSelectionModel::SelectionFlags) override;
	QRegion visualRegionForSelection(const QItemSelection &) const override;
	const QColor& backgroundColor() const;
	const QColor& primaryGridColor() const;
	const QColor& secondaryGridColor() const;
	void setBackgroundColor(const QColor& color);
	void setPrimaryGridColor(const QColor& color);
	void setSecondaryGridColor(const QColor& color);
protected:
	void paintEvent(QPaintEvent *event) override;
private:
	Q_OBJECT;
	Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor);
	Q_PROPERTY(QColor primaryGridColor READ primaryGridColor WRITE setPrimaryGridColor);
	Q_PROPERTY(QColor secondaryGridColor READ secondaryGridColor WRITE setSecondaryGridColor);
	QColor mBackgroundColor;
	QColor mPrimaryGridColor;
	QColor mSecondaryGridColor;
};
QT_END_NAMESPACE
#endif