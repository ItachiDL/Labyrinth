// Create a Window with two buttons and a field where a maze is randomly generated
// 1. Generate a maze
// 2. Find a way in the maze 

import QtQuick 2.0

Window{
    id: root
    width: 1024
    height: 768
    visible: true
    title: "Maze Way Finder"

    Rectangle{
        id: contextArea
        width: root.width/3
        height: root.height
        color: "blue"
        Rectangle{
            id: mazeGenerator
            width: contextArea.width/2
            height: contextArea.height/10
            color: "lightgray"
            anchors.horizontalCenter: parent.horizontalCenter
            y: 20
            border.color: "black"
            Text{
                text: "Generate Maze"
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    //maze.generateMaze()
                    parent.color = "green"
                }
            }
        }
        Rectangle{
            id: mazeWayFinder
            width: contextArea.width/2
            height: contextArea.height/10
            color: "lightgray"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: mazeGenerator.bottom
            border.color: "black"
            Text{
                text: "Find Way in Maze"
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    //maze.generateMaze()
                    parent.color = "green"
                }
            }
        }
    }
    Rectangle{
        id: mazeArea
        width: root.width*2/3
        height: root.height
        color: "lightgray"
        anchors.left: contextArea.right
    }
}
