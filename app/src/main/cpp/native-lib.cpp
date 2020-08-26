




#include <jni.h>
#include <string>

#include <android/log.h>
#define TAG "jni_proctice"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__)



extern "C" JNIEXPORT jstring JNICALL
Java_com_easyway_ndkapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    LOGD("我要看到的调试信息^_^");
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
