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

#include <QDebug>
#include "gameengine.h"

// Constructor
GameEngine::GameEngine()
{
}

// Destructor
GameEngine::~GameEngine()
{
}

QStringList GameEngine::inventoryItems() const
{
    return m_inventoryItems;
}

QStringList GameEngine::localItems() const
{
    return m_localItems;
}

int GameEngine::turnsPlayed() const
{
    return m_turns;
}

QString GameEngine::currentLocation() const
{
    return "driveway";
}

void GameEngine::doLook()
{
    emit sendOutput(
"You are in the driveway near your car.\n"
"You see:\n"
"  key\n"
"You can go: north\n");

}

void GameEngine::doInventory()
{
    QString msg;
    msg = tr("You are carrying:");
    foreach (QString item, m_inventoryItems) {
        msg += "\n  " + item;
    }
    emit sendOutput(msg);
}

void GameEngine:: doHelp()
{
}

void GameEngine::doQuit()
{
}

void GameEngine::doTake(QString item)
{
    qDebug() << "Take: " << item;
}

void GameEngine::doDrop(QString item)
{
    qDebug() << "Drop: " << item;
}

void GameEngine::doUse(QString item)
{
    qDebug() << "Use: " << item;
}

void GameEngine::doExamine(QString item)
{
    qDebug() << "Examine: " << item;
}

void GameEngine::doMoveUp()
{
}

void GameEngine::doMoveDown()
{
}

void GameEngine::doMoveNorth()
{
}

void GameEngine::doMoveSouth()
{
}

void GameEngine::doMoveEast()
{
}

void GameEngine::doMoveWest()
{
}

// emit updateInventoryItems(QStringList items);
// emit updateLocalItems(QStringList items);
// emit updateValidMoves(QStringList moves);

void GameEngine::start()
{
    m_turns = 0;
    m_inventoryItems << "flashlight";
    m_localItems << "key";

    emit sendOutput(
"                        Abandoned Farmhouse Adventure\n"
"                                By Jeff Tranter\n"
"\n"
"Your three-year-old grandson has gone missing and was last seen headed in the\n"
"direction of the abandoned family farm. It's a dangerous place to play.\n"
"You have to find him before he gets hurt, and it will be getting dark soon...\n"
);

}
