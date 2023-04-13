
#include <Windows.h>
#include <winbase.h>

#include "pch.h"
#include "TestDll.h"

#include "..\..\JavaJNI\include\jni_klass_TestDll.h" //Generated


// Implementation of the native method sayHello()
JNIEXPORT void JNICALL Java_jni_klass_TestDll_sayHello(JNIEnv* env, jobject callingJavaObj) {
    writeToConsole("Hello World from C++!\n");
    return;
}


// Implementation of the native method sayHello(String)
JNIEXPORT void JNICALL Java_jni_klass_TestDll_sayHello1(JNIEnv* env, jobject callingJavaObj, jstring calledArg1) {

    const char* inCStr = env -> GetStringUTFChars(calledArg1, NULL);
    if (NULL == inCStr) return;

    printf("In C, the received string is : %s \n", inCStr);
    printf("Given Argument Echo from C++ - %s \n", inCStr);

    env -> ReleaseStringUTFChars(calledArg1, inCStr);  // release resources
    return;
}


// Implementation of the native method copyFile(String, String)
JNIEXPORT void JNICALL Java_jni_klass_TestDll_copyFile
                 (JNIEnv* env, jobject callingJavaObj, jstring jsrcFilePath, jstring jdestFilePath) {

     LPCWSTR srcFilePath = jstringToWCHAR(env, jsrcFilePath);
     LPCWSTR destFilePath = jstringToWCHAR(env, jdestFilePath);

    BOOL b = CopyFile(srcFilePath, destFilePath, 0);
    if (!b) {
        printf("Error: %ld \n", GetLastError());
    } else {
        printf("Success");
    }
}


WCHAR* jstringToWCHAR(JNIEnv* env, jstring javaString) {
    WCHAR* pwcsName;
    const char* inCStr = env -> GetStringUTFChars(javaString, NULL);
    if (NULL == inCStr) return NULL;
    // required size
    int nChars = MultiByteToWideChar(CP_ACP, 0, inCStr, -1, NULL, 0);
    // allocate it
    pwcsName = new WCHAR[nChars];
    MultiByteToWideChar(CP_ACP, 0, inCStr, -1, (LPWSTR)pwcsName, nChars);
    env->ReleaseStringUTFChars(javaString, inCStr);  // release resources
    return pwcsName;
}


BOOL writeToConsole(char* msg) {
    return ::WriteConsoleA(::GetStdHandle(STD_OUTPUT_HANDLE), msg, (DWORD)strlen(msg), nullptr, nullptr);
}
























