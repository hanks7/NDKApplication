package com.easyway.ndkapplication.load;

public class JNIDynamicLoad {
    static {
        System.loadLibrary("dynamic-lib");
    }

    public native int getRandomNum();

    public native String getNativeString();
}
