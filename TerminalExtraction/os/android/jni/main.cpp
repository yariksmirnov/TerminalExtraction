#include <string.h>
#include <jni.h>

jstring Java_com_te_TerminalExtraction_TerminalExtraction_stringFromJNI( JNIEnv* env, jobject thiz )
{
    return (*env)->NewStringUTF(env, "My first JNI!");
}
