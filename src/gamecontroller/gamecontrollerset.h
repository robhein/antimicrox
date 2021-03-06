/* antimicrox Gamepad to KB+M event mapper
 * Copyright (C) 2015 Travis Nickles <nickles.travis@gmail.com>
 * Copyright (C) 2020 Jagoda Górska <juliagoda.pl@protonmail>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef GAMECONTROLLERSET_H
#define GAMECONTROLLERSET_H

#include "setjoystick.h"

#include <SDL2/SDL_gamecontroller.h>

class QXmlStreamReader;
class InputDevice;


class GameControllerSet : public SetJoystick
{
    Q_OBJECT

public:
    explicit GameControllerSet(InputDevice *device, int index, QObject *parent = nullptr);

    virtual void refreshAxes();

    virtual void readConfig(QXmlStreamReader *xml); // GameControllerSetXml
    virtual void readJoystickConfig(QXmlStreamReader *xml,
                            QHash<int, SDL_GameControllerButton> &buttons,
                            QHash<int, SDL_GameControllerAxis> &axes,
                            QList<SDL_GameControllerButtonBind> &hatButtons); // GameControllerSetXml class

protected:
    void populateSticksDPad();

public slots:
    virtual void reset();

private:
    void getElemFromXml(QString elemName, QXmlStreamReader *xml); // GameControllerSetXml class
    void readConfDpad(QXmlStreamReader *xml, QList<SDL_GameControllerButtonBind> &hatButtons, bool vdpadExists, bool dpadExists); // GameControllerSetXml class
    void resetSticks();
};

#endif // GAMECONTROLLERSET_H
