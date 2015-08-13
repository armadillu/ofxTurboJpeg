#About
Rough OF addon that uses turbo-jpeg lib to read and write jpegs. 2-4 times faster than OF's freeImge based jpeg en/decoder.

You will need to install libjpeg-turbo (http://sourceforge.net/projects/libjpeg-turbo/) and its dylibs or freemImage's internal version of libjpeg will conflict with the one required by libjpeg-turbo, throwing a "Wrong JPEG library version: library is 80, caller expects 62" error. Alternatively you can just place the "libturbojpeg.dylib" by the binary and it should work. Only tested on OSX Lion.

	ofxTurboJpeg turbo;
	
	//load jpeg
	ofImage * image = turbo.load("loadTest.jpg");
	
	//save jpeg
	turbo.save(image, "save turbo.jpg", 75);

![ofxTurboJpeg screenshot](http://farm8.staticflickr.com/7243/6999702551_fc8812d210_z.jpg)

#Compiling

* Visual studio 2015 (instructions by [tgfrerer](https://github.com/tgfrerer))
  * turboJPEG libraries for vs2015 compiled straight off the sources using the following recipe:
  * download turbojpeg release:
    http://sourceforge.net/projects/libjpeg-turbo/files/1.4.1/libjpeg-turbo-1.4.1-vc.exe/download
  * download nasm (net assembler): http://www.nasm.us/pub/nasm/releasebuilds/2.11.08/win32/nasm-2.11.08-installer.exe
  * copy nasm.exe into the cmake/bin directory so it ends up in the PATH for the cmd prompt.
  * use cmake-gui and cmake to build visual studio project files, compile turbojpeg
  * find turbojpeg-static.lib and it's debug counterpart.
  * rename the debug .lib to turbojpeg-staticd.lib (note the 'd' for last character)
  * copy both lib files into the lib folder in the ofxTurboJpeg addon.
