




#include <jni.h>
#include <string>

#include <base.h>



extern "C" JNIEXPORT jstring JNICALL
Java_com_easyway_ndkapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    LOGD("我要看到的调试信息^_^");
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
