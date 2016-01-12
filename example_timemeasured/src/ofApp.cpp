#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	float framerate = 5;
	ofBackground(0, 0, 0, 0);
	chrono = ofxTimeMeasurements::instance();
	chrono->setDesiredFrameRate(framerate);
	ofSetFrameRate(framerate);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// load with turboJPG //////////////////////////
	chrono->startMeasuring("load turbo jpeg", false);
        turbo.load("loadTest.jpg", turboJpegLoadedImage);
	chrono->stopMeasuring("load turbo jpeg", false);

	
	// load with freeImage //////////////////////////
	chrono->startMeasuring("load freeImage jpeg", false);
		freeImageLoadedImage.load("loadTest.jpg");
	chrono->stopMeasuring("load freeImage jpeg", false);


	// save with turboJPG //////////////////////////
	chrono->startMeasuring("save turbo jpeg", false);
		turbo.save( &turboJpegLoadedImage, "save turbo.jpg", 75);
	chrono->stopMeasuring("save turbo jpeg", false);

	// save with freeImage //////////////////////////
	chrono->startMeasuring("save freeImage jpeg", false);
		freeImageLoadedImage.save("freeImge.jpg", OF_IMAGE_QUALITY_HIGH);
	chrono->stopMeasuring("save freeImage jpeg", false);
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	turboJpegLoadedImage.draw(0,0);
	freeImageLoadedImage.draw( turboJpegLoadedImage.getWidth(), 0);
	
	chrono->draw(20, turboJpegLoadedImage.getHeight() + 10);
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