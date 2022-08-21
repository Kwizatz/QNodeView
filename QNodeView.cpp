/*
Copyright (C) 2017,2022 Rodrigo Jose Hernandez Cordoba

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
#include "QNodeView.h"

void InitializeUI(QNodeView* nodeView)
{
	nodeView->setRenderHints(
		QPainter::Antialiasing |
		QPainter::TextAntialiasing |
		QPainter::SmoothPixmapTransform);
	nodeView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	nodeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	nodeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

QNodeView::QNodeView(QWidget * parent)  : QGraphicsView(parent)
{
	InitializeUI(this);
}

QNodeView::QNodeView(QGraphicsScene *scene, QWidget *parent) : QGraphicsView(scene, parent)
{
	InitializeUI(this);
}

QNodeView::~QNodeView() = default;

