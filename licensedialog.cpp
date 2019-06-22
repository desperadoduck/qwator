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

#include "licensedialog.h"
#include "build/ui_licensedialog.h"
#include "build/ui_codelicensewidget.h"
#include "build/ui_graphicslicensewidget.h"
#include <QApplication>

LicenseDialog::LicenseDialog(QWidget* parent): QDialog(parent) {
   m_uiLicenseDialog = new Ui_LicenseDialog();
   m_uiCodeLicenseWidget = new Ui_CodeLicenseWidget();
   m_uiGraphicsLicenseWidget = new Ui_GraphicsLicenseWidget();
   m_uiLicenseDialog->setupUi(this);
   m_uiCodeLicenseWidget->setupUi(m_uiLicenseDialog->codeLicenseTab);
   m_uiGraphicsLicenseWidget->setupUi(m_uiLicenseDialog->graphicsLicenseTab);
   connect(m_uiCodeLicenseWidget->aboutQtButton, &QPushButton::clicked, qApp, &QApplication::aboutQt);
}

LicenseDialog::~LicenseDialog() {
    delete m_uiLicenseDialog;
    delete m_uiCodeLicenseWidget;
    delete m_uiGraphicsLicenseWidget;
}
