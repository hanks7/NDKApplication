


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
Java_com_easyway_ndkapplication_jni_JNIStringType_getStringFromC(JNIEnv *env, jobject instance,
                                                                 jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);
    LOGD("from java string:%s", str);
    env->ReleaseStringUTFChars(str_, str);
    return env->NewStringUTF("from c string hello！");
}

extern "C" JNIEXPORT void JNICALL
Java_com_easyway_ndkapplication_jni_JNIStringType_handleStringByC(JNIEnv *env, jobject instance,
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
Java_com_easyway_ndkapplication_jni_JNIRefrenceType_handleStringArray(JNIEnv *env, jobject instance,
                                                                      jobjectArray objArray) {
    jobject firstObj = env->GetObjectArrayElement(objArray, 0);//得到第一个java数组的第一元素,0就是表示取第一个
    jstring jfirstStr = static_cast<jstring>(firstObj);//强转成String类型
    const char *cfirstStr = env->GetStringUTFChars(jfirstStr, 0);//转成c++ String类型
    LOGD("数组长度是：%d", env->GetArrayLength(objArray));
    LOGD("第一个元素是：%s", cfirstStr);
    env->ReleaseStringUTFChars(jfirstStr, cfirstStr);//释放字符串内存空间

    return env->NewStringUTF(cfirstStr);
}


//JNI方法Java类字段
extern "C" JNIEXPORT void JNICALL
Java_com_easyway_ndkapplication_jni_JNIAccessField_accessFile(JNIEnv *env, jobject instance,
                                                              jobject bean) {
    jclass beanClass = env->GetObjectClass(bean);//强转成class类型
    jfieldID nameFiledId = env->GetFieldID(beanClass, "name",
                                           "Ljava/lang/String;");//得到name字段的fieldID
    jstring joldStrName = static_cast<jstring>(env->GetObjectField(bean,
                                                                   nameFiledId));//1.先得到jfieldID为nameFiledId的object类型 2.再强转为jstring类型
    const char *ColdStrName = env->GetStringUTFChars(joldStrName, 0);//转成C语言的 String类型
    env->ReleaseStringUTFChars(joldStrName, ColdStrName);//释放字符串内存
    LOGD("原来的name是：%s", ColdStrName);
    const char *cStrNewName = "新的值：";
//    char *res = newNamePid << oldStr;
// env->NewStringUTF(cStrNewName) 转成 java 的String字符串类型
    env->SetObjectField(bean, nameFiledId, env->NewStringUTF(cStrNewName));

    jfieldID ageFiledId = env->GetStaticFieldID(beanClass, "age", "I");
    jint age = env->GetStaticIntField(beanClass, ageFiledId);
    LOGD("原来的age是：%d", age);
    age *= 2;
    env->SetStaticIntField(beanClass, ageFiledId, age * 2);
}

//JNI方法Java类字段
extern "C" JNIEXPORT void JNICALL
Java_com_easyway_ndkapplication_jni_JNIAccessField_staticAccessInstanceFiedld(JNIEnv *env,
                                                                              jclass beanClass) {
    jfieldID ageFiledId = env->GetStaticFieldID(beanClass, "age", "I");
    jint jIntAge = env->GetStaticIntField(beanClass, ageFiledId);
    LOGD("原来的age是：%d", jIntAge);
    jIntAge *= 2;
    env->SetStaticIntField(beanClass, ageFiledId, jIntAge * 2);
}


extern "C"
JNIEXPORT void JNICALL
Java_com_easyway_ndkapplication_jni_JNIAccessMethod_accessMethod(JNIEnv *env, jobject thiz,
                                                                 jobject person) {
    jclass pJclass = env->GetObjectClass(person);
    jmethodID mId = env->GetMethodID(pJclass, "callMethod",
                                     "(Ljava/lang/String;)Ljava/lang/String;");
//    jclass strClass = env->FindClass("java/lang/String");
//    env->GetObjectField()
    env->CallObjectMethod(person, mId, env->NewStringUTF("哈哈哈哈"));
    jstring jstr = NULL;
    env->CallObjectMethod(person, mId, jstr);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_easyway_ndkapplication_jni_JNIAccessMethod_accessStaticMethod(JNIEnv *env, jobject thiz,
                                                                       jobject person) {
    jclass pJclass = env->GetObjectClass(person);
    jmethodID mId = env->GetStaticMethodID(pJclass, "callStaticMethod",
                                           "([Ljava/lang/String;I)Ljava/lang/String;");
    jclass strClass = env->FindClass("java/lang/String");
    jint length = 20;
    jobjectArray array = env->NewObjectArray(length, strClass, NULL);
    jstring strItem;
    for (int i = 0; i < length; ++i) {
        strItem = env->NewStringUTF("string in native");
        env->SetObjectArrayElement(array, i, strItem);
    }
    env->CallStaticObjectMethod(pJclass, mId, array, length);
}
/**
 * JNI访问Java接口(interface)的方法
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_easyway_ndkapplication_jni_JNIInvokeMethod_nativeCallback(JNIEnv *env, jobject thiz,
                                                                   jobject callback) {
    jobject threadObject = env->NewGlobalRef(callback);
    jclass pJclass = env->GetObjectClass(callback);
    jmethodID mId = env->GetMethodID(pJclass, "callback", "()V");
    env->CallVoidMethod(callback, mId);
}
