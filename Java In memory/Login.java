import java.util.*;
import java.text.SimpleDateFormat;
import java.time.*;
class BugDetails{
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
	public String getBug_assigned_to() {
		return bug_assigned_to;
	}
	public void setBug_assigned_to(String bug_assigned_to) {
		this.bug_assigned_to = bug_assigned_to;
	}
	public String getBugname() {
		return bugname;
	}
	public void setBugname(String bugname) {
		this.bugname = bugname;
	}
	public int getBugid() {
		return bugid;
	}
	public void setBugid(int bugid) {
		this.bugid = bugid;
	}
	public String getBug_danger() {
		return bug_danger;
	}
	public void setBug_danger(String bug_danger) {
		this.bug_danger = bug_danger;
	}
	public String getBug_status() {
		return bug_status;
	}
	public void setBug_status(String bug_status) {
		this.bug_status = bug_status;
	}
	public String getBug_created_by() {
		return bug_created_by;
	}
	public void setBug_created_by(String bug_created_by) {
		this.bug_created_by = bug_created_by;
	}
	public String getBugtime() {
		return bugtime;
	}
	public void setBugtime(String bugtime) {
		this.bugtime = bugtime;
	}
	void display(){
		System.out.println("-----------------------------");
		System.out.println("Bug name       :" + bugname);
		System.out.println("Bug id         :" + bugid );
		System.out.println("Bug priority   :" + bug_danger );
		System.out.println("Bug status     :" + bug_status );
		System.out.println("Bug time       :" + bugtime );
		System.out.println("Bug created by :" + bug_created_by );
		System.out.println("Bug Assigned to:" + bug_assigned_to);
	}
}
class LoginPortal {
	String name;
	String mailid;
	String password;
	int age;
	String gender;
	
	LoginPortal(String name,String mailid,String password,int age,String gender){
		this.name=name;
		this.mailid=mailid;
		this.password=password;
		this.age=age;
		this.gender=gender;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getMailid() {
		return mailid;
	}
	public void setMailid(String mailid) {
		this.mailid = mailid;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getGender() {
		return gender;
	}
	public void setGender(String gender) {
		this.gender = gender;
	}
}
public class Login{
	static LoginPortal[] log = new LoginPortal[30];
	static int count=0;
	
	static BugDetails[] Bug = new BugDetails[100];
	static int c=0;
	
	public static int Validate(String name, String password) {
		String id,passwd;
		for(int i=0;i<count;i++) {
			id=log[i].getName();
			passwd=log[i].getPassword();
			if(id.equals(name) && passwd.equals(password)) {
					return 1;
			}
			else {
					return 0;
				
			}
			}
		return 0;
			
	}
	private static void insideportal(String name) {
		Scanner sc = new Scanner(System.in);
		Scanner sc1 = new Scanner(System.in);
		int id1,h;
		int cho,schoice;
		do {
		System.out.println("\n\t1. INSERT BUG NAME\n\t2. DISPLAY THE DATA\n\t3. UPDATE THE DATA\n\t4. SEARCH\n\t5. ASSIGN A WORK\n\t6. CHANGE THE STATUS\n\t8. EXIT\n");
        System.out.println("\n\n------------------------------------------\n");
        System.out.println("\nEnter your choice:");
        cho = sc.nextInt();
        switch(cho) {
        case 1:
            insert(name);
            break;
        case 2:
        	displayBug();
        	break;
        case 3:
        	System.out.println("Enter Bug ID to update");
            id1=sc.nextInt();
            System.out.println("Enter Updated Bug Name");
            name=sc1.nextLine();
            System.out.println("Enter Updated Bug status");
            String bugstatus = sc1.nextLine();
            System.out.println("Enter Updated Bug priority");
            String bugdanger = sc1.nextLine();
        	h=update(id1,name,bugstatus,bugdanger);
        	break;
        case 4:
        	System.out.println("1. SEARCH BY BUG ID\n2. SEARCH BY BUG NAME\n3. SEARCH BY BUG PRIORITY");
        	System.out.println("Enter the choice to Search by mode");
        	schoice=sc.nextInt();
        	switch(schoice) {
        	case 1:
        		System.out.println("Enter a bug id to search");
        		int bugid=sc.nextInt();
        		searchbugid(bugid);
        		break;
        	case 2:
        		System.out.println("Enter a bug name to search");
        		String bugname=sc1.nextLine();
        		searchbugname(bugname);
        		break;
        	case 3:
        		System.out.println("Enter a bug priority to search");
        		String bugpriority=sc1.nextLine();
        		searchpriority(bugpriority);
        		break;
        	default:
        		break;
        	}
        	break;
         case 5:
        	 System.out.println("Enter the bugid to change the assignment to work");
        	 int bugid=sc.nextInt();
        	 assignwork(bugid);
        	 break;
         case 6:
        	 System.out.println("Enter the bugid to change the status of the work");
        	 int sbugid=sc.nextInt();
        	 String bug_status = null;
        	 System.out.println("Change the Status to");
        	 System.out.println("1. IN PROGRESS\n2. FIXED\n3. DELIVERED\n4. ANALYZING\n");
        	 int wchoice=sc.nextInt();
        	 switch(wchoice) {
         		case 1:
         			bug_status = "In Progress";
         			break;
         		case 2:
         			bug_status="Fixed";
         			break;
         		case 3:
         			bug_status="Delivered";
         			break;
         		case 4:
         			bug_status="Analyzing";
         			break;
        	 
        	 }
        	 changestatus(sbugid,bug_status);
        	 break;
         case 7:
        	 break;
        }	
	}while(cho!=7);
	}
	private static void changestatus(int sbugid, String bugstatus) {
		for(int i=0;i<c;i++) {
			int id = Bug[i].getBugid();
			if(id==sbugid) {
				Bug[i].setBug_status(bugstatus);
			}
		}
		
	}
	private static void assignwork(int bugid) {
		Scanner sc= new Scanner(System.in);
		for(int i=0;i<c;i++) {
			int id = Bug[i].getBugid();
			if(id==bugid) {
				System.out.println("Assign work to");
				System.out.println("1. ADMIN\n2. ADMIN\n3. ADMIN\n4. ADMIN\n");
				int choi= sc.nextInt();
				switch(choi) {
				case 1:
					Bug[i].setBug_assigned_to("admin 1");
					break;
				case 2:
					Bug[i].setBug_assigned_to("admin 2");
					break;
				case 3:
					Bug[i].setBug_assigned_to("admin 3");
					break;
				case 4:
					Bug[i].setBug_assigned_to("admin 4");
					break;
				
				}
					
			}
		}
	}
	private static void searchpriority(String bugpriority) {
		for(int i=0;i<c;i++) {
			String id = Bug[i].getBug_danger();
			if(id==bugpriority) {
				Bug[i].display();
			}
		}
		
	}
	private static void searchbugname(String bugname) {
		for(int i=0;i<c;i++) {
			String id = Bug[i].getBugname();
			if(id==bugname) {
				Bug[i].display();
			}
		}
		
	}
	private static void searchbugid(int bugid) {
		for(int i=0;i<c;i++) {
			int id = Bug[i].getBugid();
			if(id==bugid) {
				Bug[i].display();
			}
		}
		
	}
	private static int update(int id1,String name,String bugstatus,String bugdanger) {
		int id;
		for(int i=0;i<c;i++) {
			id=Bug[i].getBugid();
			if(id==id1) {
				Bug[i].setBugname(name);
				Bug[i].setBug_status(bugstatus);
				Bug[i].setBug_danger(bugdanger);
				return 1;
			}
		}
		return 0;
	}
	private static void insert(String name) {
		String bugname,bugdanger,bugstatus,creatorname,bug_assigned_to = null;
		int bugid;
		Scanner sc=new Scanner(System.in);
		Scanner sc1=new Scanner(System.in);
		System.out.print("Enter the bug name : ");
		bugname = sc.nextLine();
	    System.out.print("Enter the bugid : ");
	    bugid = sc1.nextInt(); 
	    System.out.print("Enter the bug priority(High or Low)? : ");
	    bugdanger = sc.nextLine();
	    System.out.println("Enter the bug status : ");
	    bugstatus = sc.nextLine();
	    Date thisDate=new Date();
	    SimpleDateFormat dateForm= new SimpleDateFormat("dd/MM/YY hh:mm a");
	    String bugtime = dateForm.format(thisDate);
	    creatorname=name;
	    System.out.println("Do you want assign bug(Type '1'-(yes) or '0'(no)");
	    int assignment= sc1.nextInt();
	    if(assignment==1) {
	    	System.out.println("Assign work to");
			System.out.println("1. ADMIN 1\n2. ADMIN 2\n3. ADMIN 3\n4. ADMIN 4\n");
		    System.out.println("Enter the choice\n");
			int choice=sc1.nextInt();
			switch(choice){
				case 1:
					bug_assigned_to="admin1";
					break;
				case 2:
					bug_assigned_to="admin2";
					break;
				case 3:
					bug_assigned_to="admin3";
					break;
				case 4:
					bug_assigned_to="admin4";
					break;
				default:
					break;
	    }
	    }
	    Bug[c]=new BugDetails(bugname,bugid,bugdanger,bugstatus,bugtime,creatorname,bug_assigned_to);
	    c++;
	}
	private static void displayBug(){
		for(int i=0;i<c;i++) {
			Bug[i].display();
		}
	}
	public static void main(String[] args) {
	  Scanner sc = new Scanner(System.in);
	  Scanner sc1 = new Scanner(System.in);
	  int ch;
	  do {
		  System.out.println("1. CREATE NEW ACCOUNT");
		  System.out.println("2. LOGIN EXISTING USER");
		  System.out.println("3. EXIT");
		  ch=sc1.nextInt();
		  
		  switch(ch){
		  case 1:
			  System.out.print("Enter your name : ");
			  String name=sc.nextLine();
			  System.out.print("Enter your mailid : ");
			  String mailid=sc.nextLine();
			  System.out.print("Set Password : ");
			  String password=sc.nextLine();
			  System.out.print("Enter your age : ");
			  int age=sc1.nextInt();
			  System.out.print("Enter your gender : ");
			  String gender=sc.nextLine();
			  log[count]=new LoginPortal(name,mailid,password,age,gender);
			  count++;
			  break;
		  case 2:
			  System.out.println("Enter Your Name");
			  String name1=sc.nextLine();
			  System.out.println("Enter your password");
			  String pass=sc.nextLine();
			  int choice = Validate(name1,pass);
			  if(choice==1) {
				  System.out.println("Logging in....");
				  System.out.println("---------------------");
				  System.out.println("Welcome to the portal");
				  System.out.println("---------------------");
				  insideportal(name1);
			  }
			  else {
				  System.out.println("Mailid or password incorrect");
			  }
			  break;
		  }
	  }while(ch!=3);
}
}
	
