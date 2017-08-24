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
#include "qlayout.h"
#include "qpainter.h"
#include "qstyle.h"
#include "qstyleoption.h"
#include "QNodeViewItemSocket.h"

QNodeViewItemSocket::QNodeViewItemSocket(QWidget *parent, Qt::WindowFlags f) : QWidget(parent,f), mSocketColor("green")
{
	setAttribute(Qt::WA_StaticContents);
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	setMinimumSize(10, 10);
}

QNodeViewItemSocket::~QNodeViewItemSocket()
{
}

void QNodeViewItemSocket::setSocketColor(const QColor & color)
{
	mSocketColor = color;
}

const QColor & QNodeViewItemSocket::socketColor() const
{
	return mSocketColor;
}

void QNodeViewItemSocket::paintEvent(QPaintEvent * event)
{
	int diameter = ((size().width() < size().height()) ? size().width() : size().height());
	QStyleOption opt;
    QPainter p(this);
	opt.init(this);
	p.setBrush(mSocketColor);
	p.setPen(mSocketColor);
	p.drawEllipse(((size().width()-diameter+1)/2), ((size().height() - diameter+1) / 2),diameter-1,diameter-1);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
