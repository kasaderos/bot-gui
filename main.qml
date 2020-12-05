import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
/*
  State
    ...

  Orders
    -...

  */

Window {
    width: 320
    height: 440
    visible: true
    title: qsTr("Hello World")

    ListView{
        width: parent.width
        height: parent.height
        id: listMessages
        anchors.top: parent.top
        anchors.bottom: textEditor.top
        delegate: Component {
            Text {
                text: model.msg
            }
        }
        model: messageModel
    }

    ListModel {
        id: messageModel
    }

    Rectangle {
        id: textEditor
        height: parent.height / 13
        width: parent.width
        anchors.bottom: parent.bottom
        color: Qt.rgba(0.9, 0.9, 0.9, 1.0)

        TextInput {
            signal newMessage(string msg)
            width: parent.width * 0.9
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            id: commandLine
            text:  "enter command"

            onAccepted: {
                console.log(text)
                var message = {}
                message.msg = text
                messageModel.append(message)
                commandLine.clear()
            }
        }
    }
}
