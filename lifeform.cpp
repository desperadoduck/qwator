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

#include "lifeform.h"
#include "ocean.h"

LifeForm::LifeForm(Ocean* ocean, const QPoint & pos): QGraphicsSvgItem() {
    m_age=0;
    m_ocean=ocean;
    m_position=pos;
    ocean->scene()->addItem(this);
    ocean->setLifeForm(pos, this);
    setPos(QPoint(pos.x()*32, pos.y()*32));
    show();
}


LifeForm::~LifeForm()  {
    m_ocean->scene()->removeItem(this);
}

void LifeForm::turn() {
    m_age += 1;
}

void LifeForm::setPosition(const QPoint & pos) {
    m_ocean->setLifeForm(m_position, NULL);
    m_ocean->setLifeForm(pos, this);
    m_position=pos;
    setPos(QPoint(pos.x()*32, pos.y()*32));
}

QVector<QPoint> LifeForm::findEmptyNeighbours() {
    QVector<QPoint> result;
    for (int i=-1; i<2; i++) {
       for (int j=-1; j<2; j++) {
           if ((i==0) && (j==0)) continue;
           QPoint npos(m_position.x()+i, m_position.y()+j);
           npos = m_ocean->normalize(npos);
           if (m_ocean->getLifeForm(npos)==NULL) {
               result.push_back(npos);
           }
       }
    }
    return result;
}

QVector<QPoint> LifeForm::findNeighboursWithSymbol(const QString& symbol) {
    QVector<QPoint> result;
    for (int i=-1; i<2; i++) {
       for (int j=-1; j<2; j++) {
           if ((i==0) && (j==0)) continue;
           QPoint npos(m_position.x()+i, m_position.y()+j);
           npos = m_ocean->normalize(npos);
           if (m_ocean->getLifeForm(npos)!=NULL && m_ocean->getLifeForm(npos)->getSymbol()==symbol) {
               result.push_back(npos);
           }
       }
    }
    return result;
}