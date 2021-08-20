#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
int menu(); //Main menu
void add(); //Function to add member into phone directory
void find(); //Function to search a member from the directory
void edit(); //Function to edit the details of a member if
needed
void del(); //Function to delete a member from the directory
void disp(); //Function to display all members in the
directory
struct node
{
char lname[20],fname[20],telno[15];
struct node *next;
};
struct node *start,*temp;
int menu()
{
 int ch,f=1;
 while(f)
 {
 printf("\t\t\tTELEPHONE DIRECTORY\n");
 printf("1.Add\n");
 printf("2.Find\n");
 printf("3.Edit\n");
 printf("4.Delete\n");
 printf("5.Display All Entries\n");
 printf("6.Exit\n");
 printf(" Enter your choice(1-6):");
 scanf("%d", &ch);
 return ch;
 }
}
void add()
{
struct node *ptr,*prev;
temp=(struct node *)malloc(sizeof(struct node));
printf("Enter the First name: ");
scanf("%s",temp->fname);
printf("Enter the Last name:");
scanf("%s",temp->lname);
printf("Enter the Telephone No.: ");
scanf("%s",temp->telno);
temp->next=NULL;
if(start==NULL)
{
 start=temp;
}
else
{
prev=ptr=start;
while(strcmp(temp->fname,ptr->fname)>0)
 {
prev=ptr;
ptr=ptr->next;
 if(ptr==NULL)
 {
 break;
 }
}
if(ptr==prev)
 {
temp->next=start;
start=temp;
 }
else
 {
temp->next=ptr;
prev->next=temp;
}
}
}
void find()
{
struct node *ptr;
char str[20];
if(start==NULL)
 {
printf("\n\t\t\tTelephone Directory is
Empty....\n");
 return;
}
printf("Enter the First Name to be found: ");
scanf("%s",str);
 ptr=start;
 while(strcmp(ptr->fname,str)!=0)
 {
 ptr=ptr->next;
 if(ptr==NULL)
 {
 break;
 }
 }
if(ptr!=NULL)
 {
 printf("\t\t--------------------------------------
\n");
 printf("\t\t\tFirst Name : %s\n",ptr->fname);
 printf("\t\t\tLast Name : %s\n",ptr->lname);
 printf("\t\t\tPhone Number : %s\n",ptr->telno);
 printf("\t\t--------------------------------------
\n");
}
else
 {
printf("No Matching Records Found .......\n");
}
}
void edit()
{
struct node *ptr;
char str[20];
if(start==NULL)
 {
printf("\n\t\t\tTelephone Directory is
Empty....\n");
 return;
}
printf("Enter the First Name to Edit : ");
scanf("%s",str);
 ptr=start;
 while(strcmp(ptr->fname,str)!=0)
 {
 ptr=ptr->next;
 if(ptr==NULL)
 break;
 }
if(ptr!=NULL)
{
printf("Enter the new First Name : ");
 scanf("%s",ptr->fname);
printf("Enter the new Last Name :");
 scanf("%s",ptr->lname);
printf("Enter the new Phone Number :");
 scanf("%s",ptr->telno);
}
else
 {
printf("No Matching Records Found .......\n");
}
}
void del()
{
struct node *ptr,*prev,*temp;
char str[20],yn='n';
if(start==NULL)
 {
printf("\n\t\t\tTelephone Directory is
Empty....\n");
return;
}
printf("Enter the First Name to be deleted : ");
scanf("%s",str);
 prev=ptr=start;
 while(strcmp(ptr->fname,str)!=0)
 {
 prev=ptr;
 ptr=ptr->next;
 if(ptr==NULL)
 break;
 }
if(ptr!=NULL)
{
printf("\nDeleting Record.....Confirm [y/n]: ");
yn=getch();
 printf("\n\n------------------------------------------
---------------");
printf("\nFirst Name : %s\n",ptr->fname);
printf("Last Name : %s\n",ptr->lname);
printf("Phone Number : %s\n",ptr->telno);
 printf("----------------------------------------------
-----------");
if(yn=='y')
{
if(ptr==start)
{
temp=start->next;
free(start);
start=temp;
}
else
{
temp=ptr->next;
free(ptr);
prev->next=temp;
}
printf("\n\n Record Deleted....\n");
}
else
printf("\n\nRecord not Deleted....\n");
}
else
{
printf("\nNo Matching Records Found .......\n");
}
}
void disp()
{
struct node *ptr;
if(start==NULL)
 {
printf("\n\t\t\tTelephone Directory is
Empty....\n");
 return;
}
printf("\t\t------------------------------\n");
for(ptr=start;ptr!=NULL;ptr=ptr->next)
{
printf("\t\tFirst name: %s",ptr->fname);
printf("\n\t\tLast name:%s",ptr->lname);
printf("\n\t\tTelephone No.: %s",ptr->telno);
printf("\n\t\t------------------------------\n");
 }
}
void main()
{
int ch;
start=(struct node *)malloc(sizeof(struct node));
start=NULL;
do{
ch=menu();
switch(ch)
{
case 1: add();
 break;
case 2: find();
 break;
case 3: edit();
 break;
case 4: del();
 break;
case 5: disp();
 break;
}
}while(ch!=6);
}
