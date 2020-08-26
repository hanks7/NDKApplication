




#include <jni.h>
#include <string>

#include <base.h>
#include <People.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_easyway_ndkapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    LOGD("我要看到的调试信息^_^");
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jint JNICALL
Java_com_easyway_ndkapplication_jni_JNIBasicType_callNativeInt(
        JNIEnv *env,
        jobject instance,
        jint num) {
    LOGD("java int value is %d", num);
    return num * 2;
}

extern "C" JNIEXPORT jbyte JNICALL
Java_com_easyway_ndkapplication_jni_JNIBasicType_callNativeByte(
        JNIEnv *env,
        jobject instance,
        jbyte byte) {
    LOGD("java byte value is %c", byte);
    return byte;
}

extern "C" JNIEXPORT jchar JNICALL
Java_com_easyway_ndkapplication_jni_JNIBasicType_callNativeChar(
        JNIEnv *env,
        jobject instance,
        jchar c) {
    LOGD("java char value is %c", c);
    return c;
}

extern "C" JNIEXPORT jshort JNICALL
Java_com_easyway_ndkapplication_jni_JNIBasicType_callNativeShort(
        JNIEnv *env,
        jobject instance,
        jshort sh) {
    LOGD("java short value is %c", sh);
    return sh;
}

extern "C" JNIEXPORT jlong JNICALL
Java_com_easyway_ndkapplication_jni_JNIBasicType_callNativeLong(
        JNIEnv *env,
        jobject instance,
        jlong l) {
    LOGD("java long value is %d", l);
    return l;
}

extern "C" JNIEXPORT jfloat JNICALL
Java_com_easyway_ndkapplication_jni_JNIBasicType_callNativeFloat(
        JNIEnv *env,
        jobject instance,
        jfloat f) {
    LOGD("java short value is %f", f);
    return f;
}

extern "C" JNIEXPORT jdouble JNICALL
Java_com_easyway_ndkapplication_jni_JNIBasicType_callNativeDouble(
        JNIEnv *env,
        jobject instance,
        jdouble f) {
    LOGD("java double value is %f", f);
    return f;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_easyway_ndkapplication_jni_JNIBasicType_callNativeBoolean(
        JNIEnv *env,
        jobject instance,
        jboolean f) {
    LOGD("java boolean value is %p", f);
    return f;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnidemo3_jni_JNIStringType_getStringFromC(JNIEnv *env, jobject instance,
                                                           jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);
    LOGD("from java string:%s", str);
    env->ReleaseStringUTFChars(str_, str);
    return env->NewStringUTF("from c string hello！");
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_jnidemo3_jni_JNIStringType_handleStringByC(JNIEnv *env, jobject instance,
                                                            jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);
    jsize i = env->GetStringLength(str_);
    char buf[128];
    env->GetStringUTFRegion(str_, 0, i - 1, buf);
    LOGD("字符串长度为%d", i);
    LOGD("字符串%s", buf);
    env->ReleaseStringUTFChars(str_, str);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnidemo3_jni_JNIRefrenceType_handleStringArray(JNIEnv *env, jobject instance,
                                                                jobjectArray objArray) {
    jobject firstObj = env->GetObjectArrayElement(objArray, 0);
    jstring firstStr_ = static_cast<jstring>(firstObj);
    const char *firstStr = env->GetStringUTFChars(firstStr_, 0);
    LOGD("数组长度是：%d", env->GetArrayLength(objArray));
    LOGD("第一个元素是：%s", firstStr);
    env->ReleaseStringUTFChars(firstStr_, firstStr);

    return env->NewStringUTF(firstStr);
}

