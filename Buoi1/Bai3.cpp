#include<stdio.h>
#include<conio.h>
void NhapMang( int a[], int &n);
void XuatMang( int a[], int n);
void LinearSearch_1( int a[], int n, int x);
int LinearSearch_2( int a[], int n, int x);
int main()
{
	int ds[100], sopt;
	NhapMang(ds, sopt);
	
	
	printf(" TIM KIEM TUYEN TINH\n");
	int x;
	printf(" Nhap gia tri can tim: ");
	scanf("%d", &x);
	LinearSearch_1(ds, sopt, x);
	int kq1 =LinearSearch_2(ds, sopt, x);
	printf(" Vi tri tim duoc la %d \n", x);
	printf(" Cac phan tu vua nhap la:\n ");
	XuatMang(ds,sopt);
	
	return 0;
}
void NhapMang( int a[], int &n)
{
	printf(" Nhap vao so luong phan tu: ");
	scanf("%d", &n);
	while (n<=0)
	{
		printf("Nhap lai: ");
		scanf("%d", &n);
	}
	for (int i=0; i<n; i++)
	{
		printf(" Nhap vao phan thu thu %d ", i+1);
		scanf("%d", &a[i]);
	}
}
void XuatMang( int a[], int n)
{
	
	for ( int i=0; i<n ;i++)
	{
		printf(" Gia tri cua phan tu thu %d la %d\n", i+1, a[i]);
	}
}
void LinearSearch_1( int a[], int n, int x)
{
	int flag =0 ;// 0 neu khong co x, 1 neu co x
	for (int i=0; i<n; i++)
	{
		if (x==a[i])
		{
			printf(" Vi tri cua %d la vi tri thu %d\n", x, i+1);
			flag=1;
		}
	}
	if (flag==0)
		printf(" Tim khong thay\n");
		
}
int LinearSearch_2( int a[], int n, int x)
{
// for ( int i=0; i<n; i++)
	for ( int i=n-1; i>=0; i--)
	{
		if (x==a[i])
		return i+1;
	}
	return 0;
	
}
	
