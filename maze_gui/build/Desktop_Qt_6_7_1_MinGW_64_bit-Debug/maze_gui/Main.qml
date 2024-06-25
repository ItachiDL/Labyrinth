import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("Maze Generator")

    Column {
        spacing: 10
        anchors.centerIn: parent

        Row {
            spacing: 10
            Button {
                text: "Generate Maze"
                onClicked: backend.generateMaze()
            }

            Button {
                text: "Find Way"
                onClicked: backend.findWay()
            }
        }

        GridLayout {
            id: mazeGrid
            columns: backend.mazeColumns
            rowSpacing: 0
            columnSpacing: 0
            Repeater {
                model: backend.mazeData
                Rectangle {
                    width: 20
                    height: 20
                    color: modelData === 'W' ? "black" :
                           modelData === 'X' ? "white" :
                           modelData === 'S' ? "green" :
                           modelData === 'E' ? "red" :
                           modelData === 'O' ? "blue" : "transparent"
                    border.color: "gray"
                    border.width: 1
                }
            }
        }
    }
}
