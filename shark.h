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

#ifndef SHARK_H
#define SHARK_H

#include "lifeform.h"

class Shark: public LifeForm {
public:
    Shark(Ocean* ocean, const QPoint& size);
    virtual QString getSymbol();
    void turn();
private:
    int m_hunger;
    int m_max_hunger;
private:
    static QSvgRenderer* renderer;
};

#endif
