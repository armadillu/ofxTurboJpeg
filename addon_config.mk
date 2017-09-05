meta:
	ADDON_NAME = ofxTurboJpeg
	ADDON_DESCRIPTION = OF wrapper for turbo-jpeg
	ADDON_AUTHOR = Oriol Ferrer Mesià, Satoru Higa, Brett Renfer
	ADDON_TAGS = "jpeg" "turboJPEG" "binary" "image"
	ADDON_URL = https://github.com/robotconscience/ofxTurboJpeg

osx:
	ADDON_INCLUDES = src/ 
	ADDON_INCLUDES += libs/turbo-jpeg/include

	ADDON_SOURCES = src/ofxTurboJpeg.h
	ADDON_SOURCES += src/ofxTurboJpeg.cpp

linux64:
	ADDON_LDFLAGS = -lturbojpeg

vs:
	# These should get automatically set up by the projectGenerator. If you're adding
	# to a project manually, use the following pattern:
	# Win32/Debug
	# ADDON_LIBS = libs/libwebsockets/lib/vs/Win32/Debug/turbojpeg-static.lib
	# Win32/Release
	# ADDON_LIBS = libs/libwebsockets/lib/vs/Win32/Release/turbojpeg-static.lib
	# x64/Debug 
	# ADDON_LIBS = libs/libwebsockets/lib/vs/x64/Debug/turbojpeg-static.lib
	# x64/Release 
	# ADDON_LIBS = libs/libwebsockets/lib/vs/x64/Release/turbojpeg-static.lib

