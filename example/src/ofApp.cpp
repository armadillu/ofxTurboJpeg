#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	float framerate = 5;
	ofBackground(0, 0, 0, 0);
	chrono = ofxTimeMeasurements::instance();
	chrono->setDesiredFrameRate(framerate);
	ofSetFrameRate(framerate);
	
	turboJpegLoadedImage = NULL;
}

//--------------------------------------------------------------
void ofApp::update(){

	if (turboJpegLoadedImage != NULL) delete turboJpegLoadedImage;
	
	// load with turboJPG //////////////////////////
	chrono->startMeasuring("load turbo jpeg");
		turboJpegLoadedImage = turbo.load("loadTest.jpg");	
	chrono->stopMeasuring("load turbo jpeg");

	
	// load with freeImage //////////////////////////
	chrono->startMeasuring("load freeImage jpeg");
		freeImageLoadedImage.loadImage("loadTest.jpg");	
	chrono->stopMeasuring("load freeImage jpeg");


	// save with turboJPG //////////////////////////
	chrono->startMeasuring("save turbo jpeg");
		turbo.save( turboJpegLoadedImage, "save turbo.jpg", 75);
	chrono->stopMeasuring("save turbo jpeg");

	// save with freeImage //////////////////////////
	chrono->startMeasuring("save freeImage jpeg");
		freeImageLoadedImage.saveImage("freeImge.jpg", OF_IMAGE_QUALITY_HIGH);
	chrono->stopMeasuring("save freeImage jpeg");
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	turboJpegLoadedImage->draw(0,0);
	freeImageLoadedImage.draw( turboJpegLoadedImage->getWidth(), 0);
	
	chrono->draw(20, turboJpegLoadedImage->getHeight() + 10);
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