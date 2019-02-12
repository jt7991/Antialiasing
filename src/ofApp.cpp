#include "ofApp.h"
#include "of3dGraphics.h"
#include "ofApp.h"
#include "../Antialiasing.h"
#include "ofxGui/src/ofxGui.h"
ofxToggle toggleAntialiasing;
ofxButton drawImageBtn;
double minX,maxX,minY,maxY;
ofImage img;
ofxPanel gui;
ofxIntSlider imageWidth, imageHeight;
Antialiasing antialiasing;
//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui.add(toggleAntialiasing.setup("Antialiasing",false));
	gui.add(imageWidth.setup("Image Width Pixels", 512,100, 1024));
	gui.add(imageHeight.setup("Image Height Pixels", 512, 100, 1024));
	gui.add(drawImageBtn.setup("Draw Image"));
	drawImageBtn.addListener(this, &ofApp::drawImage);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	img.draw(0, 0); 
	gui.draw();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
void ofApp::drawImage() {
	minX = 0;
	maxX = 10.83;
	minY = 0;
	maxY = 10.83;
	img.allocate(imageWidth, imageHeight, OF_IMAGE_COLOR);
	img = antialiasing.calculatePixels(minX, maxX, minY, maxY, img, toggleAntialiasing);

}
