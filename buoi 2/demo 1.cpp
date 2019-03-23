#include <stdio.h>
void NhapMang (int a[],int n );
void XuatMang (int a[],int n );
void SXChon(int a[],int n);
void SXChen(int a[],int n);
void SXDoiCho(int a[],int n);
void SXNoiBot(int a[],int n);


void vonglap(int a[],int n);
void key(int a[],int n);
void HoanVi(int &a,int &b);

int main()
{
	int a[100];
	int n;
	printf("\n nhap so phan tu:");
	scanf("%d",&n);
	while(n>0)
	{
		NhapMang(a,n);
		printf("\n mang vua nhap la:");
		XuatMang(a,n);
		
		key(a,n);
		
		printf("\n nhap so phan tu:");
		scanf ("%d",&n);
	}
	
	
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

void SXChen(int a[],int n)
{
	for (int i=1;i<n;i++)
	{
		int x; // luu vi CAN THEM
		int vt;// LUU GIA TRI THEM VAO
		printf("\n");
		printf("\n    --------------------------------------------------------");
		for(int j=i;j>=0;j--)
		{
			x=a[i];
			vt=i-1;
			while((vt>=0)&&a[vt]>x)
			{
				a[vt+1]=a[vt];
				vt--;
			}
			a[vt+1]=x;
			
		}
		printf("\n SX lan thu %d:\t",i);
		XuatMang (a, n);	
	}
}

void SXDoiCho(int a[],int n)
{
	for (int i=0;i<n-1;i++)
	{
		int min=i;
		printf("\n");
		printf("\n    		-------------------------------------------------");
		for(int j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				HoanVi(a[min],a[j]);
			}
		}
		printf("\n SX lan thu %d:\t",i+1);
		XuatMang (a, n);	
	}
}

void SXNoiBot(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		
		printf("\n");
		printf("\n    		-----------------------------------------------------------");
		for(int j=n-1;j>i;j--)
		{
			if(a[j]<a[j-1])
				HoanVi(a[j-1],a[j]);
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


void key(int a[],int n)
{
	int x;
	printf ("\n 1:SX Chon.	");
	printf (" 2:SX Chen.	");
	printf (" 3:SX Doi cho.	");
	printf (" 4:SX Noi bot.	");
	printf ("\n nhap PP SX:	");
	scanf("%d",&x);
	switch (x)
	{
		case 1:
			SXChon(a,n);break;
		case 2:
			SXChen(a,n);break;
		case 3:
			SXDoiCho(a,n);break;
		case 4:
			SXNoiBot(a,n);break;			
	}
}




























