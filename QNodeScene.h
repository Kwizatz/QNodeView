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
#ifndef QNODESCENE_H
#define QNODESCENE_H
#include <QGraphicsScene>
#include <QColor>

class QNodeScene : public QGraphicsScene
{
public:
	Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor);
	Q_PROPERTY(QColor primaryGridColor READ primaryGridColor WRITE setPrimaryGridColor);
	Q_PROPERTY(QColor secondaryGridColor READ secondaryGridColor WRITE setSecondaryGridColor);
	Q_PROPERTY(size_t gridSize READ gridSize WRITE setGridSize);
	Q_PROPERTY(size_t gridSquares READ gridSquares WRITE setGridSquares);

    QNodeScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
    QNodeScene(const QRectF &sceneRect, QObject *parent = nullptr);
    QNodeScene(QObject *parent = nullptr);

	~QNodeScene() override;
	void drawBackground(QPainter *painter, const QRectF &rect) override;
	const QColor& backgroundColor() const;
	const QColor& primaryGridColor() const;
	const QColor& secondaryGridColor() const;
	const size_t gridSize() const;
	const size_t gridSquares() const;
	void setBackgroundColor(const QColor& color);
	void setPrimaryGridColor(const QColor& color);
	void setSecondaryGridColor(const QColor& color);
	void setGridSize(size_t size);
	void setGridSquares(size_t size);

private:
	Q_OBJECT;
	QColor mBackgroundColor{0xdc, 0xdc, 0xdc};
	QColor mPrimaryGridColor{0xd6,0x9d,0x85};
	QColor mSecondaryGridColor{0xaa,0xaa,0xaa};
    size_t mGridSize{20};
    size_t mGridSquares{5};
};
#endif
