#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Patient{
int id;
char name[50];
char date[20];
};

FILE *fp;

void login(){

char user[20],pass[20];

printf("\n===== LOGIN =====");

printf("\nUsername: ");
scanf("%s",user);

printf("Password: ");
scanf("%s",pass);

if(strcmp(user,"admin")==0 &&
strcmp(pass,"1234")==0){

printf("\nLogin Successful!\n");
}
else{

printf("\nWrong Login");
exit(0);
}
}

void addAppointment(){

struct Patient p;

fp=fopen("appointment.txt","a");

printf("\nPatient ID: ");
scanf("%d",&p.id);

printf("Patient Name: ");
scanf("%s",p.name);

printf("Appointment Date: ");
scanf("%s",p.date);

fprintf(fp,"%d %s %s\n",
p.id,p.name,p.date);

fclose(fp);

printf("\nAppointment Added!\n");
}

void trackSchedule(){

struct Patient p;

fp=fopen("appointment.txt","r");

printf("\n===== Schedule List =====");

while(fscanf(fp,"%d %s %s",
&p.id,p.name,p.date)!=EOF){

printf("\nID:%d",p.id);
printf("\nName:%s",p.name);
printf("\nDate:%s\n",p.date);
}

fclose(fp);
}

void searchPatient(){

struct Patient p;

int id,found=0;

printf("\nEnter ID:");
scanf("%d",&id);

fp=fopen("appointment.txt","r");

while(fscanf(fp,"%d %s %s",
&p.id,p.name,p.date)!=EOF){

if(id==p.id){

found=1;

printf("\nPatient Found");
printf("\nName:%s",p.name);
printf("\nDate:%s\n",p.date);
}
}

if(found==0)
printf("\nPatient Not Found");

fclose(fp);
}

void cancelAppointment(){

struct Patient p;
FILE *temp;

int id,found=0;

printf("\nEnter ID:");
scanf("%d",&id);

fp=fopen("appointment.txt","r");
temp=fopen("temp.txt","w");

while(fscanf(fp,"%d %s %s",
&p.id,p.name,p.date)!=EOF){

if(id!=p.id){

fprintf(temp,"%d %s %s\n",
p.id,p.name,p.date);
}
else{

found=1;
}
}

fclose(fp);
fclose(temp);

remove("appointment.txt");
rename("temp.txt",
"appointment.txt");

if(found)
printf("\nAppointment Cancelled");
else
printf("\nID Not Found");
}

int main(){

int choice;

login();

while(1){

printf("\n===== APPOINTMENT MANAGEMENT =====");

printf("\n1.Book Appointment");
printf("\n2.Track Schedule");
printf("\n3.Search Patient");
printf("\n4.Cancel Appointment");
printf("\n5.Exit");

printf("\nChoice:");
scanf("%d",&choice);

switch(choice){

case 1:
addAppointment();
break;

case 2:
trackSchedule();
break;

case 3:
searchPatient();
break;

case 4:
cancelAppointment();
break;

case 5:
exit(0);

default:
printf("\nInvalid");
}
}
}