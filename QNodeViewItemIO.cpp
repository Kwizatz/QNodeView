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
#include "qlabel.h"
#include "QNodeViewItemIO.h"
#include "QNodeViewItemSocket.h"

QNodeViewItemIO::QNodeViewItemIO(QWidget *parent, Qt::WindowFlags f) : QWidget(parent,f)
{
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->setSizeConstraint(QLayout::SetMinimumSize);
	layout->setMargin(5);
	QNodeViewItemSocket *input = new QNodeViewItemSocket(this);
	QLabel *label = new QLabel("Input/Output",this);
	QNodeViewItemSocket *output = new QNodeViewItemSocket(this);
	layout->addWidget(input,0, Qt::AlignLeft);
	layout->addWidget(label, 0, Qt::AlignCenter);
	layout->addWidget(output, 0, Qt::AlignRight);
}

QNodeViewItemIO::~QNodeViewItemIO()
{
}
