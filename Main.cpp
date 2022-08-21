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
#include <cstdio>
#include <iostream>
#include <QApplication>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include<QGraphicsProxyWidget>
#include <QPushButton>
#include <QTextEdit>
#include "QNodeView.h"
#include "QNodeScene.h"

void AddDebugContent(QGraphicsScene* nodeScene)
{
	QBrush greenBrush{Qt::green};
	QPen outlinePen{QPen(Qt::black)};
	outlinePen.setWidth(2);

	QGraphicsRectItem* rect {nodeScene->addRect(-100, -100, 80, 100, outlinePen, greenBrush)};
	rect->setFlag(QGraphicsItem::ItemIsMovable);

	QGraphicsTextItem* text{nodeScene->addText("This is my Awesome text!", QFont("Noto"))};
	text->setFlag(QGraphicsItem::ItemIsSelectable);
	text->setFlag(QGraphicsItem::ItemIsMovable);
	text->setDefaultTextColor(QColor::fromRgbF(1.0, 1.0, 1.0));

	QPushButton* widget1{new QPushButton("Hello World")};
	QGraphicsProxyWidget* proxy1{nodeScene->addWidget(widget1)};
	proxy1->setFlag(QGraphicsItem::ItemIsMovable);
	proxy1->setPos(0, 30);

	QTextEdit* widget2{new QTextEdit()};
	QGraphicsProxyWidget* proxy2{nodeScene->addWidget(widget2)};
	proxy2->setFlag(QGraphicsItem::ItemIsSelectable);
	proxy2->setPos(0, 60);

	QGraphicsLineItem* line{nodeScene->addLine(-200, -200, 400, -100, outlinePen)};
	line->setFlag(QGraphicsItem::ItemIsMovable);
	line->setFlag(QGraphicsItem::ItemIsSelectable);
}

int main ( int argc, char *argv[] )
{
    QApplication application ( argc, argv );
    QNodeView view;
    view.setWindowTitle("NodeView");
    view.resize(800, 600);
    view.show();
    view.setScene(new QNodeScene());
    AddDebugContent(view.scene());
    return application.exec();
}
