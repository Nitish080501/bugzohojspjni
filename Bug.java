package com;
import java.lang.*;
public final class Bug {
	static {
		System.load("C:\\Users\\Nitish\\source\\repos\\BugManagementUserFunctions\\x64\\Debug\\BugManagementUserFunctions.dll");
	}
	public Bug(){
		
	}
	public static native void insert(String bugname,String bugpriority,String bugstatus,String bugtime,String createdby,String assigned);
	public static native int updatestatus(int bugid,String cstatus);
	public static native int changeassign(int assignid,String changework);
	public static native int deleterep(int deletebugid);
	public static native int searchid(int searchbugid);
	public static native int searchpriority(String searchbugpriority);
}