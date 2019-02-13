#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char str1[50], str2[50];
	printf(" Nhap vao chuoi thu 1: ");
	gets(str1);
	printf(" Nhap vao chuoi thu 2: ");
	gets(str2);
	
	printf("- Choi thu nhat vua nhap la: %s\n", str1);
	printf("- Choi thu hai vua nhap la: %s\n", str2);
	
	if( strcmp(str1,str2)==0)

		printf(" Hai chuoi vua nhap giong nhau.");
	else
		printf(" Hai chuoi vua nhap khong giong nhau.");
	return 0;		
	
	
}
