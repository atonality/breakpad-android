#ifndef BREAKPAD_JNI_H
#define BREAKPAD_JNI_H

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_com_google_breakpad_ExceptionHandler_init(JNIEnv *env, jobject obj, jstring dumpfile_dir);

#ifdef __cplusplus
};
#endif

#endif // BREAKPAD_JNI_H