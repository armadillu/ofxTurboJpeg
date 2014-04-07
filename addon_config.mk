meta:
	ADDON_NAME = ofxTurboJpeg
	ADDON_DESCRIPTION = OF wrapper for turbo-jpeg
	ADDON_AUTHOR = Oriol Ferrer Mesià, Satoru Higa, Brett Renfer
	ADDON_TAGS = "jpeg" "turboJPEG" "binary" "image"
	ADDON_URL = https://github.com/robotconscience/ofxTurboJpeg

common:
	# dependencies with other addons, a list of them separated by spaces 
	# or use += in several lines
	ADDON_DEPENDENCIES =
	
	# include search paths, this will be usually parsed from the file system
	# but if the addon or addon libraries need special search paths they can be
	# specified here separated by spaces or one per line using +=
	ADDON_INCLUDES = src/ 
	ADDON_INCLUDES += libs/turbo-jpeg/include

	# any special flag that should be passed to the compiler when using this
	# addon
	ADDON_CFLAGS = 
	
	# any special flag that should be passed to the linker when using this
	# addon, also used for system libraries with -lname
	ADDON_LDFLAGS = 
	
	# linux only, any library that should be included in the project using
	# pkg-config
	ADDON_PKG_CONFIG_LIBRARIES =
	
	# osx/iOS only, any framework that should be included in the project
	ADDON_FRAMEWORKS =
	
	# source files, these will be usually parsed from the file system looking
	# in the src folders in libs and the root of the addon. if your addon needs
	# to include files in different places or a different set of files per platform
	# they can be specified here
	ADDON_SOURCES = src/ofxTurboJpeg.h
	ADDON_SOURCES += src/ofxTurboJpeg.cpp

	# some addons need resources to be copied to the bin/data folder of the project
	# specify here any files that need to be copied, you can use wildcards like * and ?
	ADDON_DATA = libs/turbo-jpeg/lib/osx/libturbojpeg.dylib	
	
	# when parsing the file system looking for libraries exclude this for all or
	# a specific platform
	ADDON_LIBS_EXCLUDE =
	
linux64:
	# binary libraries, these will be usually parsed from the file system but some 
	# libraries need to passed to the linker in a specific order 
	#nothing yet
	
linux:
	#nothing yet
	
win_cb:
	#nothing yet

vs:
	# source files, these will be usually parsed from the file system looking
	# in the src folders in libs and the root of the addon. if your addon needs
	# to include files in different places or a different set of files per platform
	# they can be specified here
	ADDON_SOURCES += 

	# include search paths, this will be usually parsed from the file system
	# but if the addon or addon libraries need special search paths they can be
	# specified here separated by spaces or one per line using +=
	ADDON_INCLUDES += 


	# when parsing the file system looking for include paths exclude this for all or
	# a specific platform
	ADDON_INCLUDES_EXCLUDE
	ADDON_LIBS = libs/turbo-jpeg/lib/win32/turbojpeg-static.lib

linuxarmv6l:
	ADDON_LDFLAGS = 
	ADDON_LIBS = 
linuxarmv7l:
	#nothing yet
	
android/armeabi:	
	#nothing yet
	
android/armeabi-v7a:	
	#nothing yet

osx:
	ADDON_LDFLAGS = ../../../addons/ofxTurboJpeg/libs/turbo-jpeg/lib/osx/libturbojpeg.dylib	
