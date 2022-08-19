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

#include "QNodeScene.h"
#include <QPainter>
#include <QPen>
#include <cmath>
#include <cstdint>

QNodeScene::QNodeScene(qreal x, qreal y, qreal width, qreal height, QObject *parent) : 
    QGraphicsScene(x, y, width, height, parent)
{
    setBackgroundBrush(QBrush(mBackgroundColor));
}

QNodeScene::QNodeScene(const QRectF &sceneRect, QObject *parent) :
    QGraphicsScene(sceneRect,parent)
{
    setBackgroundBrush(QBrush(mBackgroundColor));
}

QNodeScene::QNodeScene(QObject *parent) : QGraphicsScene(parent)
{
    setBackgroundBrush(QBrush(mBackgroundColor));
    setSceneRect(-32000, -32000, 64000, 64000);
}

QNodeScene::~QNodeScene() = default;

void QNodeScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter,rect);

    int32_t left = floorf(rect.left());
    int32_t right = ceilf(rect.right());
    int32_t top = floorf(rect.top());
    int32_t bottom = ceilf(rect.bottom());

    int32_t first_left = left - (left % mGridSize);
    int32_t first_top  = top -  (top % mGridSize);

    for(int32_t x = first_left; x < right; x += mGridSize)
    {
        if (x % (mGridSize * mGridSquares) != 0)
        {
            painter->setPen(QPen(mSecondaryGridColor,1.0));
            painter->drawLine(x, top, x, bottom);
        }
        else
        { 
            painter->setPen(QPen(mPrimaryGridColor,2.0));
            painter->drawLine(x, top, x, bottom);
        }
    }

    for(int32_t y = first_top; y < bottom; y += mGridSize)
    {
        if (y % (mGridSize * mGridSquares) != 0)
        {
            painter->setPen(QPen(mSecondaryGridColor,1.0));
            painter->drawLine(left, y, right, y);
        }
        else
        { 
            painter->setPen(QPen(mPrimaryGridColor,2.0));
            painter->drawLine(left, y, right, y);
        }
    }
}

const QColor & QNodeScene::backgroundColor() const
{
	return mBackgroundColor;
}

const QColor & QNodeScene::primaryGridColor() const
{
	return mPrimaryGridColor;
}

const QColor & QNodeScene::secondaryGridColor() const
{
	return mSecondaryGridColor;
}

void QNodeScene::setBackgroundColor(const QColor & color)
{
	mBackgroundColor = color;
}

void QNodeScene::setPrimaryGridColor(const QColor & color)
{
	mPrimaryGridColor = color;
}

void QNodeScene::setSecondaryGridColor(const QColor & color)
{
	mSecondaryGridColor = color;
}

const size_t QNodeScene::gridSize() const
{
    return mGridSize;
}
const size_t QNodeScene::gridSquares() const
{
    return mGridSquares;
}
void QNodeScene::setGridSize(size_t size)
{
    mGridSize = size;
}
void QNodeScene::setGridSquares(size_t size)
{
    mGridSquares = size;
}
