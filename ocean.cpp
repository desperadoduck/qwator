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

#include "ocean.h"
#include "lifeform.h"
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsScene>

Ocean::Ocean(QWidget* parent, const QPoint& size): QGraphicsView(parent) {
    int elemcnt=size.x()*size.y();
    m_array=new LifeForm*[elemcnt];
    memset(m_array, 0, elemcnt*sizeof(LifeForm*));
    m_size=size;
    m_age=0;
    setScene(new QGraphicsScene());
}

Ocean::~Ocean() {
    int elemcnt=m_size.x()*m_size.y();
    for (int i=0; i<elemcnt ; i++) {
        delete m_array[i];
    }
    delete m_array;
}

QString Ocean::renderAsText() {
    int elemcnt=m_size.x()*m_size.y();
    QString text="";
    for (int i=0; i<elemcnt ; i++) {
        if (i>0 && (i % m_size.x()) == 0) {
            text=text+"\n";
        }
        if (m_array[i])
           text=text+m_array[i]->getSymbol();
        else text=text+" ";
    }
    return text;
}


void Ocean::turn() {
    int elemcnt=m_size.x()*m_size.y();
    for (int i=0; i<elemcnt ; i++) {
        if (m_array[i]) {
            m_array[i]->turn();
        }
    }
    //std::cout<<renderAsText().toStdString()<<std::endl;
    m_age++;
    invalidateScene();
}

QPoint Ocean::normalize(const QPoint& pos) {
    auto x = pos.x() % m_size.x();
    auto y = pos.y() % m_size.y();
    if (x < 0) x=x+m_size.x();
    if (y < 0) y=y+m_size.y();
    return QPoint(x,y);
}

LifeForm* Ocean::getLifeForm(const QPoint& pos) {
    return m_array[m_size.x()*pos.y()+pos.x()];
}

void Ocean::setLifeForm(const QPoint& pos, LifeForm* lifeform) {
    m_array[m_size.x()*pos.y()+pos.x()] = lifeform;
}

void Ocean::removeLifeForm(const QPoint& pos) {
    auto elemnr = m_size.x()*pos.y()+pos.x();
    delete m_array[elemnr];
    m_array[elemnr]=NULL;
}