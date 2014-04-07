#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	ofBackground(30);
	
	//freeImageLoadedImage.loadImage("loadTest.jpg");
}

//--------------------------------------------------------------
void testApp::update()
{
	// load with turboJPG //////////////////////////
		turbo.load("loadTest.jpg", turboJpegLoadedImage);
	
	// load with freeImage //////////////////////////
	//freeImageLoadedImage.loadImage("loadTest.jpg");
	
	// save with turboJPG //////////////////////////
		turbo.save("save turbo.jpg", turboJpegLoadedImage, 75);
	
	// save with freeImage //////////////////////////
	//freeImageLoadedImage.saveImage("freeImge.jpg", OF_IMAGE_QUALITY_HIGH);

}

//--------------------------------------------------------------
void testApp::draw()
{
	turboJpegLoadedImage.draw(0,0);
	freeImageLoadedImage.draw( turboJpegLoadedImage.getWidth(), 0);
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