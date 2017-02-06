#pragma once

#include "ofMain.h"

#include "turbojpeg.h"

class ofxTurboJpeg
{

public:

	ofxTurboJpeg();
	~ofxTurboJpeg();

	bool load(ofPixels & pix, const string & path);
	bool load(ofPixels & pix, const ofBuffer & buf);

	void save(const ofPixels & img, const string & path, int jpegQuality = 90);
	void save(ofBuffer & buf, const ofPixels & pix, int jpegQuality = 90);

	OF_DEPRECATED_MSG("Use ofPixels api instead.", bool load(ofImage & img, const string & path));
	OF_DEPRECATED_MSG("Use ofPixels api instead.", bool load(ofImage & img, const ofBuffer & buf));

	OF_DEPRECATED_MSG("Use ofPixels api instead.", void save(ofImage * img, const string & path, int jpegQuality = 90));
	OF_DEPRECATED_MSG("Use ofPixels api instead.", void save(const ofImage & img, const string & path, int jpegQuality = 90));

	template <class T>
	bool compress( T & img, int jpegQuality, ofBuffer & buffer){

		if (img.getWidth() == 0) return NULL;

		int pitch = 0, flags = 0, jpegsubsamp = 0;
		buffer.clear();

		unsigned int bpp = img.getPixels().getNumChannels();
		unsigned int bytesPerLine = img.getPixels().getBytesPerPixel() *  img.getWidth();
		unsigned char* data = NULL;

		unsigned long size = 0;

		if ( bpp == 1 ){
			jpegsubsamp = TJSAMP_GRAY;
		}

		int ok = tjCompress2(handleCompress, img.getPixels().getData(), img.getWidth(), bytesPerLine, img.getHeight(), getTJPixelFormat(img.getPixels().getImageType()), &data, &size, jpegsubsamp, jpegQuality, flags);

		if (ok != 0)
		{
			ofLogError("Error in tjCompress():")<<tjGetErrorStr();
			tjFree(data);

			return false;
		} else {
			buffer.set((char*)(data), size);
			tjFree(data);
			return true;
		}
	}

private:

	tjhandle handleCompress;
	tjhandle handleDecompress;

    int getTJPixelFormat( ofImageType fmt );
};
