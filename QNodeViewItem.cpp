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
#include "qstyle.h"
#include "qstyleoption.h"
#include "qpainter.h"
#include "QNodeViewItem.h"
#include "QNodeViewItemIO.h"

QNodeViewItem::QNodeViewItem(QWidget *parent, Qt::WindowFlags f) : QFrame(parent,f)
{
	setFrameStyle(QFrame::StyledPanel|QFrame::Plain);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->setSizeConstraint(QLayout::SetMinimumSize);
	layout->setMargin(5);
	QNodeViewItemIO *label = new QNodeViewItemIO(this);
	layout->addWidget(label);
}

QNodeViewItem::~QNodeViewItem()
{
}

#if 0
void QNodeViewItem::paintEvent(QPaintEvent * event)
{
	QStyleOption opt;
	QPainter p(this);
	opt.init(this);
	style()->drawPrimitive(QStyle::PE_FrameDockWidget, &opt, &p, this);
}
#endif