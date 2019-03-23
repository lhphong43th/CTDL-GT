#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream>
using namespace std;
struct HCN
{
	float dai,rong,ChuVi,DienTich;
};
typedef HCN ElementType;

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
	
void Read_List(List L);
void Print_List(List L);
void TinhCVDT(List L);
/* MAIN PROGRAM */
int main()
{
	List ds;
	Makenull_List(ds);
	Read_List(ds);
	TinhCVDT(ds);
	Print_List(ds);
	

	getch();
	return 1;

}

void Read_List(List L)
{
	int n;
	ElementType X;
	printf("\n-NHAP Ellipse-");
	printf("\n-nhap so luong hinh hinh chu nhat: ");
	scanf("%d", &n);
	Position P = Header(L);
	
 	for(int i=1;i<=n;i++)
		{
			printf("\n-nhap Hinh chu nhat thu %d:",i);
			printf("\n-Nhap chieu dai:"); scanf("%f", &X.dai);
			printf("\n-Nhap chieu rong:"); scanf("%f", &X.rong);
			Insert_List(X,P,L);
			P = P->Next;
		}
}

void Print_List(List L)
{
	if(IsEmpty_List(L))
		printf("\n DANH SACH RONG");
	else
	{
		for(Position i=First(L);i!=NULL; i=i->Next)
		{
			printf("-chieu dai: %.2f\n", i->Element.dai);
			printf("-chieu rong: %.2f\n", i->Element.rong);
		
			printf("-Chu vi: %.2f\n", i->Element.ChuVi);
			printf("-Dien Tich: %.2f\n", i->Element.DienTich);
		}	
	}
}

void TinhCVDT(List L)
{
	for(Position i=First(L);i!=NULL; i=i->Next)
		{
			i->Element.ChuVi = (i->Element.dai+i->Element.rong)*2;
			i->Element.DienTich = i->Element.dai*i->Element.rong;
		}
}
	


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
  while( P != NULL && P->Element.ChuVi != X.ChuVi )
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
  while( P->Next != NULL && P->Next->Element.ChuVi != X.ChuVi )
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

	




	
