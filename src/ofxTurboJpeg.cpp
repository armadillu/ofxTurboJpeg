/*
 *  ofxTurboJpeg.cpp
 *  emptyExample
 *
 *  Created by Oriol Ferrer Mesià on 20/03/12.
 *  Copyright 2012 uri.cat. All rights reserved.
 *
 */

#include "ofxTurboJpeg.h"
#include <sys/stat.h>

ofxTurboJpeg::ofxTurboJpeg(){
	
	handleCompress = tjInitCompress();	
	if (handleCompress == NULL){
		printf("Error in tjInitCompress():\n%s\n", tjGetErrorStr());
	}

	handleDecompress = tjInitDecompress();
	if (handleDecompress == NULL){
		printf("Error in tjInitDeCompress():\n%s\n", tjGetErrorStr());
	}
}

ofxTurboJpeg::~ofxTurboJpeg(){
	if (handleCompress){
		tjDestroy(handleCompress);
	}
	if (handleDecompress){
		tjDestroy(handleDecompress);
	}
}


//rgb only for now...
void ofxTurboJpeg::save( ofImage * img, string fileName, int jpegQuality ){
	
	if (img == NULL) return;

	int pitch = 0, flags = 0, jpegsubsamp = 0;
	unsigned long size = 0;
	int bpp = 3;	//rgb only for now...

	unsigned char * output = (unsigned char*) malloc ( sizeof(char) * img->getWidth() * img->getHeight() * bpp );
	tjCompress(handleCompress, img->getPixels() , img->getWidth(), pitch, img->getHeight(), bpp, output, &size, jpegsubsamp, jpegQuality, flags);

	string filePath = ofToDataPath( fileName, false);
	FILE * file = fopen( filePath.c_str(), "wb");
	fwrite ( output , 1 , size , file );
	fclose( file);
	free (output);	
}

//rgb only for now...
unsigned char * ofxTurboJpeg::compress( ofImage * img, int jpegQuality, unsigned long *size){
	
	if (img == NULL) return;

	int pitch = 0, flags = 0, jpegsubsamp = 0;
	*size = 0;
	int bpp = 3;	//rgb only for now...

	unsigned char * output = (unsigned char*) malloc ( sizeof(char) * img->getWidth() * img->getHeight() * bpp );
	tjCompress(handleCompress, img->getPixels() , img->getWidth(), pitch, img->getHeight(), bpp, output, size, jpegsubsamp, jpegQuality, flags);

    return output;
}

//rgb only for now...
ofImage* ofxTurboJpeg::load(string fileName){
	
	ofImage * img = NULL;
	
	string filePath = ofToDataPath( fileName, false);
	FILE * file = fopen( filePath.c_str(), "rb");

	if ( file != NULL){

		int flags = 0;
		flags = TJ_FASTUPSAMPLE; //faster but worse!
	
		img = new ofImage();
		struct stat info;
		stat(filePath.c_str(), &info);	
		unsigned char * pixels = (unsigned char *)malloc(info.st_size * sizeof(char));
		fread(pixels, info.st_size, 1, file);
		fclose(file);
		
		int w; int h; int subsamp;
		int ok = tjDecompressHeader2( handleDecompress, pixels, info.st_size, &w, &h, &subsamp );
		if (ok!=0) {printf("Error in tjDecompressHeader2():\n%s\n", tjGetErrorStr());}
		
		//printf("jpeg is %d x %d\n", w, h);
		// 3 >> rgb only for now
		unsigned char* rgbData = (unsigned char*) malloc(  3 * w * h * sizeof(char));	
		tjDecompress( handleDecompress, pixels, info.st_size, rgbData, w, 0, h, 3 /* rgb only for now*/, 0 );
		
		img->setFromPixels( rgbData, w, h, OF_IMAGE_COLOR);
		
		delete rgbData;
		delete pixels;
	}else {
		ofLog(OF_LOG_ERROR, "ofxTurboJpeg::load() >> Image %s not found", fileName.c_str());
	}

	
	return img;

}
