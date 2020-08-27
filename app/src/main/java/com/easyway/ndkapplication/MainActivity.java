package com.easyway.ndkapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

import com.easyway.ndkapplication.jni.JNIAccessField;
import com.easyway.ndkapplication.jni.JNIBasicType;
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


        Ulog.i("callNativeInt", type.callNativeInt(1));
        Ulog.i("callNativeByte", type.callNativeByte((byte) 122));
        Ulog.i("callNativeChar", type.callNativeChar('a'));
        Ulog.i("callNativeShort", type.callNativeShort((short) 4));
        Ulog.i("callNativeLong", type.callNativeLong(5l));

        Ulog.i("getStringFromC", stringType.getStringFromC("test"));
        stringType.handleStringByC("test");
        Ulog.i("getStringFromC", jniRefrenceType.handleStringArray(new String[]{"aaa", "bbb", "ccc"}));


        JNIAccessField jniAccessField = new JNIAccessField();
        Person person = new Person();
        Ulog.i("jni_proctice", "修改前 person:" + person);
        jniAccessField.accessFile(person);
        Ulog.i("jni_proctice", "修改后 person:" + person);

        jniAccessField.staticAccessInstanceFiedld();
        Ulog.i("jniAccessField", "修改后 jniAccessField.age:" + jniAccessField.age);

    }
}
