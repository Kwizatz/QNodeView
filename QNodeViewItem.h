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
#ifndef QNODEVIEWITEM_H
#define QNODEVIEWITEM_H
#include "qwidget.h"
QT_BEGIN_NAMESPACE
class QNodeViewItem : public QWidget
{
    Q_OBJECT
public:
	QNodeViewItem(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~QNodeViewItem();
signals:
};
QT_END_NAMESPACE
#endif