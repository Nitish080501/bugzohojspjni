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
    <strong>Enter the Bug Priority to search</strong> <input type="text" name="searchBugpriority"><br>
    <br>
     <input class="button-15" type="submit" value="Enter">
     </form>
     <%
     try{
  	   String searchbugpriority=(String)request.getParameter("searchBugpriority");
  	   if(!searchbugpriority.isEmpty()){
       	 	int i=Bug.searchpriority(searchbugpriority);
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