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
#ifndef QNODEVIEWITEMSOCKET_H
#define QNODEVIEWITEMSOCKET_H
#include "qwidget.h"
QT_BEGIN_NAMESPACE
class QNodeViewItemSocket : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QColor socketColor READ socketColor WRITE setSocketColor)
public:
	QNodeViewItemSocket(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	virtual ~QNodeViewItemSocket();
	void setSocketColor(const QColor &color);
	const QColor& socketColor() const;
signals:
protected:
    void paintEvent(QPaintEvent * event) override;
private:
	QColor mSocketColor;
};
QT_END_NAMESPACE
#endif
