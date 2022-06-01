import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.ListIterator;
import java.util.Scanner;

class Login implements Serializable{
    String name;
    String mailid;
    String password;
    int age;
    String gender;

    public Login(String name, String mailid, String password, int age, String gender) {
        this.name = name;
        this.mailid = mailid;
        this.password = password;
        this.age = age;
        this.gender = gender;
    }
    public String toString(){
        return name+" "+mailid+" "+password+" "+age+" "+gender;
    }
}
class BugDetails implements Serializable{
	String bugname;
	int bugid;
	String bug_danger;
	String bug_status;
	String bugtime;
	String bug_created_by;
	String bug_assigned_to;
	
	BugDetails(String bugname, int bugid, String bug_danger, String bug_status,String bugtime, String bug_created_by, String bug_assigned_to) {
		this.bugname = bugname;
		this.bugid = bugid;
		this.bug_danger = bug_danger;
		this.bug_status = bug_status;
		this.bugtime=bugtime;
		this.bug_created_by = bug_created_by;
		this.bug_assigned_to=bug_assigned_to;
		
	}
	 public String toString()
	    {
	        return bugname+"\t"+bugid+"\t"+bug_danger+"\t\t"+bug_status+"\t"+bugtime+"\t"+bug_created_by+"\t\t"+bug_assigned_to;
	    }
}
public class LoginSystem{
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {
        int choice=-1;
        Scanner sc=new Scanner(System.in);  // int
        Scanner sc1=new Scanner(System.in); // String
        File file = new File("login.txt");
        ArrayList<Login> al = new ArrayList<Login>();
        ObjectOutputStream oos =null;
        ObjectInputStream ois =null;
        ListIterator<Login> li = null;

        if(file.isFile()){
            ois = new ObjectInputStream(new FileInputStream(file));
            al = (ArrayList<Login>)ois.readObject();
            ois.close();
        }
        do{
            System.out.println("1) CREATE NEW ACCOUNT");
            System.out.println("2) LOGIN");
            System.out.println("0) EXIT(Enter zero to exit)");
            System.out.println("Enter your Choice");
            choice=sc.nextInt();
            switch (choice){
                case 1:
                    System.out.println("Enter your Name");
                    String name=sc1.nextLine();
                    System.out.println("Enter your Mail id");
                    String mailid=sc1.nextLine();
                    System.out.println("Set Password");
                    String password=sc1.nextLine();
                    System.out.println("Enter you age");
                    int age=sc.nextInt();
                    System.out.println("Enter your Gender");
                    String gender=sc1.nextLine();
                    al.add(new Login(name,mailid,password,age,gender));
                    oos = new ObjectOutputStream(new FileOutputStream(file));
                    oos.writeObject(al);
                    oos.close();
                    break;
                case 2:
                    int found=0;
                    System.out.println("Enter your name");
                    String uname=sc1.nextLine();
                    System.out.println("Enter your password");
                    String upassword = sc1.nextLine();
                    ois = new ObjectInputStream(new FileInputStream(file));
                    al = (ArrayList<Login>)ois.readObject();
                    ois.close();
                    li = al.listIterator();
                    while(li.hasNext()){
                        Login l =(Login) li.next();
                        if(l.name.equals(uname) && l.password.equals(upassword)){
                            found=1;
                        }
                    }
                    if(found==1){
                        System.out.println("Logging in.........");
                        System.out.println("-----------------------------");
                        System.out.println("\t\tWelcome to the portal");
                        System.out.println("-----------------------------");
                        insideportal(uname);
                    }
                    else{
                        System.out.println("Invalid Credentials");
                    }
                    break;
            }

        }while(choice!=0);
    }
	@SuppressWarnings("unchecked")
	private static void insideportal(String uname) throws FileNotFoundException, IOException, ClassNotFoundException{
		File file1 = new File("BugReport.txt");
	    ArrayList<BugDetails> arr = new ArrayList<BugDetails>();
	    ObjectOutputStream oos =null;
        ObjectInputStream ois =null;
        ListIterator<BugDetails> li = null;
		Scanner sc1 = new Scanner(System.in);
		Scanner sc = new Scanner(System.in);
		if(file1.isFile()){
			    ois = new ObjectInputStream(new FileInputStream(file1));
			    arr = (ArrayList<BugDetails>)ois.readObject();
			    ois.close();
	    }
		int cho,schoice;
		do {
		System.out.println("\n\t1. INSERT BUG NAME\n\t2. DISPLAY THE DATA\n\t3. UPDATE THE DATA\n\t4. SEARCH\n\t5. DELETE BY BUG ID\n\t6. CHANGE THE STATUS\n\t7. ASSIGN A WORK\n\t8. EXIT\n");
        System.out.println("\n\n------------------------------------------\n");
        System.out.println("\nEnter your choice:");
        cho = sc.nextInt();
        switch(cho) {
        case 1:
        	String bugname,bugdanger,bugstatus,creatorname,ibug_assigned_to = null;
    		int bugid;
    		System.out.println("Enter the bug name : ");
    		bugname = sc1.nextLine();
    	    System.out.println("Enter the bugid : ");
    	    bugid = sc.nextInt(); 
    	    System.out.println("Enter the bug priority(High or Low)? : ");
    	    bugdanger = sc1.nextLine();
    	    System.out.println("Enter the bug status : ");
    	    bugstatus = sc1.nextLine();
    	    Date thisDate=new Date();
    	    SimpleDateFormat dateForm= new SimpleDateFormat("dd/MM/YY hh:mm a");
    	    String bugtime = dateForm.format(thisDate);
    	    creatorname=uname;
    	    System.out.println("Do you want assign bug(Type '1'-(yes) or '0'(no)");
    	    int assignment= sc1.nextInt();
    	    if(assignment==1) {
    	    	System.out.println("Assign work to");
    			System.out.println("1. ADMIN 1\n2. ADMIN 2\n3. ADMIN 3\n4. ADMIN 4\n");
    		    System.out.println("Enter the choice\n");
    			int choice=sc1.nextInt();
    			switch(choice){
    				case 1:
    					ibug_assigned_to="admin1";
    					break;
    				case 2:
    					ibug_assigned_to="admin2";
    					break;
    				case 3:
    					ibug_assigned_to="admin3";
    					break;
    				case 4:
    					ibug_assigned_to="admin4";
    					break;
    				default:
    					break;
    	    }
    	    }
    		arr.add(new BugDetails(bugname,bugid,bugdanger,bugstatus,bugtime,creatorname,ibug_assigned_to));
    		oos = new ObjectOutputStream(new FileOutputStream(file1));
            oos.writeObject(arr);
            oos.close();
            break;
        case 2:
        	System.out.println("---------------------");
        	System.out.println("BugName\t\tBugId\tBugPriority\tBugStatus\tTime\t\t\tCreatedBy\tAssignedTo");
        	oos = new ObjectOutputStream(new FileOutputStream(file1));
            oos.writeObject(arr);
            oos.close();
        	li = arr.listIterator();
        	while(li.hasNext()) {
        		System.out.println(li.next());
        	}
        	System.out.println("---------------------");
        	break;
        case 3:
        	int found2=0;
        	Scanner sc3=new Scanner(System.in);
        	System.out.println("Enter Bug ID to update");
            int idu=sc.nextInt();
            li = arr.listIterator();
         	while(li.hasNext()){
        	     BugDetails b = (BugDetails)li.next();
        	     if(b.bugid==idu) {
        	    	 System.out.println("Enter updated bug name");
        	    	 String bugnameu=sc3.nextLine();
        	    	 System.out.println("Enter updated bug priority(High or Low)");
        	    	 String bugpriority=sc1.nextLine();
        	    	 System.out.println("Enter updated bug status");
        	    	 String bugstatusu=sc1.nextLine();
        	    	 Date uthisDate=new Date();
        	    	 SimpleDateFormat dateFormu= new SimpleDateFormat("dd/MM/YY hh:mm a");
        	    	 String bugtimeu = dateFormu.format(uthisDate);
        	    	 int bugidu=b.bugid;
        	    	 String creatornameu=b.bug_created_by;
        	    	 li.set(new BugDetails(bugnameu,bugidu,bugpriority,bugstatusu,bugtimeu,creatornameu,b.bug_assigned_to));
        	    	 found2=1; 
        	     }
        	}
         	if(found2==1){
         		System.out.println("---------------------");
                System.out.println("Updated Successfully");
                oos = new ObjectOutputStream(new FileOutputStream(file1));
                oos.writeObject(arr);
                oos.close();
         	}
         	else {
            System.out.println("Bug id not found");
         	}
        	break;
        case 4:
        	System.out.println("1. SEARCH BY BUG ID\n2. SEARCH BY BUG NAME\n3. SEARCH BY BUG PRIORITY");
        	System.out.println("Enter the choice to Search by mode");
        	schoice=sc.nextInt();
        	int found=0;
        	switch(schoice) {
        	case 1:
        		System.out.println("Enter a bug id to search");
        		int bugid1=sc.nextInt();
        		ois = new ObjectInputStream(new FileInputStream(file1));
                arr = (ArrayList<BugDetails>)ois.readObject();
                ois.close();
             	li = arr.listIterator();
             	System.out.println("BugName\t\tBugId\tBugPriority\tBugStatus\tTime\t\t\tCreatedBy\tAssignedTo");
             	while(li.hasNext()){
            	     BugDetails b = (BugDetails)li.next();
            	     if(b.bugid==bugid1) {
            	    	 System.out.println(b);
            	    	 found = 1;
            	     }
            	}
             	if(found!=1) {
             		System.out.println("Bug id not found");
             	}
            	System.out.println("---------------------");	
        		break;
        	case 2:
        		Scanner sc2=new Scanner(System.in);
        		System.out.println("Enter a bug name to search");
        		String bugname1=sc2.nextLine();
             	li = arr.listIterator();
             	System.out.println("BugName\t\tBugId\tBugPriority\tBugStatus\tTime\t\t\tCreatedBy\tAssignedTo");
             	while(li.hasNext()){
            	     BugDetails b = (BugDetails)li.next();
            	     if(b.bugname.equals(bugname1)) {
            	    	 System.out.println(b);
            	    	 found = 1;
            	     }
            	}
             	if(found!=1) {
             		System.out.println("Bug name not found");
             	}
            	System.out.println("---------------------");	
        		break;
        	case 3:
        		System.out.println("Enter a bug priority to search");
        		String bugpriority=sc1.nextLine();
        		ois = new ObjectInputStream(new FileInputStream(file1));
                arr = (ArrayList<BugDetails>)ois.readObject();
                ois.close();
             	li = arr.listIterator();
             	System.out.println("BugName\t\tBugId\tBugPriority\tBugStatus\tTime\t\t\tCreatedBy\tAssignedTo");
             	while(li.hasNext()){
            	     BugDetails b = (BugDetails)li.next();
            	     if(b.bug_danger.equals(bugpriority)) {
            	    	 System.out.println(b);
            	    	 found = 1;
            	     }
            	}
             	if(found!=1) {
             		System.out.println("Bug priority not found");
             	}
            	System.out.println("---------------------");	
        		
        		break;
        	default:
        		break;
        	}
        	break;
        case 5:
        	ois = new ObjectInputStream(new FileInputStream(file1));
            arr = (ArrayList<BugDetails>)ois.readObject();
            ois.close();
            
        	boolean found1 = false;
        	System.out.println("Enter a bug id to delete");
    		int bugid1=sc.nextInt();
         	li = arr.listIterator();
         	while(li.hasNext()){
        	     BugDetails b = (BugDetails)li.next();
        	     if(b.bugid==bugid1) {
        	    	 li.remove();
        	    	 found1=true;
        	     }
        	}
         	if(found1){
         		System.out.println("---------------------");
                System.out.println("Deleted Successfully");
                oos = new ObjectOutputStream(new FileOutputStream(file1));
                oos.writeObject(arr);
                oos.close();
         	}
         	else {
            System.out.println("Bug id not found");
         	}
         	break;
         case 6:
        	 int cho1=0;
        	 int found3=0;
        	 System.out.println("1) CHANGE STATUS BY BUG ID\n2) CHANGE STATUS BY BUG NAME");
        	 System.out.println("Enter your choice");
        	 cho1=sc.nextInt();
        	 switch(cho1) {
        	 case 1:
        	 System.out.println("Enter the bugid to change the status of the work");
        	 int sbugid=sc.nextInt();
        	 String upbugstatus = null;
        	 li = arr.listIterator();
        	 while(li.hasNext()){
        	     BugDetails b = (BugDetails)li.next();
        	     if(b.bugid==sbugid) {
        	    	 System.out.println("Change the Status to");
                	 System.out.println("1. IN PROGRESS\n2. FIXED\n3. DELIVERED\n4. ANALYZING\n");
                	 int wchoice=sc.nextInt();
                	switch(wchoice) {
              		case 1:
              			upbugstatus = "In Progress";
              			break;
              		case 2:
              			upbugstatus="Fixed";
              			break;
              		case 3:
              			upbugstatus="Delivered";
              			break;
              		case 4:
              			upbugstatus="Analyzing";
              			break;
             	 }
                Date thisDates=new Date();
            	SimpleDateFormat dateForms= new SimpleDateFormat("dd/MM/YY hh:mm a");
            	String bugtimes = dateForms.format(thisDates);
                 li.set(new BugDetails(b.bugname,b.bugid,b.bug_danger,upbugstatus,bugtimes,b.bug_created_by,b.bug_assigned_to));
       	    	 found3=1;
        	     }
        	 }
        	 if(found3==1) {
        		 System.out.println("Status updated....");
        	 }
        	 break;
        	 case 2:
        		 Scanner sc4=new Scanner(System.in);
        		 System.out.println("Enter the bug name to change the status of the work");
            	 String bugnameu =sc4.nextLine();
            	 String ubugstatus = null;
            	 li = arr.listIterator();
            	 while(li.hasNext()){
            	     BugDetails b = (BugDetails)li.next();
            	     if(b.bugname.equals(bugnameu)) {
            	    	 System.out.println("Change the Status to");
                    	 System.out.println("1. IN PROGRESS\n2. FIXED\n3. DELIVERED\n4. ANALYZING\n");
                    	 int wchoice=sc.nextInt();
                    	switch(wchoice) {
                  		case 1:
                  			ubugstatus = "In Progress";
                  			break;
                  		case 2:
                  			ubugstatus="Fixed";
                  			break;
                  		case 3:
                  			ubugstatus="Delivered";
                  			break;
                  		case 4:
                  			ubugstatus="Analyzing";
                  			break;
                 	 }
                    Date thisDates=new Date();
                	SimpleDateFormat dateForms= new SimpleDateFormat("dd/MM/YY hh:mm a");
                	String bugtimes = dateForms.format(thisDates);
                     li.set(new BugDetails(b.bugname,b.bugid,b.bug_danger,ubugstatus,bugtimes,b.bug_created_by,b.bug_assigned_to));
           	    	 found3=1;
            	     }
            	 }
            	 if(found3==1) {
            		 System.out.println("Status updated....");
            	 }
            	 break;
                 }
           break;
         case 7:
        	int found4=0;
        	String ubug_assigned_to = null;
         	Scanner sc5=new Scanner(System.in);
         	System.out.println("Enter Bug ID to Assign a work");
            int idup=sc.nextInt();
            li = arr.listIterator();
          	while(li.hasNext()){
         	     BugDetails b = (BugDetails)li.next();
         	     if(b.bugid==idup) {
         	    	System.out.println("Assign work to");
        			System.out.println("1. ADMIN 1\n2. ADMIN 2\n3. ADMIN 3\n4. ADMIN 4\n");
        		    System.out.println("Enter the choice\n");
        			int choice=sc5.nextInt();
        			switch(choice){
        				case 1:
        					ubug_assigned_to="admin1";
        					break;
        				case 2:
        					ubug_assigned_to="admin2";
        					break;
        				case 3:
        					ubug_assigned_to="admin3";
        					break;
        				case 4:
        					ubug_assigned_to="admin4";
        					break;
         	     }
        		li.set(new BugDetails(b.bugname,b.bugid,b.bug_danger,b.bug_status,b.bugtime,b.bug_created_by,ubug_assigned_to));
        	    found4=1; 
         	    }
        }
          	if(found4==1){
          		System.out.println("---------------------");
                 System.out.println("Updated Successfully");
                 oos = new ObjectOutputStream(new FileOutputStream(file1));
                 oos.writeObject(arr);
                 oos.close();
          	}
          	else {
             System.out.println("Bug id not found");
          	}
         	break;
        	 
        }
	}while(cho!=8);
	}
}

