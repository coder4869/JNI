// Copyright (c) 2016 coder4869 ( https://github.com/coder4869/JNI ). All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.

package com.jni.org;

public class JNIInterface {
	

    static {
    	System.out.println("java.library.path="+System.getProperty("java.library.path"));
        System.loadLibrary("JNIInterface"); //loading libJNIInterface.so or libJNIInterface.dylib
    }
    
    /**
     * @param idNumber
     *     IDNUMBER_LEGAL = 0,
     *     IDNUMBER_ILLEGAL_LENGTH = 101,
     *     IDNUMBER_ILLEGAL_CHARACTER = 102,
     *     IDNUMBER_ILLEGAL_BIRTHDAY = 111,
     * @return
     */
    public native int isIDNumberLegal(String idNumber);
}
