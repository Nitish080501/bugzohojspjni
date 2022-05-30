<%@page import="com.*" %>
<%@page import="java.io.*" %>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
<script>
    $(function(){
    	$(document).on("click",".transferrows",function(){
    		var getselectedvalues=$(".maintable input:checked").parents("tr").clone().appendTo($(".secondtable tbody").add(getselectedvalues));
    		console.log(getselectedvalues);
    	})
    })
    
    $(function(){
    	$(document).on("click",".deleterows",function(){
    		var deleterowsfromtable=$(".secondtable input:checked").parents("tr").remove();
    	})
    })
</script>
<link rel='stylesheet' type='text/css' href='style.css' media='all'/>
<meta name='viewport' content="width=device-width,initial-scale=1">
<meta charset="ISO-8859-1">
<script src="https://kit.fontawesome.com/212374e92a.js" crossorigin="anonymous"></script>
<title>All Bugs Reported Page</title>
<style>
 #mybutton {
  position: absolute;
  top: 100px;
  right: 0;
 }
 #fixedbutton {
    position: fixed;
    bottom: 560px;
    right: 1000px; 
}
</style>
<style>
		* {
			margin: 0;
			padding: 0;
		}
		.navbar {
			display: flex;
			align-items: center;
			justify-content: center;
			position: sticky;
			top: 0;
			cursor: pointer;
		}
		.background {
			background: black;
			background-blend-mode: darken;
			background-size: cover;
		}
		.nav-list {
			width: 70%;
			display: flex;
			align-items: center;
		}
		.logo {
			display: flex;
			justify-content: center;
			align-items: center;
		}
		.nav-list li {
			list-style: none;
			padding: 26px 30px;
		}
		.nav-list li a {
			text-decoration: none;
			color: white;
		}
		.nav-list li a:hover {
			color: grey;
		}
		.rightnav {
			width: 30%;
			text-align: right;
		}
		#search {
			padding: 5px;
			font-size: 17px;
			border: 2px solid grey;
			border-radius: 9px;
		}
		.firstsection {
			background-color: green;
			height: 400px;
		}
		.secondsection {
			background-color: blue;
			height: 400px;
		}
		.box-main {
			display: flex;
			justify-content: center;
			align-items: center;
			color: black;
			max-width: 80%;
			margin: auto;
			height: 80%;
		}
		.firsthalf {
			width: 100%;
			display: flex;
			flex-direction: column;
			justify-content: center;
		}
		.secondhalf {
			width: 30%;
		}
		.secondhalf img {
			width: 70%;
			border: 4px solid white;
			border-radius: 150px;
			display: block;
			margin: auto;
		}
		.text-big {
			font-family: 'Piazzolla', serif;
			font-weight: bold;
			font-size: 35px;
		}
		.text-small {
			font-size: 18px;
		}
		.btn {
			padding: 8px 20px;
			margin: 7px 0;
			border: 2px solid white;
			border-radius: 8px;
			background: none;
			color: white;
			cursor: pointer;
		}
		.btn-sm {
			padding: 6px 10px;
			vertical-align: middle;
		}
		.section {
			height: 400px;
			display: flex;
			align-items: center;
			justify-content: center;
			max-width: 90%;
			margin: auto;
		}
		.section-Left {
			flex-direction: row-reverse;
		}
		.paras {
			padding: 0px 65px;
		}
		.thumbnail img {
			width: 250px;
			border: 2px solid black;
			border-radius: 26px;
			margin-top: 19px;
		}
		.center {
			text-align: center;
		}
		.text-footer {
			text-align: center;
			padding: 30px 0;
			font-family: 'Ubuntu', sans-serif;
			display: flex;
			justify-content: center;
			color: white;
		}
		#icon1{
		   color: white;
		   width: 100%;
		   height:10%;
		   display:flex;
		   align-items:centre;
		}
.button-24 {
  background: #FF4742;
  border: 1px solid #FF4742;
  border-radius: 6px;
  box-shadow: rgba(0, 0, 0, 0.1) 1px 2px 4px;
  box-sizing: border-box;
  color: #FFFFFF;
  cursor: pointer;
  display: inline-block;
  font-family: nunito,roboto,proxima-nova,"proxima nova",sans-serif;
  font-size: 16px;
  font-weight: 800;
  line-height: 16px;
  min-height: 40px;
  outline: 0;
  padding: 12px 14px;
  text-align: center;
  text-rendering: geometricprecision;
  text-transform: none;
  user-select: none;
  -webkit-user-select: none;
  touch-action: manipulation;
  vertical-align: middle;
}

.button-24:hover,
.button-24:active {
  background-color: initial;
  background-position: 0 0;
  color: #FF4742;
}

.button-24:active {
  opacity: .5;
}
</style>
<style>
table, th, td {
  border:1px solid black;
}
</style>
</head>
<body>
       <nav class="navbar background">
		<ul class="nav-list">
			<div class="logo">
				<i id="icon1" class="fa-solid fa-bug"></i>
			</div>
			<li><a href="">   </a></li>
			<li><a href="">   </a></li>
			<li><a href="">   </a></li>
		</ul>
	 </nav>
     <br>
     <h2>Data of Bugs</h2>
     
     <table style="width:100%" class="maintable" >
  <tr>
    <th>Bug name</th>
    <th>Bug id</th>
    <th>Priority</th>
    <th>Status</th>
    <th>Time</th>
    <th>Created By</th>
    <th>Assigned to</th>
    <th>Select</th>
  </tr>
    <%
       int i=0,z=1;
       FileReader fr=new FileReader("C:\\Users\\Nitish\\OneDrive\\Desktop\\bugmanagement.txt");
       BufferedReader br=new BufferedReader(fr);
       String str;
       %><tr><%
       while((str = br.readLine())!=null){
    	   ++i;
    	   out.println("<td>"+str+"</td>");
    	   if(i==7){
    		   %><td><input type="checkbox" ></td>
    		   </tr>
    		   <tr><%
    		   i=0;
    	   }
       }
       br.close();
     %>
     <form>
     <strong>Enter the Bug ID to Delete</strong> <input type="number" name="deletetableBugid">
     <input class="button-24" type="submit" value="Enter"><br>
     </form>
     <input type="button" value="Transfer Selected Data" class="transferrows" id="mybutton">
     <table border="1" class="secondtable">
     <input type="button" value="Delete Selected Rows" class="deleterows"/>
     <input type="submit" value="Back" id="fixedbutton" formaction="adminhomepage.jsp">
      <h3>Work table</h3>
     <tr>
        <th>Bug name</th>
    	<th>Bug id</th>
    	<th>Priority</th>
   	    <th>Status</th>
    	<th>Time</th>
    	<th>Created By</th>
        <th>Assigned to</th>
        <th>Select</th>
      </tr>
     </table>
     <%
     try{
       int j=0;
  	   int deletebugid=Integer.parseInt(request.getParameter("deletetableBugid"));
  	   if(deletebugid >= 0){
       	 	j=Bug.deleterep(deletebugid);
       	 	if(j==1){
        	 		response.sendRedirect("view.jsp");
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