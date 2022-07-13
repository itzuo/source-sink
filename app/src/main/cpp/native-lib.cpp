#include <jni.h>
#include <string>
#include <ADebug.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_zxj_android_source_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
//    CHECK()
    return env->NewStringUTF(hello.c_str());
}