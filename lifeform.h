/* 
This code is part of QWator.
Copyright (C) 2019  Florian Schmitt

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LIFEFORM_H
#define LIFEFORM_H

#include <QPoint>
#include <QObject>
#include <QGraphicsSvgItem>

class Ocean;

class LifeForm: public QGraphicsSvgItem {
public:
    LifeForm(Ocean* ocean, const QPoint& size);
    virtual void turn();
    virtual void setPosition(const QPoint & pos);
    virtual QString getSymbol()=0;
    virtual ~LifeForm();
protected:
    QVector<QPoint> findEmptyNeighbours();
    QVector<QPoint> findNeighboursWithSymbol(const QString& symbol);
    int m_age;
    Ocean* m_ocean;
    QPoint m_position;
    int m_repoductionRateAvg;
    int m_repoductionRateRand;
};

#endif