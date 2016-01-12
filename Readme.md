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

* Visual studio 2015 (instructions by [tgfrerer](https://github.com/tgfrerer) and [mattfelsen](https://github.com/mattfelsen))
  * turboJPEG libraries for vs2015 compiled straight off the sources using the following recipe:
  * download [turbojpeg source v1.4.1](http://sourceforge.net/projects/libjpeg-turbo/files/1.4.1/libjpeg-turbo-1.4.1.tar.gz/download)
  * download [nasm (net assembler)](http://www.nasm.us/pub/nasm/releasebuilds/2.11.08/win32/nasm-2.11.08-installer.exe)
  * add `nasm.exe` to your `%PATH%` environment variable
    * this depends on where you installed nasm, but should be something like `C:\Users\YOUR_USERNAME\AppData\Local\nasm`
    * edit in `Control Panel > System > Advanced system settings > Environment variables > Path`
  * use `cmake-gui.exe` to build visual studio project files
  * open and compile `libjpeg-turbo.sln` in `Debug` and `Release` modes
  * find `turbojpeg-static.lib` in `build\[Debug|Release]` and copy into the proper locations in the ofxTurboJpeg addon