#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct library
{
char bk_name[30];
char publisher[30];
int price;
};
int main()
{
struct library l[100];
char pb_nm[30],bk_nm[30];
int i,j,keepcount;
float temp;
i=j=keepcount=0;
clrscr();
printf("\n\n## Library Management ##\n");
while(j!=5)
{
printf("\n1. Add Book Information");
printf("2. Display All Books Available \n");
printf("3. Display Highest Price Book \n");
printf("4. Display list of Publisher \n");
printf("5. Exit");
printf("\n\nEnter one of the above:");
scanf("%d",&j);
switch(j)
{
/* Add Book */
	case 1:
		printf("Enter Book Name:");
		scanf("%s",l[i].bk_name);
		printf("Enter Publisher Name:");
		scanf("%s",l[i].publisher);
		printf("Enter Price:");
		scanf("%d",&l[i].price);
		keepcount++;
		break;

	case 2:
		printf("Display All Book Available \n");
		for(i=0;i<keepcount;i++)
		{
		printf("\n Book name= %s",l[i].bk_name);
		printf("\n Author name= %s",l[i].publisher);
		printf("\t Price= %d",l[i].price);
		}
		break;

	case 3:
		printf("Highest Price Book :");
		for(i=0;i<keepcount;i++)
		{
		if(temp < l[i].price)
		temp=l[i].price;
		}
		printf("%f",temp);
		break;

	case 4:
		printf("List of Publisher:");
		for(i=0;i<keepcount;i++)
		{
			printf("\n %s ",l[i].publisher);
		}
		break;

	case 5:
		exit(0);
}
}
return 0;
}

