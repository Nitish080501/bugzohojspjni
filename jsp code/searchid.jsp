<%@page import="com.*" %>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Search</title>
</head>
<body>
    <form>
    <strong>Enter the Bug ID to search</strong> <input type="number" name="searchBugid"><br>
    <br>
     <input class="button-15" type="submit" value="Enter">
     </form>
     
     <%
       try{
    	   int searchbugid=Integer.parseInt(request.getParameter("searchBugid"));
    	   if(searchbugid >= 0){
         	 	int i=Bug.searchid(searchbugid);
         	 	if(i==1){
          	 		response.sendRedirect("showsearchdetails.jsp");
          	 	}
          	 	else{
          	 		response.sendRedirect("notupdated.jsp");
          	 	}
       		}
       }
     catch(Exception e){
    	 
     }
     %>
</body>
</html>