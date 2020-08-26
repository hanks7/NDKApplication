package com.easyway.ndkapplication.jni;

public class JNIRefrenceType {
    static {
        System.loadLibrary("native-lib");
    }

    public native String handleStringArray(String[] array);
}
