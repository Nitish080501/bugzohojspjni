#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct admin{
char name[100];
char mail_id[100];
char password[100];
int age;
char gender[100];
};
struct bug{
char bugname[100];
int bugid;
char bug_danger[100];
char bug_status[100];
char bug_time[100];
char bug_created_by[100];
char bug_assigned_to[100];
};
char * assigning(){
     int choice;
     printf("Assign work to\n");
			printf("1. ADMIN 1\n2. ADMIN 2\n3. ADMIN 3\n4. ADMIN 4\n");
			printf("Enter the choice\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					return "admin1";
					break;
				case 2:
					return "admin2";
					break;
				case 3:
					return "admin3";
					break;
				case 4:
				    return "admin4";
					break;
				default:
					break;
			}
}
void changeassign(){
	int choice,f=0,bugid;
	char creatorname[100];
	struct bug b1;
	FILE *fp2,*fp1;
	fp2 = fopen("bug_reported.txt","r");
	fp1=fopen("uname.txt","w");
	printf("Enter the user name\n");
	scanf("%s",creatorname);
	printf("Enter the bug id\n");
	scanf("%d",&bugid);
	while(fread(&b1,sizeof(struct bug),1,fp2)){
		if(strcmp(b1.bug_created_by,creatorname)==0){
            if(b1.bugid==bugid){
			f=1;
			printf("Assign work to\n");
			printf("1. ADMIN 1\n2. ADMIN 2\n3. ADMIN 3\n4. ADMIN 4\n");
			printf("Enter the choice\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					strcpy(b1.bug_assigned_to,"admin1");
					break;
				case 2:
					strcpy(b1.bug_assigned_to,"admin2");
					break;
				case 3:
					strcpy(b1.bug_assigned_to,"admin3");
					break;
				case 4:
				    strcpy(b1.bug_assigned_to,"admin4");
					break;
				default:
					break;
			}
		}
		printf("\n");
		}
	fwrite(&b1,sizeof(struct bug),1,fp1);
	}
	fclose(fp2);
	fclose(fp1);
	if(f){
		fp1=fopen("uname.txt","r");
		fp2=fopen("bug_reported.txt","w");

		while(fread(&b1,sizeof(struct bug),1,fp1)){
			fwrite(&b1,sizeof(struct bug),1,fp2);
		}
		fclose(fp2);
		fclose(fp1);
	}

}
void checkstatus(){
	time_t now=time(NULL);
	char *string_now=ctime(&now);
	int f=0,choice;
	int sbugname;
	struct bug b1;
	FILE *fp2,*fp1;
	fp2 = fopen("bug_reported.txt","r");
	fp1=fopen("status.txt","w");
	printf("Enter bug id to search\n");
	scanf("%d",&sbugname);
	printf("--------------\n");
	while(fread(&b1,sizeof(struct bug),1,fp2)){
		if(b1.bugid==sbugname){
			f=1;
			//printf("Administrator\n");
			printf("1. IN PROGRESS\n2. FIXED\n3. DELIVERED\n4. ANALYZING\n");
			printf("Enter the choice to change status of the bug\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					strcpy(b1.bug_status,"inprogress");
					strcpy(b1.bug_time,string_now);
					break;
				case 2:
					strcpy(b1.bug_status,"fixed");
					strcpy(b1.bug_time,string_now);
					break;
				case 3:
					strcpy(b1.bug_status,"delivered");
					strcpy(b1.bug_time,string_now);
					break;
				case 4:
					strcpy(b1.bug_status,"analyzing");
					strcpy(b1.bug_time,string_now);
					break;
				default:
					break;
			}
		}
		printf("\n");
	fwrite(&b1,sizeof(struct bug),1,fp1);
	}
	fclose(fp2);
	fclose(fp1);
	if(f){
		fp1=fopen("status.txt","r");
		fp2=fopen("bug_reported.txt","w");

		while(fread(&b1,sizeof(struct bug),1,fp1)){
			fwrite(&b1,sizeof(struct bug),1,fp2);
		}
		fclose(fp2);
		fclose(fp1);
	}
	else{
		printf("The work is assigned\n");
	}
}
void edit_time_and_date(){
	struct bug b1;
	FILE *fp2;
    FILE *fp1;
	fp2 = fopen("bug_reported.txt","r");
	fp1 = fopen("temp.txt","w");
	time_t now=time(NULL);
    struct tm *cur_time=localtime(&now);
    char udandt[100];
    int cho,d,m,y,h,min,f=0;
    int ubugid;
    printf("Enter the bug name to edit the time and date\n");
    scanf("%s",udandt);
    printf("Enter the bug id to edit the time and date\n");
    scanf("%d",&ubugid);
	while(fread(&b1,sizeof(struct bug),1,fp2)){
		if(strcmp(b1.bugname,udandt)==0&&b1.bugid==ubugid){
			f=1;
		do
		{
        printf("\n\n------------------------------------------\n");
	    printf("\n\t1. UPDATE DATE\n\t2. UPDATE MONTH\n\t3. UPDATE YEAR\n\t4. UPDATE TIME_HOUR\n\t5. UPDATE TIME_MIN\n\t6. EXIT\n");
	    printf("\n\n------------------------------------------\n");
	    printf("Enter your choice\n");
	    scanf("%d",&cho);
	    printf("\n");
	    switch(cho)
	    {
	    	    case 1:
		    		printf("Enter an unsigned integer number to add or subract date from present date\n");
		    		scanf("%d",&d);
		    		cur_time->tm_mday=cur_time->tm_mday+d;
					time_t new_timed= mktime(cur_time);
					char *string_nowd=ctime(&new_timed);
					strcpy(b1.bug_time,string_nowd);
					break;
				case 2:
					printf("Enter an unsigned integer number to add or subract month from present month\n");
		    		scanf("%d",&m);
		    		cur_time->tm_mon=cur_time->tm_mon+m;
					time_t new_timem = mktime(cur_time);
					char *string_nowm=ctime(&new_timem);
					strcpy(b1.bug_time,string_nowm);
					break;
				case 3:
					printf("Enter an unsigned integer number to add or subract year from present year\n");
		    		scanf("%d",&y);
		    		cur_time->tm_year=cur_time->tm_year+y;
					time_t new_timey = mktime(cur_time);
					char *string_nowy=ctime(&new_timey);
					strcpy(b1.bug_time,string_nowy);
					break;
				case 4:
					printf("Enter an unsigned integer number to add or subract hour from present hour\n");
		    		scanf("%d",&h);
		    		cur_time->tm_hour=cur_time->tm_hour+h;
					time_t new_timeh = mktime(cur_time);
					char *string_nowh=ctime(&new_timeh);
		            strcpy(b1.bug_time,string_nowh);
		            break;
				case 5:
					printf("Enter an unsigned integer number to add or subract min from present min\n");
		    		scanf("%d",&min);
		    		cur_time->tm_min=cur_time->tm_min+min;
					time_t new_timemin = mktime(cur_time);
					char *string_nowmin=ctime(&new_timemin);
					strcpy(b1.bug_time,string_nowmin);
					break;
				case 6:
					printf("Exit");
	                break;
	            default:
	            	printf("Invalid option\n");
	            	break;
			}
		}while(cho!=6);
	}
	fwrite(&b1,sizeof(struct bug),1,fp1);
	}
	fclose(fp2);
	fclose(fp1);
	if(f){
		fp1=fopen("temp.txt","r");
		fp2=fopen("bug_reported.txt","w");

		while(fread(&b1,sizeof(struct bug),1,fp1)){
			fwrite(&b1,sizeof(struct bug),1,fp2);
		}
		fclose(fp2);
		fclose(fp1);
	}
	else{
		printf("No records found\n");
	}
}
void searchbydate(){
	char date[100],temptime[100];
	struct bug b1;
	FILE *fp2;
	printf("Enter the date to search(Day(in String) Month(in String) Date(in number))\n");
	scanf(" %[^\n]s",date);
	fp2 = fopen("bug_reported.txt","r");
	while(fread(&b1,sizeof(struct bug),1,fp2)){
		int n = strlen(b1.bug_time);
		strcpy(temptime,b1.bug_time);
		temptime[n-15]='\0';
		if(strcmp(temptime,date)==0){
		printf("Bugname    : %s\n",b1.bugname);
		printf("Bug_id     : %d\n",b1.bugid);
		printf("Bug_danger : %s\n",b1.bug_danger);
		printf("Bug_status : %s\n",b1.bug_status);
		printf("Bug_time   : %s\n",b1.bug_time);
		printf("Created_by : %s\n",b1.bug_created_by);
		printf("Assigned to: %s\n",b1.bug_assigned_to);
		printf("\n");
		}
	}
	fclose(fp2);
}
void searchstatus(){
	char sbugname[100];
	struct bug b1;
	FILE *fp2;
	fp2 = fopen("bug_reported.txt","r");
	printf("Enter bug status to search\n");
	scanf("%s",sbugname);
	while(fread(&b1,sizeof(struct bug),1,fp2)){
		if(strcmp(b1.bug_status,sbugname)==0){
		printf("Bugname    : %s\n",b1.bugname);
		printf("Bug_id     : %d\n",b1.bugid);
		printf("Bug_danger : %s\n",b1.bug_danger);
		printf("Bug_status : %s\n",b1.bug_status);
		printf("Bug_time   : %s\n",b1.bug_time);
		printf("Created_by : %s\n",b1.bug_created_by);
		printf("Assigned to: %s\n",b1.bug_assigned_to);
		printf("\n");
	}
	}
	fclose(fp2);
}
void searchdanger(){
	char sbugname[100];
	struct bug b1;
	FILE *fp2;
	fp2 = fopen("bug_reported.txt","r");
	printf("Enter bug danger to search(High or Low)\n");
	scanf("%s",sbugname);
	while(fread(&b1,sizeof(struct bug),1,fp2)){
		if(strcmp(b1.bug_danger,sbugname)==0){
		printf("Bugname    : %s\n",b1.bugname);
		printf("Bug_id     : %d\n",b1.bugid);
		printf("Bug_danger : %s\n",b1.bug_danger);
		printf("Bug_status : %s\n",b1.bug_status);
		printf("Bug_time   : %s\n",b1.bug_time);
		printf("Created_by : %s\n",b1.bug_created_by);
		printf("Assigned to: %s\n",b1.bug_assigned_to);
		printf("\n");
	}
	}
	fclose(fp2);
}
void searchid(){
	int sbugname;
	struct bug b1;
	FILE *fp2;
	fp2 = fopen("bug_reported.txt","r");
	printf("Enter bug id to search\n");
	scanf("%d",&sbugname);
	while(fread(&b1,sizeof(struct bug),1,fp2)){
		if(b1.bugid==sbugname){
		printf("Bugname    : %s\n",b1.bugname);
		printf("Bug_id     : %d\n",b1.bugid);
		printf("Bug_danger : %s\n",b1.bug_danger);
		printf("Bug_status : %s\n",b1.bug_status);
		printf("Bug_time   : %s\n",b1.bug_time);
		printf("Created_by : %s\n",b1.bug_created_by);
		printf("Assigned to: %s\n",b1.bug_assigned_to);
		printf("\n");
	}
	}
	fclose(fp2);
}
void searchname(){
	char sbugname[100];
	struct bug b1;
	FILE *fp2;
	fp2 = fopen("bug_reported.txt","r");
	printf("Enter bug name to search\n");
	scanf("%s",sbugname);
	while(fread(&b1,sizeof(struct bug),1,fp2)){
		if(strcmp(b1.bugname,sbugname)==0){
		printf("Bugname    : %s\n",b1.bugname);
		printf("Bug_id     : %d\n",b1.bugid);
		printf("Bug_danger : %s\n",b1.bug_danger);
		printf("Bug_status : %s\n",b1.bug_status);
		printf("Bug_time   : %s\n",b1.bug_time);
		printf("Created_by : %s\n",b1.bug_created_by);
		printf("Assigned to: %s\n",b1.bug_assigned_to);
		printf("\n");
	}
	}
	fclose(fp2);
}
void deleteentire(){
	if (remove("bug_reported.txt")== 0)
      printf("All Data Deleted successfully\n");
}
void deletecontent(){
	FILE *fp;
	FILE *fp1;
	struct bug b2;
	int f=0; //ubugid;
	char ubug_name[100];
	fp=fopen("bug_reported.txt","r");
	fp1=fopen("copy.txt","w");
	printf("Enter a bug name to delete\n");
	scanf("%s",ubug_name);
//	printf("Enter the bugid to delete");
//	scanf("%d",&ubugid);
	while(fread(&b2,sizeof(struct bug),1,fp)){
		if(strcmp(b2.bugname,ubug_name)==0){
			f=1;
		}
		else{
		fwrite(&b2,sizeof(struct bug),1,fp1);
	}
	}
	fclose(fp);
	fclose(fp1);
	if(f){
		fp1=fopen("copy.txt","r");
		fp=fopen("bug_reported.txt","w");

		while(fread(&b2,sizeof(struct bug),1,fp1)){
			fwrite(&b2,sizeof(struct bug),1,fp);
		}
		fclose(fp);
		fclose(fp1);
	}
	else{
		printf("No records found\n");
	}
}
void update(){
	time_t now=time(NULL);
	char *string_now=ctime(&now);
	FILE *fp;
	FILE *fp1;
	struct bug b2;
	int f=0,ubugid;
	char ubug_name[100];
	fp=fopen("bug_reported.txt","r");
	fp1=fopen("temp.txt","w");
	printf("Enter a bug name to update\n");
	scanf("%s",ubug_name);
	printf("Enter the bugid to update");
	scanf("%d",&ubugid);
	while(fread(&b2,sizeof(struct bug),1,fp)){
		if(strcmp(b2.bugname,ubug_name)==0&&b2.bugid==ubugid){
			f=1;
			printf("Enter the updated bug name\n");
		    scanf("%s",b2.bugname);
		    printf("Enter the bug seriousness(High or Low)?\n");
		    scanf("%s",b2.bug_danger);
		    printf("Enter the bug status\n");
		    scanf("%s",b2.bug_status);
		    strcpy(b2.bug_time,string_now);
		}

		fwrite(&b2,sizeof(struct bug),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(f){
		fp1=fopen("temp.txt","r");
		fp=fopen("bug_reported.txt","w");

		while(fread(&b2,sizeof(struct bug),1,fp1)){
			fwrite(&b2,sizeof(struct bug),1,fp);
		}
		fclose(fp);
		fclose(fp1);
	}
	else{
		printf("No records found\n");
	}
}
void insert(char creator_name[100],int id){
	time_t now=time(NULL);
	char *string_now=ctime(&now);
	FILE *fp1;
	fp1=fopen("bug_reported.txt","a");
	struct bug b;
	struct admin a;
	int assignment;
	printf("Enter the bug name\n");
    scanf("%s",b.bugname);
    b.bugid=id;
    //printf("Enter the bugid\n");
    //scanf("%d",&b.bugid);
    printf("Enter the bug seriousness(High or Low)?\n");
    scanf("%s",b.bug_danger);
    printf("Enter the bug status\n");
    scanf("%s",b.bug_status);
    strcpy(b.bug_time,string_now);
    strcpy(b.bug_created_by,creator_name);
    printf("Do you want to assign the work (Type 1 or 0)\n");
    scanf("%d",&assignment);
    if(assignment==1){
    	strcpy(b.bug_assigned_to,assigning());
	}
    fwrite(&b,sizeof(struct bug),1,fp1);
    fclose(fp1);
}
void display(){
	struct bug b1;
	FILE *fp2;
	fp2 = fopen("bug_reported.txt","r");
	while(fread(&b1,sizeof(struct bug),1,fp2)){
		printf("Bugname    : %s\n",b1.bugname);
		printf("Bug_id     : %d\n",b1.bugid);
		printf("Bug_danger : %s\n",b1.bug_danger);
		printf("Bug_status : %s\n",b1.bug_status);
		printf("Bug_time   : %s\n",b1.bug_time);
		printf("Created_by : %s\n",b1.bug_created_by);
		printf("Assigned to: %s\n",b1.bug_assigned_to);
		printf("---------------------------------\n");
	}
	fclose(fp2);

}
void insideportal(char creator_name[100]){
	    int c,id=0;
	         do
             {
              printf("\n\t----Select your choice---------\n");
              printf("\n\t1. INSERT BUG NAME\n\t2. DISPLAY THE DATA\n\t3. UPDATE THE DATA\n\t4. DELETE THE DATA\n\t5. DELETE ENTIRE DATA\n\t6. SEARCH BY NAME\n\t7. SEARCH BY STATUS\n\t8. SEARCH BY BUG ID\n\t9. SEARCH BY DANGER(HIGH OR LOW)\n\t10. SEARCH BY DATE\n\t11. EDIT TIME AND DATE\n\t12. ASSIGN A WORK\n\t13. CHANGE THE STATUS\n\t14. EXIT\n");
              printf("\n\n------------------------------------------\n");
              printf("\nEnter your choice:");
              scanf("%d",&c);
              printf("\n");
              switch (c)
              {
              case 1:
                  id++;
                  insert(creator_name,id);
                  break;
              case 2:
               display();
               break;
              case 3:
              	update();
              	break;
              case 4:
              	deletecontent();
              	break;
              case 5:
              	deleteentire();
               break;
              case 6:
              	searchname();
              	break;
              case 7:
              	searchstatus();
              	break;
              case 8:
              	searchid();
              	break;
              case 9:
              	searchdanger();
              	break;
              case 10:
              	searchbydate();
              	break;
              case 11:
              	edit_time_and_date();
              	break;
              case 12:
              	changeassign();
              	break;
              case 13:
              	checkstatus();
              	break;
              case 14:
              	exit(0);
              	break;
               default:
               printf("\nYour choice is wrong\nPlease try again...\n");
               break;
              }
          }while(c!=14);
      }
int menu()
{
    int ch;
    printf("1) Create Account\n");
    printf("2) Login\n");
    printf("3) Exit\n");
    printf("Enter your choice :  ");
    scanf("%d",&ch);
    return ch;
}
void login()
{
    char umail_id[100],upassword[100];
    FILE *fp;
    struct admin a;
    printf("-------LOGIN TO YOUR ACCOUNT-------\n\n");
    printf("Enter your mail id\n");
    scanf("%s",umail_id);
    printf("\n");
    printf("Enter Password\n");
    scanf("%s",upassword);
    fp=fopen("login.txt","r");
    while(fread(&a, sizeof(struct admin), 1, fp)){
        if(strcmp(umail_id,a.mail_id) == 0 && strcmp(upassword,a.password)==0)
        {
            printf("Logging in........\n\n");
            printf("-------Welcome to the portal-------\n");
            insideportal(a.name);
        }
        else
        {
            printf("Mail id and Password is Incorrect.\n\n");
        }
    }
    fclose(fp);
}
void createaccount()
{
    struct admin a;
    FILE *fp;
    puts("-----Create Account----");
    printf("\n\n");
    printf("Enter your Name: ");
    fflush(stdin);
    scanf("%[^\n]s",a.name);
    printf("\n");
    printf("Enter your mail_id\n");
    scanf("%s",a.mail_id);
    printf("\n");
    printf("Set your password\n");
    scanf("%s",a.password);
    printf("\n");
    printf("Enter your age\n");
    scanf("%d",&a.age);
    fflush(stdin);
    printf("\n");
    printf("Enter you Gender\n");
    scanf("%s",a.gender);
    printf("\n");
    fp=fopen("login.txt","a");
    if(fp==NULL)
    {
        printf("\nError opened file\n");
        exit (1);
    }
    fwrite(&a,sizeof(struct admin),1,fp);
    fclose(fp);
    printf(" Account Created Successfully.\n");
}
int main(){
	FILE *fp;
	int choice;
	char umail_id[100],upassword[100];
    while (1){
    switch (menu())
    {
        case 1:
            createaccount();
            break;
        case 2:
            login();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice! ");
            break;
        }
    }
    return 0;
}
