#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <string.h>

typedef struct student 
{
	int rno;
	char name[20];
	struct subject 
	{
		int scode;
		int sname[20];
		int mark;
	} sub [3];
	int total;
	float per;
} student;

void titles(int x)
{
	if (x == 1)
	printf("CREATING RECORDS\n");
	else if (x == 2)
	printf("DISPLAYING PRESENT RECORDS\n");
	else if (x == 3)
	printf("ADDING RECORDS\n");
	else if (x == 4)
	printf("DISPLAYING PRESENT RECORDS\n");
	else if (x == 5)
	printf ("SEARCH FOR A RECORD\n");
	else if (x == 6)
	printf("UPDATING RECORDS\n"); 
	else if (x == 7)
	printf("DELETING RECORD\n");
	else if (x == 8)
	printf("SORTING RECORD BY TOTAL IN DESCENDING\n");
	else if (x == 9)
	printf("SORTING RECORD BY TOTAL IN DESCENDING PERMANENTLY\n");
	else if (x == 10)
	printf("SORTING RECORD ALPHABETICALLY\n");
}

void create() {
	clrscr();
	titles(1);
	student *s;
	int n, i, j;
	printf("How Many Record of Students You Want To Create? ");
	scanf("%d",&n);
	
	FILE *fp;
	s = (student*)calloc(n, sizeof(student));
	fp = fopen("mystudents.txt","w");
	for (i = 0; i < n; i++)
	{
		s[i].total = 0;
		s[i].per = 0;
		
		printf ("Enter RollNo. : ");
		scanf("%d",&s[i]);
		fflush(stdin);
		printf("Enter name :");
		scanf("%[^\n]s",s[i].name);
		
		for (j = 0; j < 3; j++)
		{
			printf("Enter Marks For Subject %d ",j+1);
			scanf("%d",&s[i].sub[j].mark);
			s[i].total += s[i].sub[j].mark;
		}
		s[i].per = s[i].total /3.0;
			fwrite(&s[i],sizeof(student),1,fp);
	}
	fclose(fp);
	}
	
void display () {
	clrscr();
	titles(2);
	student s1;
	int j;
	FILE *fp;
	fp = fopen("mystudents.txt","r");
	while(fread(&s1,sizeof(student),1,fp))
	{
		printf("\n%-5d %-20s",s1.rno,s1.name);
		for(j = 0; j <3; j++)
		{
			printf("%d ",s1.sub[j].mark);
		}
		printf ("%5d %7.2f",s1.total,s1.per);
	}
	fclose(fp);
	}
	
void append() {
	clrscr();
	titles(3);
	student *s;
	int n, i, j;
	FILE *fp;
	printf("How Many Students You Want To Add? ");
	scanf("%d",&n);
	
	s = (student*)calloc(n, sizeof(student));
	fp = fopen("mystudents.txt","a");
	for (i = 0; i < n; i++)
	{
		s[i].total = 0;
		s[i].per = 0;
		
		printf ("Enter RollNo. : ");
		scanf("%d",&s[i]);
		fflush(stdin);
		printf("Enter name :");
		scanf("%[^\n]s",s[i].name);
		
		for (j = 0; j < 3; j++)
		{
			printf("Enter Marks For Subject %d ",j+1);
			scanf("%d",&s[i].sub[j].mark);
			s[i].total += s[i].sub[j].mark;
		}
		s[i].per = s[i].total /3.0;
			fwrite(&s[i],sizeof(student),1,fp);
	}
	fclose(fp);
}

void numofrec()
{
	clrscr();
	titles(4);
	student s1;
	FILE *fp;
	fp = fopen("mystudents.txt","r");
	fseek(fp,0,SEEK_END);
	int n = ftell(fp) /sizeof(student);
	printf("\nNO OF RECORD : %d",n);
	fclose(fp);
}
void search()
{
	clrscr();
	titles(5);
	student s1;
	int j, rno, found = 0;
	FILE *fp;
	fp = fopen("mystudents.txt","r");
	
	printf("Enter RollNo. To Search: ");
	scanf("%d",&rno);
	
	while(fread(&s1,sizeof(student),1,fp))
	{
		if (s1.rno == rno)
		{
		found = 1;
		printf("\n%-5d %-20s",s1.rno,s1.name);
		for(j = 0; j <3; j++)
		{
			printf("%d ",s1.sub[j].mark);
		}
		printf ("%5d %7.2f",s1.total,s1.per);
		}
	}
	if (!found)
	{
		printf("\nRecord Not Found...\n");
	}
	fclose(fp);
}

void update()
{
	clrscr();
	titles(6);
	student s1;
	int j, rno, found = 0;
	FILE *fp, *fpt;
	fp = fopen("mystudents.txt","r");
	fpt = fopen("temp.txt","w");
	printf("Enter RollNo. To Update: ");
	scanf("%d",&rno);
	
	while(fread(&s1,sizeof(student),1,fp))
	{
		if (s1.rno == rno)
		{
			s1.per = 0;
			s1.total = 0;
			found = 1;
			fflush(stdin);
			printf("Enter New name :");
			scanf("%[^\n]s",s1.name);
			
			for (j = 0; j < 3; j++)
			{
				printf("Enter New Marks For Subject %d ",j+1);
				scanf("%d",&s1.sub[j].mark);
				s1.total += s1.sub[j].mark;
			}
			s1.per = s1.total /3.0;
		}
		fwrite(&s1,sizeof(student),1,fpt);
	}
	fclose(fp);
	fclose(fpt);
	
	if (found)
	{
		fpt = fopen("temp.txt","r");
		fp = fopen("mystudents.txt","w");
		
		while(fread(&s1,sizeof(student),1,fpt))
		{
			fwrite(&s1,sizeof(student),1,fp);
		}
		fclose(fpt);
		fclose(fp);
		remove("temp.txt");
	}
	else
	{
		printf("\nRecord Not Found...\n");
	}
}

void delete_rec()
{
	clrscr();
	titles(7);
	student s1;
	int j, rno, found = 0;
	FILE *fp, *fpt;
	fp = fopen("mystudents.txt","r");
	fpt = fopen("temp.txt","w");
	printf("Enter RollNo. To Delete: ");
	scanf("%d",&rno);
	
	while(fread(&s1,sizeof(student),1,fp))
	{
		if (s1.rno == rno)
		{
			found = 1;
		}
		else {
		fwrite(&s1,sizeof(student),1,fpt); }
	}
	fclose(fp);
	fclose(fpt);
	
	if (found)
	{
		fpt = fopen("temp.txt","r");
		fp = fopen("mystudents.txt","w");
		
		while(fread(&s1,sizeof(student),1,fpt))
		{
			fwrite(&s1,sizeof(student),1,fp);
		}
		fclose(fpt);
		fclose(fp);
		remove("temp.txt");
	}
	else
	{
		printf("\nRecord Not Found...\n");
	}
	
}

void sort_total_onscreen()
{
	clrscr();
	titles(8);
	student *s, s1;
	int i = 0, j = 0;
	FILE *fp;
	fp = fopen("mystudents.txt","r");
	fseek(fp,0,SEEK_END);
	int n = ftell(fp)/sizeof(student);
	s = (student*)calloc(n,sizeof(student));
	
	rewind(fp);
	for (i = 0; i < n; i++)
	{
		fread(&s[i], sizeof (student),1,fp);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if(s[i].total < s[j].total)
			{
				s1 = s[i];
				s[i] = s[j];
				s[j] = s1;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("\n%-5d %-20s",s[i].rno,s[i].name);
		for(j = 0; j <3; j++)
		{
			printf("%d ",s[i].sub[j].mark);
		}
		printf ("%5d %7.2f",s[i].total,s[i].per);
	}
	fclose(fp);
}

void sort_total_infile()
{
	clrscr();
	titles(9);
	student *s, s1;
	int i = 0, j = 0;
	FILE *fp;
	fp = fopen("mystudents.txt","r");
	fseek(fp,0,SEEK_END);
	int n = ftell(fp)/sizeof(student);
	s = (student*)calloc(n,sizeof(student));
	
	rewind(fp);
	for (i = 0; i < n; i++)
	{
		fread(&s[i], sizeof (student),1,fp);
	}
	fclose(fp);
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if(s[i].total < s[j].total)
			{
				s1 = s[i];
				s[i] = s[j];
				s[j] = s1;
			}
		}
	}
	fp = fopen("mystudents.txt","w");
	for (i = 0; i < n; i++)
	{
		printf("\n%-5d %-20s",s[i].rno,s[i].name);
		for(j = 0; j <3; j++)
		{
			printf("%d ",s[i].sub[j].mark);
		}
		printf ("%5d %7.2f",s[i].total,s[i].per);
		fwrite (&s[i],sizeof(student),1,fp);
	}
	fclose(fp);
}
void sort_name_onscreen()
{
	clrscr();
	titles(10);
	student *s, s1;
	int i = 0, j = 0;
	FILE *fp;
	fp = fopen("mystudents.txt","r");
	fseek(fp,0,SEEK_END);
	int n = ftell(fp)/sizeof(student);
	s = (student*)calloc(n,sizeof(student));
	
	rewind(fp);
	for (i = 0; i < n; i++)
	{
		fread(&s[i], sizeof (student),1,fp);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if(strcmp(s[i].name,s[j].name) > 0)
			{
				s1 = s[i];
				s[i] = s[j];
				s[j] = s1;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("\n%-5d %-20s",s[i].rno,s[i].name);
		for(j = 0; j <3; j++)
		{
			printf("%d ",s[i].sub[j].mark);
		}
		printf ("%5d %7.2f",s[i].total,s[i].per);
	}
	fclose(fp);
}

int main()
{
	int ch;
	do {
		printf("\n\n1. Create");
		printf("\n2. Display");
		printf("\n3. Append");
		printf("\n4. No. Of Records");
		printf("\n5. Search");
		printf("\n6. Update");
		printf("\n7. Delete Record");
		printf ("\n8. Sort By Total On Screen");
		printf ("\n9. Sort By Total In File Permanently");
		printf("\n10. Sort By Name On Screen");
		printf("\n0. Exit");
		
		printf("\nEnter Your Choice: ");
		scanf ("%d",&ch);
		
		switch(ch)
		{
			case 1:
						create();
			break;
			case 2:
						display();
			break;
			case 3:
						append();
			break;
			case 4: 
						numofrec();
			break;
			case 5: 
						search();
			break;
			case 6:
						update();
			break;
			case 7:
						delete_rec();
			break;
			case 8:
						sort_total_onscreen();
			break;
			case 9:
						sort_total_infile();
			break;
			case 10:
						sort_name_onscreen();
			break;
		}
	} while (ch != 0);
	clrscr();
	printf("Thank You, Have A Nice Day!");
return 0;
}