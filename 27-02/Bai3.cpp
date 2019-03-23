//Su dung toan tu cin va cout 
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;

#define MaxLength 100
struct Ellipse
{
	float x, y,R1, R2, chuvi, dientich;
};
typedef Ellipse ElementType;
typedef int Position;
typedef struct
{
	ElementType Elements[MaxLength]; //toi da danh sach
	Position Last;  //luu so phan tu hien thoi cua mang
} List;

// KHAI BAO NGUYEN MAU HAM
void Makenull_List(List *L);
int isEmpty_List(List L);
int isFull_List(List L);
Position First_List(List L);
Position End_List(List L);
Position Next(Position P, List L);
Position Previous(Position P, List L);
ElementType Retrieve(Position P, List L);
void Insert_List(ElementType X, Position P, List *L);
void Delete_List(Position P, List *L);
Position Locate(ElementType X, List L);
// Ham chuc nang
void Read_List(List *L);
void Print_List( List L);
void Sort_List( List &L);

void TinhCVDT(List &L);
void KT_GocToaDo( List L);

//Ham chuc nang
void Read_List(List *L)
{
	ElementType X; //Luu gia tri trong khi nhap
	int n; // So luong phan tu se nhap
	Makenull_List(L);
	printf("NHAP DANH SACH ELLIPSE\n");
	printf("-Nhap so luong phan tu: ");
	scanf("%d", &n);
	for( int i=0; i<n; i++)
	{
		printf("-Nhap phan tu thu %d: ", i+1);
		//Nhap gia tri cho X
		printf("-Nhap gia tri x: ");
		scanf("%f", &X.x);
		printf("-Nhap gia tri y: ");
		scanf("%f", &X.y);
		printf("-Nhap ban kinh R1: ");
		scanf("%f", &X.R1);
		printf("-Nhap ban kinh R2: ");
		scanf("%f", &X.R2);
		//Ket thuc nhap gia tri cho X
		Insert_List(X, End_List(*L), L);
	}
}
void Print_List(List L)
{
	if (isEmpty_List(L))
		printf("Danh sach rong \n");
	else
	{
		printf("CAC PHAN TU TRONG DANH SACH\n");
		for(Position i=First_List(L); i<End_List(L); i=Next(i, L))	
		{
			printf("+ x = %f\n", L.Elements[i-1].x);
			printf("+ y = %f\n", L.Elements[i-1].y);
			printf("+ R1 = %f\n", L.Elements[i-1].R1);
			printf("+ R2 = %f\n", L.Elements[i-1].R2);
			printf("+ Chu vi = %f\n", L.Elements[i-1].chuvi);
			printf("+ Dien tich = %f\n", L.Elements[i-1].dientich);
			printf("-------------------\n");
		}
	}	
}
void Sort_List(List &L)
{
	for (Position i=First_List(L); i<End_List(L); i=Next(i, L))
	{
		for(Position j=Next(i, L); j<End_List(L); j=Next(j, L))
		{
			if(L.Elements[j-1].chuvi < L.Elements[i-1].chuvi)
			{
				ElementType t;
				t = L.Elements[i-1];
				L.Elements[i-1] = L.Elements[j-1];
				L.Elements[j-1] = t;
			}
		}
	}
}
void TinhCVDT(List &L)
{
	if (isEmpty_List(L))
		printf("Danh sach rong \n");
	else
	{
		printf("TINH CHU VI\n");
		for(Position i=First_List(L); i<End_List(L); i=Next(i, L))	
		{
			L.Elements[i-1].chuvi = 2* 3.14*sqrt(L.Elements[i-1].R1*L.Elements[i-1].R1+L.Elements[i-1].R2*L.Elements[i-1].R2)/2;
			L.Elements[i-1].dientich = 3.14*L.Elements[i-1].R1*L.Elements[i-1].R2;
		}
	}	
}
void KT_GocToaDo( List L)
{
	if (isEmpty_List(L))
		printf("Danh sach rong \n");
	else
	{
		printf("KIEM TRA GOC TOA DO\n");
		for(Position i=First_List(L); i<End_List(L); i=Next(i, L))	
		{
			if (L.Elements[i-1].x==0 && L.Elements[i-1].y==0)
				printf("-Hinh Ellipse thu %d nam o goc toa do\n", i);
		}
	}	
}

//ham chinh
int main()
{
	List ds;
	Makenull_List(&ds);
	Read_List(&ds);
	TinhCVDT(ds);
	Print_List(ds);
	KT_GocToaDo(ds);
	printf("Sap xep\n");
	
	Sort_List(ds);
	Print_List(ds);
	getch();
	return 1;
} 

//Quan niem: Vi tri P se co gia tra la Elements[P-1]
//Ex: a[9] se co vi tri P=10
//tao danh sach rong
void Makenull_List(List *L)
{
	L->Last = 0;
}

//kiem tra danh sach rong

int isEmpty_List(List L)
{
	return (L.Last == 0);
}

//kiem tra danh sach day
int isFull_List(List L)
{
	return (L.Last == MaxLength);
}

//Ham tra ve vi tri phan tu dau tien trong danh sach
//Position First_List(List L)
Position First_List(List L)
{
	return 1;
}

//Ham tra ve vi tri sau phan tu cuoi cung  trong danh sach
Position End_List(List L)
{
	return L.Last+1;
}
//ham tra ve vi tri phan tu  ke tiep phan tu P  trong danh sach L
Position Next(Position P, List L)
{
	if (P > MaxLength || P < 0)
		 {
		printf("\nVi tri khong hop le");
		return -1;
		}
	else
		return (P+1);
}

//ham tra ve vi tri phan tu  truoc vi tri  P  trong danh sach L
Position Previous(Position P, List L)
{
	if (P > MaxLength || P < 0)
	{
		printf("\nVi tri khong hop le");
		return -1;
	}
	else if (P==1)
		return 1;
		 else
		return P-1;
}

//ham tra ve noi dung phan tu tai vi tri  P  trong danh sach L
ElementType Retrieve(Position P, List L)
{
	if (P > MaxLength || P < 0)
	{
		printf("\nVi tri khong hop le");
		//return -1;
	}
	else
		return L.Elements[P-1];
}


//ham them phan tu co noi dung X vao tai vi tri P trong danh sach L
void Insert_List(ElementType X, Position P, List *L)
{  int i=0;
	if ( L->Last == MaxLength)
		printf("Danh sach day !!!");
	else if ((P < 1) ||(P > L->Last+1))
			printf("\nVi tri khong hop le !!!");
		else
		{
			//thuc hien doi cac phan tu tu P sang phai
			for (i=L->Last; i>=P; i--)
			{
				L->Elements[i] = L->Elements[i-1];
			}
			//tang Last len 1
			L->Last++;
			//chen X vao vi tri P
			L->Elements[i] = X;
		}
}

//xoa phan tu tai vi tri P trong L
void Delete_List(Position P, List *L)
{
	Position i;
	if (P < 1 || P > L->Last)
			printf("\nVi tri ko hop le !!!");
	else
		if (isEmpty_List(*L))
			printf("\nDanh sach rong !!!");
		else
		{
			//thuc hien doi cac phan tu tu P sang trai
			for (i = P; i <= L->Last; i++)
				L->Elements[i-1] = L->Elements[i];
			//giam Last xuong 1
			L->Last--;
		}
}
	
//tim vi tri dau tien co noi dung X trong sanh sach,
//Neu khong tim thay ham tra ve vi tri End_List
Position Locate(ElementType X, List L)
{
	Position P;
	int found=0;
	P=First_List(L);
	while ((P!=End_List(L)) && (found==0))
	{
		if (Retrieve(P,L).x==X.x && Retrieve(P, L).y == X.y)
			found =1;
		else
			P=Next(P,L);
	}
	return P;
}






