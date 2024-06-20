import QtQuick

Window {
    id: root
    width: 1024
    height: 720
    visible: true

    Rectangle{
        id: button_area
        width: root.width/3
        height: root.height
        anchors.left: root.left
        color: "blue"

        Rectangle{
            id: button_generate
            width: button_area.width/2
            height: button_area.height/10
            y: 15
            anchors.horizontalCenter: parent.horizontalCenter
            color: "red"
            Text{
                text: "Generate Maze"
                color: "#00FF65"
                font.family: "Ubuntu"
                font.pixelSize: 20
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    button_area.color = "black"
                }
            }
        }
        Rectangle{
            id: button_solve
            width: button_area.width/2
            height: button_area.height/10
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: button_generate.bottom
            color: "red"
            Text{
                text: "Find Way"
                color: "#00FF65"
                font.family: "Ubuntu"
                font.pixelSize: 20
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    button_area.color = "yellow"
                }
            }
        }
    }
}
