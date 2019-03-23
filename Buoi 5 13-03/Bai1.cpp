#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
typedef int ElementType;

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
void Sort_List(List L);

	
	
/* MAIN PROGRAM */
int main()
{
	List ds;
	Makenull_List(ds);
	Read_List(ds);
	Print_List(ds);
	printf("Sap xep\n");
	Sort_List(ds);
	Print_List(ds);
	
	
	getch();
	return 1;

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
		printf("-Nhap phan tu thu %d: ", i);
		scanf("%d", &X);
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
		printf("CAC PHAN TU TRONG DANH SACH\n");
		for(Position i=First(L); i!=NULL; i=i->Next)
		{
			printf("%d\t", i->Element);
		}
		printf("\n");
		}	
}
void Sort_List(List L)
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
  while( P != NULL && P->Element != X )
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
  while( P->Next != NULL && P->Next->Element != X )
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

	




	
