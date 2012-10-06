#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	ofBackground(30);
	
	chrono = ofxTimeMeasurements::instance();
	
	freeImageLoadedImage.loadImage("loadTest.jpg");	
}

//--------------------------------------------------------------
void testApp::update()
{
	// load with turboJPG //////////////////////////
	chrono->startMeasuring("load turbo jpeg");
		turbo.load("loadTest.jpg", turboJpegLoadedImage);
	chrono->stopMeasuring("load turbo jpeg");
	
	// load with freeImage //////////////////////////
	chrono->startMeasuring("load freeImage jpeg");
	freeImageLoadedImage.loadImage("loadTest.jpg");
	chrono->stopMeasuring("load freeImage jpeg");
	
	
	// save with turboJPG //////////////////////////
	chrono->startMeasuring("save turbo jpeg");
		turbo.save("save turbo.jpg", turboJpegLoadedImage, 75);
	chrono->stopMeasuring("save turbo jpeg");
	
	// save with freeImage //////////////////////////
	chrono->startMeasuring("save freeImage jpeg");
	freeImageLoadedImage.saveImage("freeImge.jpg", OF_IMAGE_QUALITY_HIGH);
	chrono->stopMeasuring("save freeImage jpeg");

}

//--------------------------------------------------------------
void testApp::draw()
{
	turboJpegLoadedImage.draw(0,0);
	freeImageLoadedImage.draw( turboJpegLoadedImage.getWidth(), 0);
	
	chrono->draw(20, turboJpegLoadedImage.getHeight() + 10);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}