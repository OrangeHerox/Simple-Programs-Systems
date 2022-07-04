#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
/*for clrscr() */

char choice1(char x);
int login ();
void title();
void titlelogin(int x);
void welcome();
int logg = 0;//to know if the user is already logged in
int tries = 5; //how many tries you have to try logging in
char view();
char edit();
int linecounter();
int numlen(int n);
void display ();

//MAKE THE CODE SHORTER 
//AND EASIER TO READ 

int main ()
{
	title();
  //declarations
	char choice;
	
	while(1)//choices : //goto statement
	{
	welcome();
	scanf(" %c",&choice);
	
	switch(choice1(choice))
 {
 	case '0' :
 	{
 		if (logg != 1 && login() == 1) {
 			 title();
 			 printf("\n\t\tLOGIN SUCCESS!\n");
 			 logg++;
 		 }
 		 else 
 		 { 
 		 printf("\n\tYOU ARE ALREADY LOGGED IN...\n"); 
 		 }
 					//goto choices; //goto statement
 		break; //break the switch enter the loop again
 	} //end case 0
 	case '1':
 	{
 		if (view() == 'X')
 		{
 			clrscr();
 			title();
 			//goto choices; //goto statement
 		}
		break; //break the switch enter the loop again
 	}
 	case '2': 
 	{
 		titlelogin(4);
 		if (edit() == 'D')
 		{
 		clrscr();
 		title();
 	//goto choices; //goto statement
 		}
 		break; //break the switch enter the loop again
 	}
 	case '3':
 	{
 		printf("\nThank You, Have A Nice Day Ahead...");
 		exit(EXIT_SUCCESS);
 		return 0; //breaking the while loop
 	}
    }
	}
  return 0;
}

char choice1(char x)
{
	while(x)
	{
	if (x == '0')
	{
		clrscr();
		title();
  	break;
	}
	else if (x == '1' || x == '2')
	{
		if (logg == 0)
		 { 
		printf("You Need To Login First!\n==> ::: ");
		scanf(" %c",&x);
		 }
		 else
		{
			clrscr();
			title();
			break;
		}
		 	
	}
	else if (x == '3')
	{
		clrscr();
		title();
		return x;
	}
	else {
	printf("PLEASE ENTER A VALID FUNCTION No :: ");
	scanf(" %c",&x); }
	}
	return x;
}
int login()
{
	char lc;
	char username[30],  password[30];
	char uname[30], pw[30];
	char buff[100];

        FILE *fp;
//	fp = fopen("LoginRegister.txt","r"); //open
	//fgets(buff,100,fp); 
//	fscanf(fp,"%s",username); 
//	fscanf(fp,"%s",password); 
//	fclose(fp); 
	
	titlelogin(1);
	scanf(" %c",&lc);
	while(lc)
	{
	if (lc == 'A')
	{
		if (tries != 0) 
		{
	tries--;
	fp = fopen("LoginRegister.txt","r"); //open
	printf("\nUsername : ");
	scanf("%s",uname);
	printf("Password : ");
	scanf("%s",pw);
	
	while (fgets(buff,100,fp) != NULL)
	  	{
			fscanf(fp,"%s%s",username,password);
	if ( (strcmp(username,uname) == 0 ) && (strcmp(password,pw) == 0 ) )
	{
		title();
		titlelogin(1);
		clrscr();
		return 1;
		break;
	}
	else 
	{
		clrscr(); 
		title();
		titlelogin(1);
		printf("\n\t\tIncorrect Email Or Password\n\t\tRemaining Tries %d...\n",tries);
		continue;
	}
		} //end of while
		}//end of if tries
	else 
		{
			printf("\nERROR LOGGING IN! Please Try Again Later...\n");
			exit(EXIT_FAILURE);
		}
		fclose(fp);
	} //end of if A
	else if (lc == 'B')
	{
	clrscr();
	title();
	titlelogin(1);
	printf("\n\n\t<==REGISTER CREDENTIALS HERE==>\n");
	printf("Username : ");
	scanf("%s",uname);
	printf("Password : ");
	scanf("%s",pw);
	clrscr();
	title();
	printf("\n\tINFORMATION HAS BEEN REGISTERED!\n");
	printf("\n\tPlease Restart The Program And Login \n\tUsing The Credentials You Registered...\n");
	//FILES NA TO
	FILE *fptr;
	fptr = fopen("LoginRegister.txt","a");
	fprintf(fptr,"%s ",uname);
	fprintf(fptr,"%s\n",pw);
	fclose(fptr);
	exit(0);
	break;
	}
	else 
	{
	printf("Enter A Valid Function! :: ");
	scanf(" %c",&lc);
	}
  } //end of first while
}//funcend
void title()
{
	//for (int i = 0; i < 31; i++)
//  {
//    if(__LINE__ == __LINE__) {
//    printf("*"); }
//    if (i == 15){
//    printf("\n\t::::: INVENTORY SYSTEM :::::\n"); }
//    if (__LINE__ == __LINE__) {
//    printf("*"); }
//  }
for (int i = 0; i < 31; i++)
  {
    if(__LINE__ == __LINE__) {
    printf("="); }
    if (i == 15){
    printf("\n\t::::: INVENTORY SYSTEM :::::\n"); }
    if (__LINE__ == __LINE__) {
    printf("="); }
  }
}
void titlelogin(int x)
{
	if (x == 1) {
	printf("\n\t <==LOGIN PORTAL==>\n");
	printf("Press : \n[ A ]. Have An Account\n[ B ]. Register \n==> ::: ");
	}
	else if (x == 2) {
	printf("Press : \n[ X ]. To Go Back\n[ Y ]. To Exit Program\n==> ::: ");
	}
	else if (x == 3) {
	printf("\n\t <==VIEWING INVENTORY==>\n");
	}
	else if (x == 4)
	{
	printf("\n\t <==EDITING INVENTORY==>\n");
	}
	else if (x == 5)
	{
	printf("Press : \n[ A ]. Add Data\n[ B ]. Delete\n[ C ]. Update \n[ D ]. Go Back\n[ E ]. Exit Program\n==> ::: ");
	}
}
void welcome()
{
  printf("\nWelcome To Your Inventory\n");
  printf("Press : \n");
  printf("[ 0 ]. Login\n[ 1 ]. Viewing Current Inventory\n[ 2 ]. Editing Inventory\n[ 3 ]. Exit\n ==> ::: ");
}
char view()
{
	char vchoice, buf[200], item[20];
	int stock, price,i,j,k;
	titlelogin(3);
	//opening inventory
	FILE *fpointer;
	fpointer = fopen("Inventory.txt", "r");
	fgets(buf,200, fpointer);
    printf("\t%s",buf);
	for (i = 0; i < linecounter(); i++)
	{
    	fscanf(fpointer,"%s%d%d",item,&price,&stock);
		int n = strlen(item);
		printf("\t%s",item);
		for (j = 17; j > n; j--)
		{
			printf("..");
		}
		int m = numlen(price);
		printf("%d",price);
		for (k = 9; k > m; k--)
		{
			printf("..");
		}
		printf("%d\n",stock);
	}
	fclose(fpointer); //closing inventory
	
	titlelogin(2);
	scanf(" %c",&vchoice);
	while(vchoice) { 
	if (vchoice == 'X')
	{
		return vchoice;
		break;
	}
	else if (vchoice == 'Y')
	{
		clrscr();
		title();
		printf("\nProgram Terminated...");
		exit(EXIT_SUCCESS);
	}
	else 
	{
		printf("Invalid Function! Try Again ::: ");
		scanf(" %c",&vchoice);
	}
	} //end of while
}
char edit()
{
	char echoice;
	char buffs[200], item[20];
	int price, stock;
	int i,j,k;
	//opening inventory
	FILE *filepointer;
	filepointer = fopen("Inventory.txt", "r");
	printf("\n\tThis Is The Current Inventory\n");
	fgets(buffs,200, filepointer);
    printf("\t%s",buffs);
	for (i = 0; i < linecounter(); i++)
	{
		fscanf(filepointer,"%s%d%d",item,&price,&stock);
		int n = strlen(item);
		printf("\t%s",item);
		for (j = 17; j > n; j--)
		{
			printf("..");
		}
		int m = numlen(price);
		printf("%d",price);
		for (k = 9; k > m; k--)
		{
			printf("..");
		}
		printf("%d\n",stock);
	}
	fclose(filepointer);//closing inventory
	
	while(1)//editchoices: //goto statement
	{
	titlelogin(5);
	scanf(" %c",&echoice);
	
	switch(echoice) 
	{
	   case 'A' : //if (echoice == 'A')
	{
	 clrscr();
	 title();
	 titlelogin(4);
	 
	 int ndata;
	 printf("\n\tHow Many Data You Want To Add? ::: ");
 	scanf("%d",&ndata);
	 FILE *fptr;
 	fptr = fopen("Inventory.txt", "a");
 	for (int a = 0; a < ndata; a++)
 	{
 	printf("\n\t[%d] Enter The Brand & Type: ",a+1);
	 scanf("%s",item);
	 printf("\t[%d] Enter The Price: ",a+1);
	 scanf("%d",&price);
	 printf("\t[%d] Enter How Many Stocks: ",a+1);
	 scanf("%d",&stock);
	fprintf(fptr,"%s ",item); //writing items
	fprintf(fptr,"%d ",price);
	fprintf(fptr,"%d\n",stock);
	clrscr();
	title();
	titlelogin(4);
 	} //endfor
		if (!fclose(fptr))
			{ 
				clrscr();
			    title();
				titlelogin(4);
				printf("\n\tThe Following Data Has Been Saved!\n");
				break;  //goto editchoices; //goto statement
			 } //endif
	} //end case A //end first if

	case 'D': //else if (echoice == 'D')
	{
	return echoice;
	return 0;
	} 
	case 'B' :
	{
	clrscr();
	title();
	titlelogin(4);
	char string[10000];
	int numline, counter = 0;
	FILE *fp = fopen ("Inventory.txt","r"); //opening orig file
	display(); //display data with line number
	FILE *ftemp = fopen("Inventorytemp.txt","w"); //opening temp file
	while(numline)
	{
	numline = 0;
	printf("\n\tEnter Line You Want To Remove :::  ");
	scanf(" %d",&numline); //entering line to remove
	numline++;
	if (numline-1 > linecounter()) 
	{
		clrscr();
		title();
		titlelogin(4);
		display();
		printf("\n\tLINE DOESN'T EXIST...\n");
		continue;
	}
	else if (numline-1 == 0)
		{
		clrscr();
		title();
		titlelogin(4);
		display();
		printf("\n\tLINE DOESN'T EXIST...\n");
		continue;
		}
	else
	{ 
	break; 
	}
	} //end of while
	while (!feof(fp)) //looping until end of file
	{
		strcpy(string,"\0"); //filling string with 0
		fgets(string,10000,fp); //getting the datas
		if (!feof(fp)) 
		{
			counter++; //counting the lines in file 
			if (counter != numline)
			{
				fprintf(ftemp,"%s",string); //writing to temp file and Skipping the line entered
			}
		}
	} //end of while
	fclose(fp); //closing orig file
	fclose(ftemp); //closing temp file
	remove("Inventory.txt"); //removing orig file
	rename("Inventorytemp.txt","Inventory.txt"); //renaming temp file with orig file name
	clrscr();
	title();
	titlelogin(4);
	printf("\n\tThe Following Data Has Been Removed...\n");
	break;
		} //end of case b
	
	case 'E' :
	{
		clrscr();
		title();
		printf("\nProgram Terminated...");
		exit(EXIT_SUCCESS);
		break;
	} //end of e
	case 'C' :
	{
	clrscr();
	title();
	titlelogin(4);
	FILE * fPtr;
    FILE * fTemp;    
    char buffer[1000];
    char newline[1000];
    int line, count = 0;
    display(); //display data with line number
	fPtr  = fopen("Inventory.txt", "r");
	fTemp = fopen("tempf.txt", "w"); 
    printf("\n\tEnter Line Number To Update: ");
    scanf("%d",&line);
    line++;
    while(line)
    {
    	if (line-1 == 0)
    	{
    	clrscr();
		title();
		titlelogin(4);
		display();
    	printf("\n\tLINE DOESN'T EXIST");
    	printf("\n\tEnter Line Number To Update: ");
    	scanf("%d",&line);
 	   line++;
 	   continue;
    	}
    	else if (line-1 > linecounter ())
    	{
    	clrscr();
		title();
		titlelogin(4);
		display();
    	printf("\n\tLINE DOESN'T EXIST");
    	printf("\n\tEnter Line Number To Update: ");
    	scanf("%d",&line);
 	   line++;
    	}
    	else 
    	{
    	clrscr();
		title();
		titlelogin(4);
		display();
    		break;
    	}
    }
    fflush(stdin);
   /* Remove extra new line character from stdin */
    printf("\n\tINPUT THE FOLLOWING IN ORDER\n");
    printf("\tBrand-Type Price Stock ::: ");
    fgets(newline, 1000, stdin);
    //fPtr  = fopen("Inventory.txt", "r");
//    fTemp = fopen("tempf.txt", "w"); 
    while ((fgets(buffer, 1000, fPtr)) != NULL)
    {
        count++;
        /* If current line is line to replace */
        if (count == line)
            fputs(newline, fTemp);
        else
            fputs(buffer, fTemp);
    }
    fclose(fPtr);
    fclose(fTemp);
    remove("Inventory.txt");
    rename("tempf.txt","Inventory.txt");
    clrscr();
	title();
	titlelogin(4);
    printf("\n\tData Has Been Successfully Updated...\n");
    break;
	}//end of c
	default:
	{
		clrscr();
		title();
		printf("\n\tInvalid Function! Try Again...\n");
		break;
	}
	}// end switch
}//while loop end
}//function end

int linecounter()
{
		int i , count = 0;
		FILE *fptr;
		fptr = fopen("Inventory.txt","r");
		 while ((i = fgetc(fptr)) != EOF)
		{
		if (i == '\n')
		{
			count++;
		}
		
		}
		fclose(fptr);
		return count-1;
}
int numlen(int n)
{
	if(n <= 999999 && n >= 100000)return 6;
	if(n <= 99999 && n >= 10000)return 5;
	if(n <= 9999 && n >= 1000) return 4;
	if (n <= 999 && n >= 100) return 3;
	if (n <= 99 && n >= 10) return 2;
	return 1;
}
void display ()
{
 	int i,j,k;
 	char buffer[200];
 	char item[20];
 	int price,stock;
 	FILE *fp = fopen ("Inventory.txt","r"); //opening orig file
	//display
	fgets(buffer,200, fp);
    printf("\t     %s",buffer);
	for (i = 0; i < linecounter(); i++)
	{
		fscanf(fp,"%s%d%d",item,&price,&stock);
		int n = strlen(item);
		printf("\t[%d] %s.....",i+1,item);
		for (j = 17; j > n; j--)
		{
			printf(".");
		}
		int m = numlen(price);
		printf("%d",price);
		for (k = 9; k > m; k--)
		{
			printf("..");
		}
		printf("%d\n",stock);
	}
	//end of display
	fclose(fp);
}