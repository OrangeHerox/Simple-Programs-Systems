#include <stdio.h>
#include <string.h>

int main()
{
	char c[10];
	char a[10];
	char b[10];
	printf("Enter String : ");
	scanf("%s",c);
	
	int i = 0;
	while(c[i] != '\0')
	{
	a[i] = c[i];
	a[i] = a[i] + 10;
	i++;
	}
	printf ("Encrypted To %s\n",a);
	
	printf("Decrypted Again To ");
	int j = 0;
	while(a[j] != '\0')
	{
	b[j] = a[j];
	b[j] = b[j] - 10;
	j++;
	}
	printf("%s",b);
	
	return 0;
}
