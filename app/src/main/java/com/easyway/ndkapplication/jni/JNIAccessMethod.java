package com.easyway.ndkapplication.jni;

/**
 * JNI访问Java类方法
 */
public class JNIAccessMethod {
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * JNI调用对象的方法
     * @param person
     */
    public native void accessMethod(Person person);

    /**
     * JNI调用类的静态方法
     * @param person
     */
    public native void accessStaticMethod(Person person);
}
