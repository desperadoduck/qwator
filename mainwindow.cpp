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

#include "mainwindow.h"
#include "shark.h"
#include "fish.h"
#include "ocean.h"
#include <QTimer>
#include <QMainWindow>
#include <licensedialog.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    m_umw=new Ui_MainWindow();
    m_umw->setupUi(this);
    reset();
    m_umw->oceanView->show();
    m_umw->oceanView->turn();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::turn);
    connect(m_umw->licenseButton,&QPushButton::clicked,this,&MainWindow::showLicense);
    connect(m_umw->resetButton,&QPushButton::clicked,this,&MainWindow::reset);
    connect(m_umw->pauseButton,&QPushButton::clicked,this,&MainWindow::pause);
    turnInterval = 400;
    timer->start(turnInterval);
}

void MainWindow::reset() {
    m_umw->oceanView->removeAll();
    auto oceansize=m_umw->oceanView->getOceanSize();
    auto oceansize_area=oceansize.x()*oceansize.y();
    for (int i=0; i<oceansize_area*0.05; i++) {
        auto target = QPoint(rand() % oceansize.x(), rand() % oceansize.y());
        if (m_umw->oceanView->getLifeForm(target)==NULL) {
            new Shark(m_umw->oceanView, target);
        }
    }
    for (int i=0; i<oceansize_area*0.2; i++) {
        auto target = QPoint(rand() % oceansize.x(), rand() % oceansize.y());
        if (m_umw->oceanView->getLifeForm(target)==NULL) {
            new Fish(m_umw->oceanView, target);
        }
    }
}

void MainWindow::turn() {
    m_umw->oceanView->turn();
}

void MainWindow::pause() {
    if (timer->isActive()) {
        timer->stop();
        m_umw->pauseButton->setText(tr("Run"));
    } else {
        timer->start(turnInterval);
        m_umw->pauseButton->setText(tr("Pause"));
    }
}

MainWindow::~MainWindow() {
    delete m_umw;
}

void MainWindow::showLicense() {
   LicenseDialog dialog(this);
   dialog.exec();
}