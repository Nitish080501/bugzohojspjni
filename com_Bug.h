/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_Bug */

#ifndef _Included_com_Bug
#define _Included_com_Bug
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_Bug
 * Method:    insert
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_Bug_insert
  (JNIEnv *, jclass, jstring, jstring, jstring, jstring, jstring, jstring);

/*
 * Class:     com_Bug
 * Method:    updatestatus
 * Signature: (ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_Bug_updatestatus
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     com_Bug
 * Method:    changeassign
 * Signature: (ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_Bug_changeassign
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     com_Bug
 * Method:    deleterep
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_Bug_deleterep
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_Bug
 * Method:    searchid
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_Bug_searchid
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_Bug
 * Method:    searchpriority
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_Bug_searchpriority
  (JNIEnv *, jclass, jstring);

#ifdef __cplusplus
}
#endif
#endif