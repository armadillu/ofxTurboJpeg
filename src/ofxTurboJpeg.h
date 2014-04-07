#pragma once

#include "ofMain.h"

#include "turbojpeg.h"

class ofxTurboJpeg
{

public:

	ofxTurboJpeg();
	~ofxTurboJpeg();
    
    template <class T>
    unsigned char * compress( T & img, int jpegQuality, unsigned long *size){
        
        if (img.getWidth() == 0) return NULL;
        
        int pitch = 0, flags = 0, jpegsubsamp = 0;
        *size = 0;
        
        unsigned int bpp = img.getPixelsRef().getNumChannels();
        
        unsigned char * output = (unsigned char*) malloc ( sizeof(char) *  img.getWidth() * img.getHeight() * bpp );
        tjCompress(handleCompress, img.getPixels() , img.getWidth(), pitch, img.getHeight(), bpp, output, size, jpegsubsamp, jpegQuality, flags);
        
        return output;
    }
    
    void save( ofImage * img, string path, int jpegQuality );
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

};