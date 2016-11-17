
#include "com_jni_org_NormalJNI.h"
#include "IDNumberUtil.h"

/*
 * Class:     NormalJNI
 * Method:    isIDNumberLegal
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_jni_org_NormalJNI_isIDNumberLegal(JNIEnv *env, jobject obj, jstring idNumber) {
    char * idChar=(char*)(*env)->GetStringUTFChars(env, idNumber, NULL);
    return isIDNumberLegal(idChar);
}
