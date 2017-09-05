#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	float framerate = 5;
	ofBackground(0, 0, 0, 0);
	ofSetFrameRate(framerate);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// load with turboJPG //////////////////////////
    turbo.load(turboJpegLoadedImage,"loadTest.jpg");

	// load with freeImage //////////////////////////
	freeImageLoadedImage.load("loadTest.jpg");
	

	// save with turboJPG //////////////////////////
	turbo.save( &turboJpegLoadedImage, "save turbo.jpg", 75);
	
	// save with freeImage //////////////////////////
	freeImageLoadedImage.save("freeImge.jpg", OF_IMAGE_QUALITY_HIGH);
}

//--------------------------------------------------------------
void ofApp::draw(){

	turboJpegLoadedImage.draw(0,0);
	freeImageLoadedImage.draw( turboJpegLoadedImage.getWidth(), 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}