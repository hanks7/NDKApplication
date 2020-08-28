package com.easyway.ndkapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

import com.easyway.ndkapplication.jni.ICallback;
import com.easyway.ndkapplication.jni.IThreadCallback;
import com.easyway.ndkapplication.jni.JNIAccessField;
import com.easyway.ndkapplication.jni.JNIAccessMethod;
import com.easyway.ndkapplication.jni.JNIBasicType;
import com.easyway.ndkapplication.jni.JNIInvokeMethod;
import com.easyway.ndkapplication.jni.JNIRefrenceType;
import com.easyway.ndkapplication.jni.JNIStringType;
import com.easyway.ndkapplication.jni.Person;
import com.easyway.ndkapplication.load.JNIDynamicLoad;
import com.easyway.ndkapplication.utils.Ulog;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    JNIDynamicLoad load;
    JNIBasicType type;
    JNIStringType stringType;
    JNIRefrenceType jniRefrenceType;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        load = new JNIDynamicLoad();
        type = new JNIBasicType();
        stringType = new JNIStringType();
        jniRefrenceType = new JNIRefrenceType();

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public void clickJNIDynamicLoad(View view) {
        ((Button) view).setText(load.getNativeString());
    }

    public void clickJNIBasicType(View view) {


        //<editor-fold desc="Java与JNI基础数据类型转换">
        Ulog.i("Java与JNI基础数据类型转换callNativeInt", type.callNativeInt(1));
        Ulog.i("Java与JNI基础数据类型转换callNativeByte", type.callNativeByte((byte) 122));
        Ulog.i("Java与JNI基础数据类型转换callNativeChar", type.callNativeChar('a'));
        Ulog.i("Java与JNI基础数据类型转换callNativeShort", type.callNativeShort((short) 4));
        Ulog.i("Java与JNI基础数据类型转换callNativeLong", type.callNativeLong(5l));
        //</editor-fold>

        //<editor-fold desc="Java与JNI字符串转换">
        Ulog.i("Java与JNI字符串转换", stringType.getStringFromC("test"));


        stringType.handleStringByC("test");
        Ulog.i("Java与JNI字符串转换", jniRefrenceType.handleStringArray(new String[]{"aaa", "bbb", "ccc"}));
        //</editor-fold>

        //<editor-fold desc="Java与JNI引用类型转换">
        JNIAccessField jniAccessField = new JNIAccessField();
        Person person = new Person();
        Ulog.i("Java与JNI引用类型转换", "修改前 person:" + person);
        jniAccessField.accessFile(person);
        Ulog.i("Java与JNI引用类型转换", "修改后 person:" + person);


        jniAccessField.staticAccessInstanceFiedld();
        Ulog.i("Java与JNI引用类型转换", "修改后 jniAccessField.age:" + jniAccessField.age);
        //</editor-fold>

        //<editor-fold desc="NI调用对象的方法和类的静态方法">
        JNIAccessMethod jniAccessMethod = new JNIAccessMethod();
        jniAccessMethod.accessMethod(new Person());//JNI调用对象的方法
        jniAccessMethod.accessStaticMethod(new Person());//JNI调用类的静态方法
        //</editor-fold>

        //<editor-fold desc="JNI访问Java接口(interface)的方法">
        final JNIInvokeMethod jniInvokeMethod = new JNIInvokeMethod();
        jniInvokeMethod.nativeCallback(new ICallback() {
            @Override
            public void callback() {
                Ulog.i("JNI访问Java接口(interface)的方法", "callback");
            }
        });
        //</editor-fold>

        //<editor-fold desc="JNI子线程访问Java方法">
        jniInvokeMethod.nativeThreadCallback(new IThreadCallback() {
            @Override
            public void threadCallback() {
                Ulog.i("JNI子线程访问Java方法", "nativeThreadCallback:" + Thread.currentThread().getName());
            }
        });
        //</editor-fold>
    }
}
