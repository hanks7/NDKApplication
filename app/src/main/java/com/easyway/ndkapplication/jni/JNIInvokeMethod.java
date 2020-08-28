package com.easyway.ndkapplication.jni;

/**
 * @author 侯建军 47466436@qq.com
 * @date 2020/8/28
 * @description JNI子线程访问Java方法
 */
public class JNIInvokeMethod {
    static {
        System.loadLibrary("native-lib");
    }

    public native void nativeCallback(ICallback callback);

    public native void nativeThreadCallback(IThreadCallback callback);

}
