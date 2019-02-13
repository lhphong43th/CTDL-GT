
#include<stdio.h>
#include <conio.h>
int main()
{
	int n;
	printf(" Nhap vao so nguyen n: ");
	scanf("%d", &n);
	while(n<=0)
	{
		printf(" Nhap lai so nguyen n: ");
		scanf("%d", &n);
	}
	printf(" So nguyen n vua nhap la: %d", n);
	return 0;
}
