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

#ifndef OCEAN_H
#define OCEAN_H

#include <QPoint>
#include <QGraphicsView>

class LifeForm;
class GraphicsScene;

class Ocean: public QGraphicsView {
public:
    Ocean(QWidget* parent=NULL, const QPoint& size=QPoint(40,20));
    ~Ocean();
    QPoint normalize(const QPoint& pos);
    void turn();
    void removeAll();
    LifeForm* getLifeForm(const QPoint& pos);
    void setLifeForm(const QPoint& pos, LifeForm* lifeform);
    void removeLifeForm(const QPoint& pos);
    QPoint getOceanSize();
    QString renderAsText();
private:
    LifeForm** m_array;
    QPoint m_size;
    int m_age;
};

#endif