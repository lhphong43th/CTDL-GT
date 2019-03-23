#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
struct Ellipse{
float x, y, R1, R2, chuvi, dientich;
};
typedef Ellipse ElementType;

typedef struct Node
{
	ElementType Element;
	Node    *Next;
};

typedef Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

void Makenull_List( List &L );
int IsEmpty_List( List L );
int IsLast( Position P);
Position Locate( ElementType X, List L );
void Delete_List( ElementType X, List L );
Position FindPrevious( ElementType X, List L );
void Insert_List( ElementType X, Position P, List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
ElementType Retrieve( Position P );
//Ham chuc nang:
void Read_List(List L);
void Print_List(List L);
//void Sort_List(List L);
void TinhCVDT(List L);
	
	
/* MAIN PROGRAM */
int main()
{
	List ds;
	Makenull_List(ds);
	Read_List(ds);
	TinhCVDT(ds);
	Print_List(ds);
	//printf("Sap xep\n");
	//Sort_List(ds);
	//Print_List(ds);
	
	
	getch();
	return 1;

}
void TinhCVDT(List L)
{
	if(IsEmpty_List(L))
	printf("danh sach rong\n");
else
	{
	printf("CAC PHAN TU TRONG DANH SACH\n");
	for(Position i=First(L); i!=NULL; i=i->Next)
	{
		i->Element.chuvi = 2*3.14*sqrt(i->Element.R1*i->Element.R1+i->Element.R2*i->Element.R2)/2;
		i->Element.dientich = 3.14* i->Element.R1* i->Element.R2;
	}
	printf("\n");
	}
}
void Read_List(List L)
{
	int n;
	ElementType X;
	printf("NHAP DANH SACH\n");
	printf("-Nhap so luong phan tu: ");
	scanf("%d", &n);
	Position P = L;
	for(int i=1; i<=n; i++)
	{
		printf("-Nhap toa do x: "); scanf("%f", &X.x);
		printf("-Nhap toa do y: "); scanf("%f", &X.y);
		printf("-Nhap ban kinh R1: "); scanf("%f", &X.R1);
		printf("-Nhap ban kinh R2: "); scanf("%f", &X.R2);
		Insert_List(X, P, L);
		P= P->Next;
	}
}
void Print_List(List L)
{
	if(IsEmpty_List(L))
		printf("Dang sach rong\n");
	else
	{
		printf("CAC PHAN TU TRONG DANH SACH CVDT\n");
		for(Position i=First(L); i!=NULL; i=i->Next)
		{
			printf("-Toa do x: %f\n", i->Element.x);
			printf("-Toa do y: %f\n", i->Element.y);
			printf("-Ban kinh R1: %f\n", i->Element.R1);
			printf("-Ban kinh R2: %f\n", i->Element.R2);
			printf("-Chu vi: %f\n", i->Element.chuvi);
			printf("-Dien Tich: %f\n", i->Element.dientich);
		}
		printf("\n");
		}	
}
/*void Sort_List(List L)
{
	for(Position i=First(L); i!=NULL; i=i->Next)
		for(Position j=i->Next; j!=NULL; j=j->Next)
			if(j->Element < i->Element)
			{
				ElementType t;
				t = i->Element;
				i->Element = j->Element;
				j->Element = t;
			}
	
		
}
*/

/* Cai dat cac ham*/
/*Tao 1 danh sach rong*/
void  Makenull_List(List  &L)
{
	L = new Node;
	if (L== NULL){
		printf("Khong du bo nho");
		exit(1);
	}
	L->Next = NULL;
}

/* Kiem tra danh sach rong? */
int IsEmpty_List( List L )
{
	return L->Next == NULL;
}

/* Kiem tra P co tro den phan tu cuoi cua ds khong? */
int IsLast( List P )
{
	return P->Next == NULL;
}

/* Tim vi tri phan tu x trong ds */
Position  Locate( ElementType X, List L )
{
  Position P;

  P = L->Next;
  while( P != NULL && P->Element.chuvi != X.chuvi )
	  P = P->Next;
  return P;
}

/* Xoa 1 phan tu */
void	Delete_List( ElementType X, List L )
{
	Position P, TmpCell;
	P = FindPrevious( X, L );
	if( !IsLast(P) )
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free( TmpCell );
	}
}

/* Tim vi tri cua phan tu X  */
Position	FindPrevious( ElementType X, List L )
{
	Position P;

  P = L;
  while( P->Next != NULL && P->Next->Element.chuvi != X.chuvi )
	  P = P->Next;
  return P;
}


/* Chen 1 phan tu vao danh sach */
void  Insert_List( ElementType X, List P, List L )
{
	Position TmpCell;
	TmpCell = new Node;
	
	if (TmpCell == NULL)
	{
		printf("Khong du bo nho");
		exit(1);
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

	
/* Tim phan tu header */
Position Header( List L )
{
	return L;
}

/* Tim phan tu dau tien */
Position First( List L )
{
	return L->Next;
}

/* Tim phan tu ke tiep */
Position	Advance( Position P )
{
	return P->Next;
}

/* Tim gia tri cua 1 phan tu */
ElementType	Retrieve( Position P )
{
	return P->Element;
}

	




	
