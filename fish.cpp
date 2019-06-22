/*
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

#include "fish.h"
#include "ocean.h"
#include <QVector>
#include <QString>
#include <QSvgRenderer>
#include <iostream>

Fish::Fish(Ocean* ocean, const QPoint & pos): LifeForm(ocean, pos) {
    m_repoductionRateAvg = 6;
    m_repoductionRateRand = 3;
    if (renderer==NULL) {
       renderer=new QSvgRenderer(QString(":/images/twemoji/1f41f.svg"));
    }
    setSharedRenderer(renderer);
    setScale(0.3);
    show();
};

void Fish::turn() {
    LifeForm::turn();
    QVector<QPoint> possibleMoves = findEmptyNeighbours();
    bool reproduce=(m_age>=(m_repoductionRateAvg +(rand() % m_repoductionRateRand) - (m_repoductionRateRand / 2)));
    if (reproduce) {
        m_age=0;
    }
    auto si=possibleMoves.size();
    if (si>0) {
      auto choice = rand() % si;
      auto newpos=possibleMoves[choice];
      if (reproduce) {
          new Fish(m_ocean,newpos);
      } else {
          setPosition(newpos);
      }
    }
};

QString Fish::getClassSymbol(){
    return "\U0001F41F";
}

QString Fish::getSymbol(){
    return Fish::getClassSymbol();
}

QSvgRenderer* Fish::renderer=NULL;