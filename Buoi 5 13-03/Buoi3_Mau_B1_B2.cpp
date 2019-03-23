#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
typedef ... ElementType;

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
	
	
	
/* MAIN PROGRAM */
int main()
{
	
	getch();
	return 1;

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

	




	
