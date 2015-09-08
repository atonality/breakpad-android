#include "breakpad_jni.h"
#include "src/client/linux/handler/exception_handler.h"
#include "src/client/linux/handler/minidump_descriptor.h"

static google_breakpad::ExceptionHandler *exception_handler;

bool DumpCallback(const google_breakpad::MinidumpDescriptor& descriptor, void* context, bool succeeded)
{
    return succeeded;
}

JNIEXPORT void JNICALL Java_com_google_breakpad_ExceptionHandler_init(JNIEnv *env, jobject obj, jstring dumpfile_dir)
{
    const char *path = env->GetStringUTFChars(dumpfile_dir, nullptr);

    google_breakpad::MinidumpDescriptor descriptor(path);
    exception_handler = new google_breakpad::ExceptionHandler(descriptor, NULL, DumpCallback, NULL, true, -1);

    env->ReleaseStringUTFChars(dumpfile_dir, path);
}