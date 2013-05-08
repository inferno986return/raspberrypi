/*
 * 
 * The Abandoned Farm House Adventure
 *
 * Jeff Tranter <tranter@pobox.com>
 *
 * Copyright 2012-1013 Jeff Tranter
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameengine.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    e = new GameEngine;
    initialize();
}

MainWindow::~MainWindow()
{
    delete e;
    delete ui;
}

void MainWindow::initialize()
{
    locationLabel = new QLabel(tr("Turns: 0"));
    turnsLabel = new QLabel(tr("Location: driveway"));
    statusBar()->addPermanentWidget(turnsLabel, 1);
    statusBar()->addPermanentWidget(locationLabel);

    // Signal/slot connections
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(quit()));

    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(ui->takeButton, SIGNAL(clicked()), this, SLOT(take()));
    connect(ui->dropButton, SIGNAL(clicked()), this, SLOT(drop()));
    connect(ui->useButton, SIGNAL(clicked()), this, SLOT(use()));
    connect(ui->examineButton, SIGNAL(clicked()), this, SLOT(examine()));

    connect(ui->lookButton, SIGNAL(clicked()), e, SLOT(doLook()));
    connect(ui->inventoryButton, SIGNAL(clicked()), e, SLOT(doInventory()));
    connect(ui->helpButton, SIGNAL(clicked()), e, SLOT(doHelp()));

    connect(ui->upButton, SIGNAL(clicked()), e, SLOT(doMoveUp()));
    connect(ui->downButton, SIGNAL(clicked()), e, SLOT(doMoveDown()));
    connect(ui->northButton, SIGNAL(clicked()), e, SLOT(doMoveNorth()));
    connect(ui->southButton, SIGNAL(clicked()), e, SLOT(doMoveSouth()));
    connect(ui->eastButton, SIGNAL(clicked()), e, SLOT(doMoveEast()));
    connect(ui->westButton, SIGNAL(clicked()), e, SLOT(doMoveWest()));

    objectButtonGroup = new QButtonGroup();
    objectButtonGroup->addButton(ui->objectButton1, 0);
    objectButtonGroup->addButton(ui->objectButton2, 1);
    objectButtonGroup->addButton(ui->objectButton3, 2);
    objectButtonGroup->addButton(ui->objectButton4, 3);
    objectButtonGroup->addButton(ui->objectButton5, 4);
    objectButtonGroup->addButton(ui->objectButton6, 5);

    for (int i = 0; i < 6; ++i) {
        objectButtonGroup->button(i)->setText(tr("-"));
    }

    inventoryButtonGroup = new QButtonGroup();
    inventoryButtonGroup->addButton(ui->inventoryButton1, 0);
    inventoryButtonGroup->addButton(ui->inventoryButton2, 1);
    inventoryButtonGroup->addButton(ui->inventoryButton3, 2);
    inventoryButtonGroup->addButton(ui->inventoryButton4, 3);
    inventoryButtonGroup->addButton(ui->inventoryButton5, 4);

    for (int i = 0; i < 5; ++i) {
        inventoryButtonGroup->button(i)->setText(tr("-"));
    }

    ui->textEdit->setText(
"                        Abandoned Farmhouse Adventure\n"
"                                By Jeff Tranter\n"
"\n"
"Your three-year-old grandson has gone missing and was last seen headed in the\n"
"direction of the abandoned family farm. It's a dangerous place to play.\n"
"You have to find him before he gets hurt, and it will be getting dark soon...\n"
"? "
);

}

void MainWindow::quit()
{
    int button = QMessageBox::question(this, tr("Confirm Quit"), tr("Are you sure you want to quit?"));
    if (button == QMessageBox::Yes) {
        qApp->quit();
    }
}

void MainWindow::gameOver()
{
    int turns = 47;
    int button = QMessageBox::question(this, tr("Game Over"), tr("Game over after %1 turns.\nDo you want to play again?").arg(turns));
    if (button == QMessageBox::No) {
        qApp->quit();
    }
}

void MainWindow::take()
{
}

void MainWindow::drop()
{
}

void MainWindow::use()
{
}

void MainWindow::examine()
{
}

// This intercepts the window close so we can ask the user to confirm.
void MainWindow::closeEvent(QCloseEvent *event)
{
    quit();
    event->ignore(); // If we got here we do not want to quit.
}
