#include <stdio.h>
void NhapMang (int a[],int n );
void XuatMang (int a[],int n );

void SXChon(int a[],int n);

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
	SXChon(a,n);
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

void SXChon(int a[],int n)
{
	for (int i=0;i<n-1;i++)
	{
		int min=i;
		printf("\n");
		printf("\n    		-----------------------------------------------------------");
		for(int j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		HoanVi(a[min],a[i]);
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
