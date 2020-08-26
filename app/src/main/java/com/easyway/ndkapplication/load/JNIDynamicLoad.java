package com.easyway.ndkapplication.load;

public class JNIDynamicLoad {
    static {
        System.loadLibrary("dynamic-lib");
    }

    protected void dd() {

    }

    public native int getRandomNum();

    public native String getNativeString();
}
