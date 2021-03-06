/*
    Copyright (C) 2017 Aseman Team
    http://aseman.co

    Meikade is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Meikade is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 2.0
import QtQuick.Controls 2.1
import AsemanTools 1.0

Item {
    id: menu_item
    anchors.fill: parent

    property variant item

    onItemChanged: {
        if( !item )
            return

        item.parent = item_menu_frame
        item.anchors.fill = item_menu_frame
    }

    Item {
        id: item_menu_frame
        width: parent.width
        height: parent.height
        y: menu_item.item? 0 : height
        clip: true

        ItemDelegate {
            anchors.fill: parent
        }

        Behavior on y {
            NumberAnimation{ easing.type: Easing.OutCubic; duration: 400 }
        }
        Behavior on scale {
            NumberAnimation{ easing.type: Easing.OutCubic; duration: 400 }
        }
    }

    Timer {
        id: item_close_timer
        interval: 400
        repeat: false
        onTriggered: {
            menu_item.destroy()
            if(menu_item.item)
                menu_item.item.destroy()
        }
    }

    function close() {
        if( item_close_timer.running )
            return

        item_menu_frame.y = height
        item_close_timer.restart()
    }

    function goOutAndClose() {
        if( item_close_timer.running )
            return

        item_menu_frame.scale = 0.7
        item_close_timer.restart()
    }

    function back() {
        close()
        return true
    }
}
