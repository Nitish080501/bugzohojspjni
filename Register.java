package com;
import java.lang.*;
public final class Register {
	static {
		System.load("C:\\Users\\Nitish\\source\\repos\\BugJspC++JNI\\x64\\Debug\\BugJspC++JNI.dll");
	}
	public Register(){
		
	}
	public static native void reg(String name,String mailid,String password);
	public static native int log(String uname,String upass);
}
