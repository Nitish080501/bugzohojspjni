<%@page import="com.*" %>
<%@page import="java.io.*" %>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Details</title>
</head>
<body>
    <%
    FileReader fr=new FileReader("C:\\Users\\Nitish\\OneDrive\\Desktop\\search.txt");
    BufferedReader br=new BufferedReader(fr);
    String str;
    while((str = br.readLine())!=null){
 	   out.println(str);
 	   %><br><%
    }
    br.close();
    %>
</body>
</html>