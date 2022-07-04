#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(int argc, char *argv[])
{
	int tries = 5;
	char lc;
	char username[30], password[30];
	char uname[30], pw[30];
	char buff[100];

	FILE *fp;
	printf("LOGIN/REGISTER FORM\n");
	printf("Press A. Login\nPress B. Register\n ::: ");
	scanf("%c", &lc);
	while (lc)
	{
		if (lc == 'A')
		{
			if (tries != 0)
			{
				tries--;
				fp = fopen("LoginRegister.txt", "r"); //open
				printf("\nUsername : ");
				scanf("%s", uname);
				printf("Password : ");
				scanf("%s", pw);

				while (fgets(buff, 100, fp) != NULL)
				{
					fscanf(fp, "%s%s", username, password);
					if ((strcmp(username, uname) == 0) && (strcmp(password, pw) == 0))
					{
						clrscr();
						printf("Login Success!");
						return 0;
						break;
					}
					else
					{
						clrscr();
						printf("\n\t\tIncorrect Email Or Password\n\t\tRemaining Tries %d...\n", tries);
						continue;
					}
				} //end of while
			}	  //end of if tries
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
			printf("\n\t<==REGISTER CREDENTIALS HERE==>\n");
			printf("Username : ");
			scanf("%s", uname);
			printf("Password : ");
			scanf("%s", pw);
			clrscr();
			printf("\n\tINFORMATION HAS BEEN REGISTERED!\n");
			printf("\n\tPlease Restart The Program And Login \n\tUsing The Credentials You Registered...\n");
			//FILES NA TO
			FILE *fptr;
			fptr = fopen("LoginRegister.txt", "a");
			fprintf(fptr, "%s ", uname);
			fprintf(fptr, "%s\n", pw);
			fclose(fptr);
			exit(0);
			break;
		}
		else
		{
			printf("Enter A Valid Function! :: ");
			scanf(" %c", &lc);
		}
	} //end of first while
}
