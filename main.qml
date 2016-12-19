import QtQuick 2.4
import QtQuick.Window 2.2

import DummyViews 1.0

/**
 * QML Example file
 */
Rectangle {
    id: window
    visible: true
    color: "#ff0000"
    anchors.fill: parent

    DummyView {
    	id: dummyView
		anchors.centerIn: parent	
    	width: 500
    	height: 500
    	cool: true
    	visible: cool

    	onCoolChanged: {
    		if(!isCool) {
    			//do something
    		}
    	}

    	Rectangle {
	    	anchors.centerIn: parent    	
	    	width: 200
	    	height: 200
	    	color: "#0000ff"


	    	Text {
	 	    	font.pixelSize: 26
	    		anchors.centerIn: parent
            	color: "#ffffff"
	    		text: backendController.number
	    	}
    	}
    }
}
