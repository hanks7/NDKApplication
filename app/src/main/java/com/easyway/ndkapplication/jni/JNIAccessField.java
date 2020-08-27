package com.easyway.ndkapplication.jni;

public class JNIAccessField {
    static {
        System.loadLibrary("native-lib");
    }

    public static int age = 50;

    public native void accessFile(Person person);

    public static native void staticAccessInstanceFiedld();
}
