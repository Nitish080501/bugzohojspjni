#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct admin{
char name[100];
char mail_id[100];
char password[100];
int age;
char gender[100];
}admin;
int main(){
	FILE *fp;
	fp=fopen("Bug Management.txt","r");
	char name[100],mail_id[100],password[100],age,gender[100];
	char umail_id[100],upassword[100];
	fscanf(fp,"%[^\n]s%s%s%d%s",name,mail_id,password,age,gender);
	printf("Enter you mail_id\n");
	scanf("%s",umail_id);
	printf("Enter your password\n");
    scanf("%s",upassword);
    if((strcmp(umail_id,mail_id)==0)&&(strcmp(password,upassword)==0)){
    	printf("------------Login Successful-------------\n");
	}
	else{
		printf("Invalid Credentials\n");
	}
	return 0;
}
