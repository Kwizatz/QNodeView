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
#ifndef QNODEMODEL_H
#define QNODEMODEL_H
#include "qabstractitemmodel.h"
QT_BEGIN_NAMESPACE
class
#if 0
/*Q_GUI_EXPORT*/
Q_DECL_EXPORT
#endif
QNodeModel : public QAbstractItemModel
{
public:
	QNodeModel(QObject *parent = Q_NULLPTR);
	virtual ~QNodeModel();
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex &index) const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
	Q_OBJECT;
};
QT_END_NAMESPACE
#endif