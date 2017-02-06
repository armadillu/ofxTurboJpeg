#include "ofxTurboJpeg.h"
#include <sys/stat.h>

ofxTurboJpeg::ofxTurboJpeg(){

	handleCompress = tjInitCompress();
	if (handleCompress == NULL){
		ofLogError("ofxTurboJpeg") << "Error in tjInitCompress():" << tjGetErrorStr();
	}

	handleDecompress = tjInitDecompress();
	if (handleDecompress == NULL){
		ofLogError("ofxTurboJpeg") << "Error in tjInitDeCompress():" << tjGetErrorStr();
	}
}

ofxTurboJpeg::~ofxTurboJpeg(){
	if (handleCompress){
		tjDestroy(handleCompress);
	}
	if (handleDecompress){
		tjDestroy(handleDecompress);
	}
	
	handleCompress = NULL;
	handleDecompress = NULL;
}


bool ofxTurboJpeg::load(ofPixels &pix, const string & path){
	ofBuffer buf = ofBufferFromFile(path, true);
	if (buf.size() == 0) return false;
	return load(pix, buf);
}


bool ofxTurboJpeg::load(ofPixels &pix, const ofBuffer& buf){
	int w, h;
	int subsamp;
	int ok = tjDecompressHeader2(handleDecompress, (unsigned char*)buf.getData(), buf.size(), &w, &h, &subsamp);

	if (ok != 0){
		ofLogError("ofxTurboJpeg") << "Error in tjDecompressHeader2():" << tjGetErrorStr() ;
		return false;
	}

	pix.allocate(w, h, 3);
	tjDecompress(handleDecompress, (unsigned char*)buf.getData(), buf.size(), pix.getData(), w, 0, h, 3, 0);
	return true;
}


bool ofxTurboJpeg::load(ofImage &img, const string & path){
	ofPixels pix;
	if (!load(pix, path)) return false;
	img.setFromPixels(pix);
	return true;
}


bool ofxTurboJpeg::load(ofImage &img, const ofBuffer& buf){
	ofPixels pix;
	if (!load(pix, buf)) return false;
	img.setFromPixels(pix);
	return true;
}


void ofxTurboJpeg::save(ofImage * img, const string & path, int jpegQuality ){
    
	if (img == NULL) return;
    
	int pitch = 0, flags = 0, jpegsubsamp = 0;
	unsigned long size = 0;
	int bpp = 3;	//rgb only for now...
	unsigned char * output = (unsigned char*) malloc ( sizeof(char) * img->getWidth() * img->getHeight() * bpp );
	tjCompress(handleCompress, img->getPixels().getData(), img->getWidth(), pitch, img->getHeight(), bpp, output, &size, jpegsubsamp, jpegQuality, flags);
    
	string filePath = ofToDataPath( path, false);
	FILE * file = fopen( filePath.c_str(), "wb");
	fwrite ( output , 1 , size , file );
	fclose( file);
	free (output);
}


void ofxTurboJpeg::save(ofBuffer &buf, const ofPixels& pix, int jpegQuality){
	int pitch = 0, flags = 0, jpegsubsamp = 0;
	unsigned long size = 0;
	
	
	if (pix.getImageType() == OF_IMAGE_COLOR)
	{
		int bpp = 3;
		vector<unsigned char> buffer;
		buffer.resize(pix.getWidth() * pix.getHeight() * bpp);
		
		unsigned char * output = &buffer[0];
		
		tjCompress(handleCompress, (unsigned char*)(pix.getData()), pix.getWidth(), pitch, pix.getHeight(), bpp, output, &size, jpegsubsamp, jpegQuality, flags);
		
		buf.set((const char*)output, size);
	}
	else if (pix.getImageType() == OF_IMAGE_COLOR_ALPHA)
	{
		ofPixels p;
		p.allocate(pix.getWidth(), pix.getHeight(), 3);
		
		const unsigned char *src = pix.getData();
		unsigned char *dst = p.getData();
		
		int num = pix.getWidth() * pix.getHeight();
		for (int i = 0; i < num; i++)
		{
			dst[0] = src[0];
			dst[1] = src[1];
			dst[2] = src[2];
			src += 4;
			dst += 3;
		}
		
		save(buf, p, jpegQuality);
	}
	else if (pix.getImageType() == OF_IMAGE_GRAYSCALE)
	{
		ofPixels p;
		p.allocate(pix.getWidth(), pix.getHeight(), 3);
		
		const unsigned char *src = pix.getData();
		unsigned char *dst = p.getData();
		
		int num = pix.getWidth() * pix.getHeight();
		for (int i = 0; i < num; i++)
		{
			dst[0] = src[0];
			dst[1] = src[0];
			dst[2] = src[0];
			src += 1;
			dst += 3;
		}
		
		save(buf, p, jpegQuality);
	} 
}

void ofxTurboJpeg::save(const ofPixels& pix, const string & path, int jpegQuality){
	ofBuffer buf;
	save(buf, pix, jpegQuality);
	ofBufferToFile(path, buf, true);
}

void ofxTurboJpeg::save(const ofImage& img, const string & path, int jpegQuality){
	save(img.getPixels(), path, jpegQuality);
}


int ofxTurboJpeg::getTJPixelFormat( ofImageType fmt ){
    switch (fmt){
        case OF_IMAGE_COLOR:
            return TJPF_RGB;
        case OF_IMAGE_COLOR_ALPHA:
            return TJPF_RGBA;
        case OF_IMAGE_GRAYSCALE:
            return TJPF_GRAY;
        case OF_IMAGE_UNDEFINED:
            return TJPF_RGB;
    }
}