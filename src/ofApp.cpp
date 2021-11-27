#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	isPaused = false;
	isMousePressed = false;

	// Uncomment this to show movies with alpha channels
	// videoPlayer.setPixelFormat(OF_PIXELS_RGBA);

	videoPlayer.setLoopState(OF_LOOP_NORMAL);
	videoPlayer.load("dummy");
}

//--------------------------------------------------------------
void ofApp::update(){
    videoPlayer.update();
    texture = videoPlayer.getTexture();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xFFFFFF);
    if (texture.isAllocated()){
    texture.draw(20,20);
    }
    ofSetColor(0,10,240);
    ofDrawRectangle(500, 320, 100, 100);
    ofSetHexColor(0x000000);

    ofDrawBitmapString("duration: " + ofToString(videoPlayer.getPosition()*videoPlayer.getDuration(),2) + "/"+ofToString(videoPlayer.getDuration(),2),20,450);
    ofDrawBitmapString("press space for pause",20,500);
    ofDrawBitmapString("press mouse on blue rectangle for file browser",20,550);
    
    if(videoPlayer.getIsMovieDone()){
        ofSetHexColor(0xFF0000);
        ofDrawBitmapString("end of movie",20,440);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 32){
	isPaused = !isPaused;
	videoPlayer.setPaused(isPaused);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (isMousePressed){
        	int width = ofGetWidth();
        	float pct = (float)x / (float)width;
        	videoPlayer.setPosition(pct);
        }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	isMousePressed = true;
	int width = ofGetWidth();
	float pct = (float)x / (float)width;
	videoPlayer.setPosition(pct);
	if (x >= 500 && x <= 600 && y >= 320 && y <= 420){
		isMousePressed = false;
		videoPlayer.load("dummy");
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	isMousePressed = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
