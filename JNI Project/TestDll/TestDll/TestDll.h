#pragma once
#include <jni.h>

WCHAR* jstringToWCHAR(JNIEnv*, jstring);

BOOL writeToConsole(char* msg);

