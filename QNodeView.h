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
#ifndef QNODEVIEW_H
#define QNODEVIEW_H
#include <QGraphicsView>
class
QNodeView : public QGraphicsView
{
public:
	QNodeView(QGraphicsScene *scene, QWidget *parent = nullptr);
	QNodeView(QWidget *parent = nullptr);
	~QNodeView() override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
private:
	Q_OBJECT;
	void middleMouseButtonPress(QMouseEvent* event);
	void middleMouseButtonRelease(QMouseEvent* event);
	void leftMouseButtonPress(QMouseEvent* event);
	void leftMouseButtonRelease(QMouseEvent* event);
	void rightMouseButtonPress(QMouseEvent* event);
	void rightMouseButtonRelease(QMouseEvent* event);
};
#endif
