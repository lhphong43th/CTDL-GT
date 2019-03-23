#include <stdio.h>
void NhapMang (int a[],int n );
void XuatMang (int a[],int n );
void SXNoiBot(int a[],int n);
void HoanVi(int &a,int &b);

int main()
{
	int a[100];
	int n;
	printf("\n nhap so phan tu cho mang:");
	scanf("%d",&n);
	NhapMang (a, n);
	printf ("\n mang vua nhap la:  ");
	XuatMang (a, n);
	SXNoiBot(a,n);
	return 0;
}

void NhapMang (int a[],int n )
{
	for (int i=0;i<n;i++)
	{
		printf ("nhap a[%d]:",i);
		scanf ("%d",& a[i]);
	}
	
}

void XuatMang (int a[],int n )
{
	for (int i=0;i<n;i++)
		printf ("\t%d",a[i]);
}

void SXNoiBot(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		printf("\n");
		printf("\n    		-----------------------------------------------------------");
		for(int j=n-1;j>=i;j--)
		{
			if(a[j-1]>a[j])
			{
				HoanVi(a[j-1],a[j]);
			}
		}
		printf("\n SX lan thu %d:\t",i+1);
		XuatMang (a, n);	
	}
}
void HoanVi(int &b,int &c)
{
	int x=b;
	b=c;
	c=x;
}

