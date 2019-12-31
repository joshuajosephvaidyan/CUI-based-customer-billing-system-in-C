#include <stdio.h>
#include<conio.h>
#include<string.h>
int dobilling(int);
int invcheck(int);
struct inventory
{
int invno;
char proname[25];
float ppu;
/*int amount;*/
}i;
int main()
{
FILE *fp;int choice,billno=0;
char title[40]="Customer Billing System ",passworde[10],passwordo[10]="PASSWORD";
printf("\t\t\t\t\t\t%s\t\t\t\t\t\t\n",title);
printf("\n");
printf("\nWelcome to CUSTOMER BILLING SYSTEM ");
printf("\n\n");
choice:
while(1)
{
printf("\nTo continue select an option\n1.Do billing.\n2.Check inventory.\n3.Exit.\n\n");
scanf("%d",&choice);
switch(choice)
{
case 1:++billno;
dobilling(billno);
break;
case 2:invcheck(1);
break;
case 3:printf("\nEnter ADMIN PASSWORD:\n");
scanf("%s",passworde);
if(strcmp(passwordo,passworde)==0)
goto exit;
else
printf("ACCESS DENIED\n");
break;
default:printf("Please enter a valid choice\n");
goto choice;
}
}
exit:
return 0;
}
int dobilling(int billno)
{
char user[20];FILE *fp;FILE *fs;int pay,k,n,quantity,cb,j=0;float
total[1000],gt=0,cash;
fs=fopen("bills.txt","a+");
fp=fopen("inv.txt","r");
printf("Enter billing operator name:\n");
scanf("%s",&user);
printf("Bill no:%d\n",billno);
printf("Operator Name:%s\n",user);
fprintf(fs,"\nBILL NO:%d \n",billno);
fprintf(fs," BILLING OPERATOR:%s\n",user);
repeat:
printf("\nEnter inv code[0 FOR EXIT]:");
scanf("%d",&n);
while(fscanf(fp,"%d %s %f",&i.invno,&i.proname,&i.ppu)!=EOF)
{
if(n==i.invno&&n!=0)
{
printf("\n%d.Product name:%s",j+1,i.proname);
printf("\n Price per unit:%5.2f",i.ppu);
printf("\n Enter quantity:");
scanf("%d",&quantity);
printf(" Amount:%5.2f\n",total[j]=i.ppu*quantity);
fprintf(fs,"\n%d %25s \t%5.2f \t%d \t%5.2f",j+1,i.proname,i.ppu,quantity,total[j]);
++j;
}
if(n==0)
goto sum;
}
rewind(fp);
goto repeat;
sum:
for(k=0;k<j;k++)
{
gt=gt+total[k];
}
carry:
printf("\nDo you want a carry bag?[Y=1 / N=0]Additional 5 Rupees\n");
scanf("%d",&cb);
if(cb==1)
{
gt=gt+5;
fprintf(fs,"\nCARRY BAG CHARGES LEVIED\n");
}
printf("\nTotal number of items purchased:%d",j);
printf("\nGrand total is %7.2f\n",gt);
gtc:
printf("\nEnter payment mode:\n1.CASH\n2.CARD\n");
scanf("%d",&pay);
switch(pay)
{
case 1:fprintf(fs,"\nMODE:CASH");
printf("\nCash recieved:");
scanf("%f",&cash);
if(cash<gt)
{
printf("\nInsufficient cash");
goto gtc;
}
float change=cash-gt;
printf("\nChange=%7.2f",change);
printf("\nThank you for shopping with us\nDetailed bill in print format available at Bill.txt \n");
printf("\n--------------------------------------------------------------------------------");
break;
case 2:fprintf(fs,"\nMODE:CARD");
printf("\nYour account will be debited with %f\n\n",gt);
printf("\nThank you for shopping with us\nDetailed bill in print format available at bill.txt\n");
printf("\n--------------------------------------------------------------------------------");
break;
}
fprintf(fs,"\nGrand total=%5.2f\n",gt);
fprintf(fs,"\n-------------------------------------------------------------------------------\n");
return 0;
}
int invcheck(int b)
{
FILE *fp;
int i=0,n,p,choice;
char s[25],passworde[10],passwordo[10]="PASSWORD";
char title[40]="INVENTORY LIST";
printf("\t\t\t %s \t\t\t",title);
printf("\n");
printf("INVCODE PRODUCTNAME PRICEPERUNIT\n");
fp=fopen("inv.txt","a+");
while(fscanf(fp,"%d%s%d",&n,&s,&p)!=EOF)
{
printf("%d %25s ",n,s);
printf("\t\t%d\n",p);
}
invcontrl:
printf("\nDo you want to add an inventory?[1(FOR YES)/0(FOR NO)]\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("\nEnter ADMIN PASSWORD:\n");
scanf("%s",passworde);
if(strcmp(passwordo,passworde)==0)
{
printf("\nACCESS GRANTED:\n");
printf("\nEnter inventory code:(%d-1999):",n+1);
scanf("%d",&n);
printf("\nEnter product name(in Caps):");
scanf("%s",&s);
printf("\nEnter the Price per unit:");
scanf("%d",&p);
printf("\nSuccessfully added to inventory!!");
fprintf(fp,"\n%d %s %d",n,s,p);
printf("\n--------------------------------------------------------------------------------");
}
else
{
printf("\nAccess Denied\n");
printf("\n--------------------------------------------------------------------------------");
}
break;
case 0:printf("\n--------------------------------------------------------------------------------");
break;
default:goto invcontrl;
}
return 0;
}
