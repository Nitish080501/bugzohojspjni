#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct admin{
char name[100];
char mail_id[100];
char password[100];
int age;
char gender[100];
struct admin *link;
}node;
typedef struct bug{
char bugname[100];
int bugid;
char bug_danger[100];
char bug_status[100];
char bug_time[100];
struct bug *next;
}bug;
void login_new(node **q,char sname[100],char smail_id[100],char spassword[100],int sage,char sgender[100]){
    node *nn,*temp;
    nn=(node*)malloc(sizeof(node));
    strcpy(nn->name,sname);
    strcpy(nn->mail_id,smail_id);
    strcpy(nn->password,spassword);
    nn->age=sage;
    strcpy(nn->gender,sgender);
    nn->link=NULL;
    if(*q==NULL){
        *q=nn;
    }
    else{
        temp=*q;
        while(temp->link!=0){
            temp=temp->link;
        }
        temp->link=nn;
    }
}
int login_existing(node *q,char umail_id[100],char upassword[100]){
     while(q!=NULL){
	    if(strcmp(umail_id,q->mail_id)==0&&strcmp(upassword,q->password)==0){
            return 1;
	    }
	    q=q->link;
	}
    return 0;
}
void insert(bug **q,char ibugname[100],int ibugid,char ibug_danger[100],char ibug_status[100]){
    bug *nn,*temp;
    time_t now=time(NULL);
	char *string_now=ctime(&now);
    nn=(bug*)malloc(sizeof(bug));
    strcpy(nn->bugname,ibugname);
    nn->bugid=ibugid;
    strcpy(nn->bug_danger,ibug_danger);
    strcpy(nn->bug_status,ibug_status);
    strcpy(nn->bug_time,string_now);
    nn->next=NULL;
    if(*q==NULL){
        *q=nn;
    }
    else{
        temp=*q;
        while(temp->next!=0){
            temp=temp->next;
        }
        temp->next=nn;
    }
}
void display(bug *q){
	time_t now=time(NULL);
	char *string_now=ctime(&now);
	if(q==NULL){
	    printf("There is no bug detected\n");
	}
	else{
        printf("The bugs noted are listed below\n");
        printf("\tBugname\t\tBug_id\t\tBug_danger\t\tBug_status\t\tBug_reported_time\n");
	    while(q!=NULL){
	        printf("\t%s",q->bugname);
            printf("\t\t%d",q->bugid);
            printf("\t\t%s",q->bug_danger);
            printf("\t\t%s",q->bug_status);
            printf("\t\t%s",q->bug_time);
            printf("\n");
	        q=q->next;
	    }
	}
}
void update(bug **q,char uupdate_bug[100]){
	time_t now=time(NULL);
	char *string_now=ctime(&now);
    bug *temp=*q;
    char updated_bugname[100],updated_bugdanger[100],updated_bugstatus[100];
    int updated_id;
        if(*q==NULL){
            return;
        }
	    else if(strcmp(temp->bugname,uupdate_bug)==0){
	    printf("Enter the updated bug name\n");
	    scanf("%s",updated_bugname);
	    printf("Enter the updated bug id\n");
	    scanf("%d",&updated_id);
	    printf("Enter the updated bug danger\n");
	    scanf("%s",updated_bugdanger);
	    printf("Enter the updated bug status\n");
	    scanf("%s",updated_bugstatus);
	    strcpy(temp->bugname,updated_bugname);
	    temp->bugid=updated_id;
	    strcpy(temp->bug_danger,updated_bugdanger);
	    strcpy(temp->bug_status,updated_bugstatus);
	    strcpy(temp->bug_time,string_now);
	    }
	     else{
	         temp=*q;
	         while(strcmp(temp->bugname,uupdate_bug)!=0){
	             temp=temp->next;
	         }
		    printf("Enter the updated bug name\n");
		    scanf("%s",updated_bugname);
		    printf("Enter the updated bug id\n");
		    scanf("%d",&updated_id);
		    printf("Enter the updated bug danger\n");
		    scanf("%s",updated_bugdanger);
		    printf("Enter the updated bug status\n");
		    scanf("%s",updated_bugstatus);
		    strcpy(temp->bugname,updated_bugname);
		    temp->bugid=updated_id;
		    strcpy(temp->bug_danger,updated_bugdanger);
		    strcpy(temp->bug_status,updated_bugstatus);
		    strcpy(temp->bug_time,string_now);
	     }
}
void search(bug *q,char ssearch_bug[100]){
	bug *temp=q;
	int flag2=0;
	while(temp!=NULL){
	    if(strcmp(temp->bugname,ssearch_bug)==0){
	    	printf("\tBugname\t\tBug_id\t\tBug_danger\t\tBug_status\t\tBug_reported_time\n");
	        printf("\t\t%s",temp->bugname);
	        printf("\t\t%d",temp->bugid);
	        printf("\t\t%s",temp->bug_danger);
	        printf("\t\t%s",temp->bug_status);
	        printf("\t\t%s",temp->bug_time);
	        flag2=1;
	    }
	    temp=temp->next;
	}
	if(flag2==0){
		printf("There is no bug found in this name\n");
	}
	
}
void updatetime(bug **q,char ubugdandt[100]){
	bug *temp=*q;
	time_t now=time(NULL);
    struct tm *cur_time=localtime(&now);  
	int cho,d,m,y,h,min
	;
	    if(*q==NULL){
            return;
        }
	    else if(strcmp(temp->bugname,ubugdandt)==0){
	    do
        {
        printf("\n\n------------------------------------------\n");
	    printf("\n\t1. UPDATE DATE\n\t2. UPDATE MONTH\n\t3. UPDATE YEAR\n\t4. UPDATE TIME_HOUR\n\t5. UPDATE TIME_MIN\n\t6. DISPLAY\n\t7. EXIT\n");
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
					strcpy(temp->bug_time,string_nowd);	
					break;
				case 2:
					printf("Enter an unsigned integer number to add or subract month from present month\n");
		    		scanf("%d",&m);
		    		cur_time->tm_mon=cur_time->tm_mon+m;
					time_t new_timem = mktime(cur_time);
					char *string_nowm=ctime(&new_timem);
					strcpy(temp->bug_time,string_nowm);
					break;
				case 3:
					printf("Enter an unsigned integer number to add or subract year from present year\n");
		    		scanf("%d",&y);
		    		cur_time->tm_year=cur_time->tm_year+y;
					time_t new_timey = mktime(cur_time);
					char *string_nowy=ctime(&new_timey);
					strcpy(temp->bug_time,string_nowy);
					break;
				case 4:
					printf("Enter an unsigned integer number to add or subract hour from present hour\n");
		    		scanf("%d",&h);
		    		cur_time->tm_hour=cur_time->tm_hour+h;
					time_t new_timeh = mktime(cur_time);
					char *string_nowh=ctime(&new_timeh);
		            strcpy(temp->bug_time,string_nowh);
		            break;
				case 5:
					printf("Enter an unsigned integer number to add or subract min from present min\n");
		    		scanf("%d",&min);
		    		cur_time->tm_min=cur_time->tm_min+min;
					time_t new_timemin = mktime(cur_time);
					char *string_nowmin=ctime(&new_timemin);
					strcpy(temp->bug_time,string_nowmin);
					break;
				case 6:
	               display(*q);
	               break;
				case 7:
					printf("Exit\n");
	                break;
	            default:
	            	printf("Invalid option\n");
	            	break;
			}
		}while(cho!=7);
	    }
	     else{
	         temp=*q;
	         while(strcmp(temp->bugname,ubugdandt)!=0){
	             temp=temp->next;
	         }
		     do
	        {
	        printf("\n\n------------------------------------------\n");
		    printf("\n\t1. UPDATE DATE\n\t2. UPDATE MONTH\n\t3. UPDATE YEAR\n\t4. UPDATE TIME_HOUR\n\t5. UPDATE TIME_MIN\n\t6. DISPLAY\n\t7. EXIT\n");
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
					strcpy(temp->bug_time,string_nowd);	
					break;
				case 2:
					printf("Enter an unsigned integer number to add or subract month from present month\n");
		    		scanf("%d",&m);
		    		cur_time->tm_mon=cur_time->tm_mon+m;
					time_t new_timem = mktime(cur_time);
					char *string_nowm=ctime(&new_timem);
					strcpy(temp->bug_time,string_nowm);
					break;
				case 3:
					printf("Enter an unsigned integer number to add or subract year from present year\n");
		    		scanf("%d",&y);
		    		cur_time->tm_year=cur_time->tm_year+y;
					time_t new_timey = mktime(cur_time);
					char *string_nowy=ctime(&new_timey);
					strcpy(temp->bug_time,string_nowy);
					break;
				case 4:
					printf("Enter an unsigned integer number to add or subract hour from present hour\n");
		    		scanf("%d",&h);
		    		cur_time->tm_hour=cur_time->tm_hour+h;
					time_t new_timeh = mktime(cur_time);
					char *string_nowh=ctime(&new_timeh);
		            strcpy(temp->bug_time,string_nowh);
		            break;
				case 5:
					printf("Enter an unsigned integer number to add or subract min from present min\n");
		    		scanf("%d",&min);
		    		cur_time->tm_min=cur_time->tm_min+min;
					time_t new_timemin = mktime(cur_time);
					char *string_nowmin=ctime(&new_timemin);
					strcpy(temp->bug_time,string_nowmin);
					break;
				case 6:
	               display(*q);
	               break;
				case 7:
					printf("Exit\n");
	                break;
	            default:
	            	printf("Invalid option\n");
	            	break;	
				}
			}while(cho!=7);
		    }
}
int main() {
	struct admin *p ;
	struct bug *b;
	b=NULL;
	p=NULL;
	int age,bugid;
	char name[100],mail_id[100],password[100],gender[100],umail_id[100],bugname[100],bug_danger[100],bug_status[100],upassword[100];
	char update_bug[100],search_bug[100],bug_dandt[100];
	int choice=1,c;
while(choice>=1 && choice<3)
{
	printf("1.Login into existing account\n2.Create new account\n3.Exit\nEnter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		    printf("Enter you mail_id\n");
		    scanf("%s",umail_id);
		    printf("Enter your password\n");
            scanf("%s",upassword);
			if(login_existing(p,umail_id,upassword)){
                printf("Login successful\n");
                printf("\t-------Welcome to the portal------\n");
              do
              {
              printf("\n\t----Select your choice---------\n");
              printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. UPDATE\n\t4. SEARCH FOR BUG AND DISPLAY THE SEARCHED BUG\n\t5. EDIT TIME AND DATA\n\t6. EXIT\n");
              printf("\n\n------------------------------------------\n");
              printf("\nEnter your choice:");
              scanf("%d",&c);
              printf("\n");
              switch (c)
              {
              case 1:
                  printf("Enter the bug name\n");
                  scanf("%s",bugname);
                  printf("Enter the bugid\n");
                  scanf("%d",&bugid);
                  printf("Enter the bug seriousness(High or Low)?\n");
                  scanf("%s",bug_danger);
                  printf("Enter the bug status\n");
                  scanf("%s",bug_status);
                  insert(&b,bugname,bugid,bug_danger,bug_status);
                  break;
              case 2:
               display(b);
               break;
              case 3:
              	printf("Enter the name of bug to be updated\n");
              	scanf("%s",update_bug);
              	update(&b,update_bug);
              	break;
              case 4:
              	printf("Enter the name of the bug to display it's details\n");
              	scanf("%s",search_bug);
              	search(b,search_bug);
              	break;
              case 5:
              	printf("Enter the bugname to edit the time and date of that bug\n");
              	scanf("%s",bug_dandt);
              	updatetime(&b,bug_dandt);
              	break;
              case 6:
               printf("Exit\n");
               break;
              default:
               printf("\nYour choice is wrong\nPlease try again...\n");
               break;
              }
             }while(c!=6);
			}
			else{
                printf("\tInvalid Credentials\n");
                printf("\n");
			}
			break;
		case 2:
		    printf("Enter your name\n");
		    scanf("%s",name);
		    printf("Enter your mail_id\n");
		    scanf("%s",mail_id);
		    printf("Set Password\n");
		    scanf("%s",password);
		    printf("Enter your age\n");
		    scanf("%d",&age);
		    printf("Enter your gender\n");
		    scanf("%s",gender);
			login_new(&p,name,mail_id,password,age,gender);
			printf("\tRegistration successful\n");
			printf("\n");
			break;
		case 3:
			printf("Exit\n");
			break;
		}
	}
	return 0;
}
