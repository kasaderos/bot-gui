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
    id: root
    width: 320
    height: 440
    visible: true
    title: qsTr("Congra")
    signal newMessage(string msg)
    ListView{
        width: parent.width
        height: parent.height
        id: listMessages
        anchors.top: parent.top
        anchors.bottom: textEditor.top
        delegate: Component {
            Text {
                height: 20
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

            width: parent.width * 0.9
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            id: commandLine
            text:  "enter command"

            // for logging command and request
            onAccepted: {
                //console.log(text)
                var message = {}
                message.msg = text
                messageModel.append(message)
                request(text)
                commandLine.clear()
            }

            function request(param) {
                var http = new XMLHttpRequest()
                var url = "http://localhost:8080";
                var params = "num="+param;
                http.open("GET", url, true);

                // Send the proper header information along with the request
                http.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
                http.setRequestHeader("Content-length", params.length);
                http.setRequestHeader("Connection", "close");

                http.onreadystatechange = function() { // Call a function when the state changes.
                    if (http.readyState == 4) {
                        if (http.status == 200) {
                            console.log(http.response)
                            root.newMessage(http.response)
                        } else {
                            console.log("error: " + http.status)
                        }
                    }
                }
                http.send(params);
            }
        }
    }
    // for logging from golang server
    onNewMessage: {
        var message = {}
        message.msg = msg
        messageModel.append(message)
    }
}
