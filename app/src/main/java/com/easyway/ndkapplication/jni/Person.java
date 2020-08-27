package com.easyway.ndkapplication.jni;

import com.easyway.ndkapplication.utils.Ulog;

public class Person {
    public static int age = 18;
    public String name = "小明";

    public String callMethod(String str) {
        if (str != null) {
            Ulog.i("jni_proctice", "call method with " + str);
        } else {
            Ulog.i("jni_proctice", "call method with null");
        }
        return "";
    }

    public static String callStaticMethod(String[] strs, int num) {
        if (strs != null) {
            for (String str : strs) {
                Ulog.i("jni_proctice", "str is:" + str);
            }
        }
        return "";
    }

    @Override
    public String toString() {
        return "Person{" +
                "age=" + age +
                ", name='" + name + '\'' +
                '}';
    }
}
