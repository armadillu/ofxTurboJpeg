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


//rgb only for now...
void ofxTurboJpeg::save( ofImage * img, string fileName, int jpegQuality ){
	
	int pitch = 0, flags = 0, jpegsubsamp = 0;
	unsigned long size = 0;
	int bpp = 3;	//rgb only for now...

	unsigned char * output = (unsigned char*) malloc ( sizeof(char) * img->width * img->height * bpp ); 
	tjCompress(handleCompress, img->getPixels() , img->width, pitch, img->height, bpp, output, &size, jpegsubsamp, jpegQuality, flags);

	string filePath = ofToDataPath( fileName, false);
	FILE * file = fopen( filePath.c_str(), "wb");
	fwrite ( output , 1 , size , file );
	fclose( file);
	free (output);
	
}


ofImage* ofxTurboJpeg::load(string fileName){
	
	ofImage * img;
	
	img = new ofImage();
	
	int flags = 0;
	flags = TJ_FASTUPSAMPLE; //faster but worse!

	string filePath = ofToDataPath( fileName, false);
	FILE * file = fopen( filePath.c_str(), "rb");
	
	struct stat info;
	stat(filePath.c_str(), &info);	
	unsigned char * pixels = (unsigned char *)malloc(info.st_size * sizeof(char));
	fread(pixels, info.st_size, 1, file);
	fclose(file);
	
	int w; int h; int subsamp;
	tjDecompressHeader2( handleDecompress, pixels, info.st_size, &w, &h, &subsamp );
	//printf("jpeg is %d x %d\n", w, h);
	// 3 >> rgb only for now
	unsigned char* rgbData = (unsigned char*) malloc(  3 * w * h * sizeof(char));	
	tjDecompress( handleDecompress, pixels, info.st_size, rgbData, w, 0, h, 3 /* rgb only for now*/, 0 );
	
	img->setFromPixels( rgbData, w, h, OF_IMAGE_COLOR);
	
	delete rgbData;
	delete pixels;
	
	return img;

}
