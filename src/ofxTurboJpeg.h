#pragma once

#include "ofMain.h"

#include "turbojpeg.h"

class ofxTurboJpeg
{

public:

	ofxTurboJpeg();
	~ofxTurboJpeg();
    
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
    
    void save( ofImage * img, string path, int jpegQuality );
	void save(string path, const ofPixels& img, int jpegQuality = 90);

	void save(string path, ofImage& img, int jpegQuality = 90)
	{
		save(path, img.getPixels(), jpegQuality);
	}
	
	bool load(string path, ofPixels &pix);
	bool load(const ofBuffer& buf, ofPixels &pix);

	bool load(string path, ofImage &img)
	{
		ofPixels pix;
		if (!load(path, pix)) return false;

		img.setFromPixels(pix);
		return true;
	}
	
	bool load(const ofBuffer& buf, ofImage &img)
	{
		ofPixels pix;
		if (!load(buf, pix)) return false;

		img.setFromPixels(pix);
		return true;
	}
	
	
private:

	tjhandle handleCompress;
	tjhandle handleDecompress;

    void save(ofBuffer &buf, const ofPixels& img, int jpegQuality = 90);
    int getTJPixelFormat( ofImageType fmt );
};
