// Copyright (c) 2016 coder4869 ( https://github.com/coder4869/JNI ). All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.

package com.jni.call;

import com.jni.org.JNIInterface;

public class JNIInterfaceCall {
    
    public static void main(String[] args) {
    	JNIInterface jni = new JNIInterface();
        /**
         * @param idNumber
         *     IDNUMBER_LEGAL = 0,
         *     IDNUMBER_ILLEGAL_LENGTH = 101,
         *     IDNUMBER_ILLEGAL_CHARACTER = 102,
         *     IDNUMBER_ILLEGAL_BIRTHDAY = 111,
         * @return
         */
    	switch (jni.isIDNumberLegal("123456789 ".trim())) {
		case 0:
	        System.out.println("Current idNumber format correct.");
			break;
			
		case 101:
	        System.out.println("Current idNumber length error!");
			break;
			
		case 102:
	        System.out.println("Current idNumber character type error!");
			break;
			
		case 103:
	        System.out.println("Current idNumber bithday error!");
			break;
						
		default:
	        System.out.println("Unknown error!");
			break;
		}
    }
}
