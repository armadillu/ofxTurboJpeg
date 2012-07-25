#pragma once

#include "ofMain.h"

#include <turbojpeg.h>

class ofxTurboJpeg
{

public:

	ofxTurboJpeg();
	~ofxTurboJpeg();

	void save(string path, const ofPixels& img, int jpegQuality = 90);
	void save(ofBuffer &buf, const ofPixels& img, int jpegQuality = 90);

	void save(string path, ofImage& img, int jpegQuality = 90)
	{
		save(path, img.getPixelsRef(), jpegQuality);
	}
	
	void save(ofBuffer &buf, ofImage& img, int jpegQuality = 90)
	{
		save(buf, img.getPixelsRef(), jpegQuality);
	}
	
	bool load(string path, ofPixels &pix);
	bool load(const ofBuffer& buf, ofPixels &pix);

	bool load(string path, ofImage &img)
	{
		if (load(path, img.getPixelsRef()))
		{
			img.update();
			return true;
		}
		return false;
	}
	
	bool load(const ofBuffer& buf, ofImage &img)
	{
		if (load(buf, img.getPixelsRef()))
		{
			img.update();
			return true;
		}
		return false;
	}
	
private:

	tjhandle handleCompress;
	tjhandle handleDecompress;

};