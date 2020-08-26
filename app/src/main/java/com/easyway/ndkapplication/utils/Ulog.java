package com.easyway.ndkapplication.utils;

import android.os.Environment;
import android.util.Log;

import androidx.annotation.NonNull;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.charset.Charset;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Ulog {

    public static final String TAG = "cc-";
    public static final String logFileName = "NDKDemoLog";
    public static final boolean IS_HIDE_LOG = false;

    public static void i(Object mess) {
        if (IS_HIDE_LOG) return;

        Log.e(TAG + "", mess + "");
    }

    public static void i(Object tag2, Object mess) {
        if (IS_HIDE_LOG) return;
        String msg = mess + "";
        String tag = TAG + tag2;
        if (tag == null || tag.length() == 0
                || msg == null || msg.length() == 0)
            return;

        int segmentSize = 3 * 1024;
        long length = msg.length();
        if (length <= segmentSize) {// 长度小于等于限制直接打印
            Log.e(tag, msg);
        } else {
            while (msg.length() > segmentSize) {// 循环分段打印日志
                String logContent = msg.substring(0, segmentSize);
                msg = msg.replace(logContent, "");
                Log.e(tag, logContent);
            }
            Log.e(tag, msg);// 打印剩余日志
        }

    }

    public static void i(Object tag, Object... content) {

        if (IS_HIDE_LOG) return;

        Log.e(TAG + tag, getString(content) + "");
    }

    public static void i1(Object tag, Object... content) {

        if (IS_HIDE_LOG) return;

        Log.e(TAG + tag, getString(content) + getFunctionName());
    }


    public static void i1(Object mess) {
        if (IS_HIDE_LOG) return;

        Log.e(TAG + "", mess + getFunctionName());
    }

    public static void i1(Object tag, Object mess) {
        if (IS_HIDE_LOG) return;

        Log.e(TAG + tag, mess + getFunctionName());
    }


    /**
     * 获取相关数据:类名,方法名,行号等.用来定位行
     *
     * @return
     */
    public static String getFunctionName() {
        StackTraceElement[] sts = Thread.currentThread().getStackTrace();
        if (sts != null) {
            for (StackTraceElement st : sts) {
                if (st.isNativeMethod()) {
                    continue;
                }
                if (st.getClassName().equals(Thread.class.getName())) {
                    continue;
                }
                if (st.getClassName().equals(Ulog.class.getName())) {
                    continue;
                }
                return "[ Thread:" + Thread.currentThread().getName() + " " + st.getMethodName()
                        + "(" + st.getFileName() + ":" + st.getLineNumber() + ")" + " ]";
            }
        }
        return null;
    }

    @NonNull
    private static String getString(Object[] obArray) {
        String message = "";
        for (int i = 0; i < obArray.length; i++) {
            message += obArray[i] + (i == 1 || i == (obArray.length - 1) ? "" : "===");
        }

        return message;
    }

    private static SimpleDateFormat mSimpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    private static SimpleDateFormat mSimpleDateFormatTag = new SimpleDateFormat("yyyy-MM-dd");

    /**
     * 写入内存卡
     *
     * @param text
     */
    public static void writeToFile(String text) {
        i("writeToFile", "---\n\n" + text + "\n\n\n\n---");
        //开始写入
        FileOutputStream fileOutputStream = null;
        BufferedWriter bufferedWriter = null;
        try {
            //文件路径
            String fileRoot = Environment.getExternalStorageDirectory().getPath() + "/" + logFileName + "/";
            String fileName = mSimpleDateFormatTag.format(new Date()) + ".txt";
            // 时间 + 内容
            String log = "\n\n\n\n-----------" + mSimpleDateFormat.format(new Date()) + "----------\n"
                    + "\n" + text;
            //检查父路径
            File fileGroup = new File(fileRoot);
            //创建根布局
            if (!fileGroup.exists()) {
                fileGroup.mkdirs();
            }
            //创建文件
            File fileChild = new File(fileRoot + fileName);
            if (!fileChild.exists()) {
                fileChild.createNewFile();
            }
            fileOutputStream = new FileOutputStream(fileRoot + fileName, true);
            //编码问题 GBK 正确的存入中文
            bufferedWriter = new BufferedWriter(new OutputStreamWriter(fileOutputStream, Charset.forName("gbk")));
            bufferedWriter.write(log);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            i(e.toString());
        } catch (IOException e) {
            e.printStackTrace();
            i(e.toString());
        } finally {
            if (bufferedWriter != null) {
                try {
                    bufferedWriter.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }


}
