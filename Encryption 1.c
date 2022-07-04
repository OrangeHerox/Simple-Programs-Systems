#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	char buff[200];
	char c[50];
	char a[50];
	char b[50];
	//opening file
	fp = fopen("encryption1.txt","w");
	if (fp == NULL)
	{
		perror("Error Opening...");
	}
	printf("Enter String : ");
	fgets(c,50,stdin);
	//scanf("%s",c);
	int i = 0;
	while(c[i] != '\0') //encrypting the word with encryption key
	{							//encryption key is each character +10
	a[i] = c[i];			//in ASCII value
	a[i] = a[i] + 10;
	i++;
	}
	fprintf(fp,"%s\n",a); //writing the encrypted data into file
    fclose(fp); //closing encryption file
 	
	fp = fopen("encryption1.txt","r"); //opening again for reading
	fgets(buff,200,fp);
	printf("encrypted data is %s",buff); //disp encrypted data
	int j = 0;
	while(buff[j] != '\0') //decrypting the data in the file using
	{							//encryption key each ch +10 in ASCII value
	b[j] = buff[j];			//so to decrypt we need to do the 
	b[j] = b[j] - 10;		//opposite of ch+10 
	j++;
	}
	printf("\nDecrypted to %s",b); //displaying decrypted data 
	fclose(fp); //closing file
}
