#include <iostream>
#include <jni.h>
#include <fstream>
#include<string> 
#include "com_Bug.h"
using namespace std;

int id = 0;

struct Bug {
	string bugname;
	int bugid;
	string bugpriority;
	string bugstatus;
	string bugtime;
	string createdby;
	string bugassignedto;
};

void printbug(Bug b) {
	ofstream tempFile;
	tempFile.open("search.txt");
	tempFile << "\n" << b.bugname;
	tempFile << "\n" << b.bugid;
	tempFile << "\n" << b.bugpriority;
	tempFile << "\n" << b.bugstatus;
	tempFile << "\n" << b.bugtime;
	tempFile << "\n" << b.bugassignedto;
	tempFile.close();
}

JNIEXPORT void JNICALL Java_com_Bug_insert(JNIEnv* env, jclass, jstring bname, jstring bpriority, jstring bstatus, jstring btime, jstring bcreated, jstring assign) {
	Bug b;
	const char* buname = env->GetStringUTFChars(bname, NULL);
	const char* bupriority = env->GetStringUTFChars(bpriority, NULL);
	const char* bustatus = env->GetStringUTFChars(bstatus, NULL);
	const char* butime = env->GetStringUTFChars(btime, NULL);
	const char* bucreated = env->GetStringUTFChars(bcreated, NULL);
	const char* assignedto = env->GetStringUTFChars(assign, NULL);
	std::string bugname = std::string(buname);
	std::string bugpriority = std::string(bupriority);
	std::string bugstatus = std::string(bustatus);
	std::string bugtime = std::string(butime);
	std::string bugcreated = std::string(bucreated);
	std::string bugassign = std::string(assignedto);
	env->ReleaseStringUTFChars(bname, buname);
	env->ReleaseStringUTFChars(bpriority, bupriority);
	env->ReleaseStringUTFChars(bstatus, bustatus);
	env->ReleaseStringUTFChars(btime, butime);
	env->ReleaseStringUTFChars(bcreated, bucreated);
	env->ReleaseStringUTFChars(assign, assignedto);
	b.bugname = bugname;
	b.bugid = id++;
	b.bugpriority = bugpriority;
	b.bugstatus = bugstatus;
	b.bugtime = bugtime;
	b.createdby = bugcreated;
	b.bugassignedto = bugassign;
	ofstream write;
	write.open("bugmanagement.txt", ios::app);
	write << "\n" << b.bugname;
	write << "\n" << b.bugid;
	write << "\n" << b.bugpriority;
	write << "\n" << b.bugstatus;
	write << "\n" << b.bugtime;
	write << "\n" << b.createdby;
	write << "\n" << b.bugassignedto;
	write.close();
}

JNIEXPORT jint JNICALL Java_com_Bug_updatestatus(JNIEnv* env, jclass, jint bid, jstring cstatus) {
		int result=0;
		const char* chstatus = env->GetStringUTFChars(cstatus, NULL);
		std::string changestatus = std::string(chstatus);
		env->ReleaseStringUTFChars(cstatus,chstatus);
		Bug newData;
		newData.bugstatus=changestatus;
		Bug b;
		ofstream tempFile;
		tempFile.open("tempbug.txt");
		ifstream read;
		read.open("bugmanagement.txt");
		while (!read.eof()) {
			read >> b.bugname;
			read >> b.bugid;
			read >> b.bugpriority;
			read.ignore();
			getline(read, b.bugstatus);
			getline(read, b.bugtime);
			read >> b.createdby;
			read >> b.bugassignedto;
			if (b.bugid != bid) {
				tempFile << "\n" << b.bugname;
				tempFile << "\n" << b.bugid;
				tempFile << "\n" << b.bugpriority;
				tempFile << "\n" << b.bugstatus;
				tempFile << "\n" << b.bugtime;
				tempFile << "\n" << b.createdby;
				tempFile << "\n" << b.bugassignedto;
			}
			else {
				tempFile << "\n" << b.bugname;
				tempFile << "\n" << b.bugid;
				tempFile << "\n" << b.bugpriority;
				tempFile << "\n" << newData.bugstatus;
				tempFile << "\n" << b.bugtime;
				tempFile << "\n" << b.createdby;
				tempFile << "\n" << b.bugassignedto;
			}
		}
		read.close();
		tempFile.close();
		remove("bugmanagement.txt");
		result=rename("tempbug.txt", "bugmanagement.txt");
		if (!result) {
			return 1;
		}
		else {
			return 0;
		}
}

JNIEXPORT jint JNICALL Java_com_Bug_changeassign(JNIEnv* env, jclass, jint cid, jstring cwork) {
	int result = 0;
	const char* chwork = env->GetStringUTFChars(cwork, NULL);
	std::string changework = std::string(chwork);
	env->ReleaseStringUTFChars(cwork, chwork);
	Bug newData;
	newData.bugassignedto = changework;
	Bug b;
	ofstream tempFile;
	tempFile.open("tempbug.txt");
	ifstream read;
	read.open("bugmanagement.txt");
	while (!read.eof()) {
		read >> b.bugname;
		read >> b.bugid;
		read >> b.bugpriority;
		read.ignore();
		getline(read, b.bugstatus);
		getline(read, b.bugtime);
		read >> b.createdby;
		read >> b.bugassignedto;
		if (b.bugid != cid) {
			tempFile << "\n" << b.bugname;
			tempFile << "\n" << b.bugid;
			tempFile << "\n" << b.bugpriority;
			tempFile << "\n" << b.bugstatus;
			tempFile << "\n" << b.bugtime;
			tempFile << "\n" << b.createdby;
			tempFile << "\n" << b.bugassignedto;
		}
		else {
			tempFile << "\n" << b.bugname;
			tempFile << "\n" << b.bugid;
			tempFile << "\n" << b.bugpriority;
			tempFile << "\n" << b.bugstatus;
			tempFile << "\n" << b.bugtime;
			tempFile << "\n" << b.createdby;
			tempFile << "\n" << newData.bugassignedto;
		}
	}
	read.close();
	tempFile.close();
	remove("bugmanagement.txt");
	result = rename("tempbug.txt", "bugmanagement.txt");
	if (!result) {
		return 1;
	}
	else {
		return 0;
	}
}

JNIEXPORT jint JNICALL Java_com_Bug_deleterep(JNIEnv* env, jclass, jint deleteid) {
	    int result = 0;
	    Bug b;
		ofstream tempFile;
		tempFile.open("tempbug.txt");
		ifstream read;
		read.open("bugmanagement.txt");
		while (!read.eof()) {
			read >> b.bugname;
			read >> b.bugid;
			read >> b.bugpriority;
			read.ignore();
			getline(read, b.bugstatus);
			getline(read, b.bugtime);
			read >> b.createdby;
			read >> b.bugassignedto;
			if (b.bugid != deleteid) {
				tempFile << "\n" << b.bugname;
				tempFile << "\n" << b.bugid;
				tempFile << "\n" << b.bugpriority;
				tempFile << "\n" << b.bugstatus;
				tempFile << "\n" << b.bugtime;
				tempFile << "\n" << b.bugassignedto;
			}
		}
		read.close();
		tempFile.close();
		remove("bugmanagement.txt");
		result = rename("tempbug.txt", "bugmanagement.txt");
		if (!result) {
			return 1;
		}
		else {
			return 0;
		}
		
}

JNIEXPORT jint JNICALL Java_com_Bug_searchid(JNIEnv* env, jclass, jint searchbugid) {
	int flag = 0;
	Bug b;
	ofstream tempFile;
	tempFile.open("search.txt");
	ifstream read;
	read.open("bugmanagement.txt");
	while (!read.eof()) {
		read >> b.bugname;
		read >> b.bugid;
		read >> b.bugpriority;
		read.ignore();
		getline(read, b.bugstatus);
		getline(read, b.bugtime);
		read >> b.bugassignedto;
		if (b.bugid == searchbugid) {
			flag = 1;
			tempFile << "\n" << b.bugname;
			tempFile << "\n" << b.bugid;
			tempFile << "\n" << b.bugpriority;
			tempFile << "\n" << b.bugstatus;
			tempFile << "\n" << b.bugtime;
			tempFile << "\n" << b.bugassignedto;
			break;
		}
	}
	read.close();
	tempFile.close();
	if (flag == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

JNIEXPORT jint JNICALL Java_com_Bug_searchpriority(JNIEnv* env, jclass, jstring bupriority) {
	int flag = 0;
	const char* bugpriority = env->GetStringUTFChars(bupriority, NULL);
	std::string searchbugpriority = std::string(bugpriority);
	env->ReleaseStringUTFChars(bupriority, bugpriority);
	Bug b;
	ofstream tempFile;
	tempFile.open("search.txt");
	ifstream read;
	read.open("bugmanagement.txt");
	while (!read.eof()) {
		read >> b.bugname;
		read >> b.bugid;
		read >> b.bugpriority;
		read.ignore();
		getline(read, b.bugstatus);
		getline(read, b.bugtime);
		read >> b.bugassignedto;
		if (b.bugpriority == searchbugpriority) {
			printbug(b);
		}
	}
	read.close();
	tempFile.close();
	if (flag == 1) {
		return 1;
	}
	else {
		return 0;
	}
}





