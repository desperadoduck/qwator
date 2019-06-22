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

#include "shark.h"
#include "ocean.h"
#include "fish.h"
#include <QSvgRenderer>

Shark::Shark(Ocean* ocean, const QPoint & pos): LifeForm(ocean, pos) {
    m_repoductionRateAvg = 25;
    m_repoductionRateRand = 7;
    m_hunger=1;
    m_max_hunger=5;
    if (renderer==NULL) {
       renderer=new QSvgRenderer(QString(":/images/twemoji/1f988.svg"));
    }
    setSharedRenderer(renderer);
    setScale(0.5);
    show();
};

void Shark::turn() {
    LifeForm::turn();
    bool reproduce=(m_age>=(m_repoductionRateAvg +(rand() % m_repoductionRateRand) - (m_repoductionRateRand / 2)));
    if (reproduce) {
        m_age=0;
    }
    QVector<QPoint> possibleMoves = findNeighboursWithSymbol(Fish::getClassSymbol());
    auto edibleMoves=possibleMoves.size();
    if (edibleMoves>0) {
      auto choice = rand() % edibleMoves;
      auto newpos=possibleMoves[choice];
      m_ocean->removeLifeForm(newpos);
      if (reproduce) {
          m_hunger = 1;
          new Shark(m_ocean,newpos);
      } else {
          m_hunger = 0;
          setPosition(newpos);
      }
      return;
    }
    m_hunger++;
    if (m_hunger > m_max_hunger) {
        m_ocean->removeLifeForm(m_position);
        return;
    }
    possibleMoves = findEmptyNeighbours();
    
    auto si=possibleMoves.size();
    if (si>0) {
      auto choice = rand() % si;
      auto newpos=possibleMoves[choice];
      if (reproduce) {
          new Shark(m_ocean,newpos);
          m_hunger++;
      } else {
          setPosition(newpos);
      }
    }
};

QString Shark::getSymbol(){
    return "\U0001F988";
}

QSvgRenderer* Shark::renderer=NULL;
