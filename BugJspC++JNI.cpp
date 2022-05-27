#include <jni.h>
#include <iostream>
#include<fstream>
#include "com_Register.h"
using namespace std;

struct Login {
	string name;
	string mailid;
	string password;
};

JNIEXPORT void JNICALL Java_com_Register_reg (JNIEnv* env, jclass, jstring n, jstring m, jstring p) {
	Login l;
	const char* name = env->GetStringUTFChars(n, NULL);
	const char* mailid = env->GetStringUTFChars(m, NULL);
	const char* password = env->GetStringUTFChars(p, NULL);
	std::string rname = std::string(name);
	std::string rmailid = std::string(mailid);
	std::string rpassword = std::string(password);
	env->ReleaseStringUTFChars(n, name);
	env->ReleaseStringUTFChars(m, mailid);
	env->ReleaseStringUTFChars(p, password);
	l.name = rname;
	l.mailid = rmailid;
	l.password = rpassword;

	ofstream write;
	write.open("login.txt", ios::app);
	write << "\n" << l.name;
	write << "\n" << l.mailid;
	write << "\n" << l.password;
	write.close();

}

JNIEXPORT jint JNICALL Java_com_Register_log (JNIEnv* env, jclass, jstring n, jstring p) {
	Login l;
	int flag = 0;
	const char* name = env->GetStringUTFChars(n, NULL);
	const char* password = env->GetStringUTFChars(p, NULL);
	std::string uname = std::string(name);
	std::string upassword = std::string(password);
	env->ReleaseStringUTFChars(n, name);
	env->ReleaseStringUTFChars(p, password);
	ifstream read;
	read.open("login.txt");
	while (!read.eof()) {
		read >> l.name;
		read >> l.mailid;
		read >> l.password;
		if (l.name == uname && l.password == upassword) {
			flag = 1;
		}
	}
	if (flag == 1) {
		return 1;
	}
	else {
		return 0;
	}
}



