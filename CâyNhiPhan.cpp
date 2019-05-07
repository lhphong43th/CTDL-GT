#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *Node;
typedef struct TreeNode *Tree;

//Khai bao cay nhi phan
struct TreeNode
{
	ElementType Element;
	Node Left;	//Con tro Trai
	Node Right;	//Con tro Phai
};

// Khai bao nguyen mau ham-------------------------------
Tree MakeEmpty(Tree T); 
int IsEmpty_Tree(Tree  T); 
Node LeftChild(Tree  p); 
Node RightChild(Tree p); 
int IsLeaf(Tree p); // Kiem tra nut la
Tree Insert(ElementType X, Tree& T); 
Tree Delete ( ElementType X, Tree T); 
ElementType Retrieve(Node P);  // Lay gia tri nut P


// 1. Tim kiem cay
Node Search(ElementType X, Tree T);
// 2. Dem so nut tren cay (de quy - khong de quy)
int nb_nodes( Tree T);
// 3. Dem so nut la tren cay (de quy - khong de quy)
int nb_leaves( Tree T);
// 4. Dem so nut trung gian (de quy - khong de quy)
int nb_interiornodes(Tree T);
// 5. Duyet tien tu - trung tu - hau tu
void PreOder(Tree T);
void InOder(Tree T);
void PosOder(Tree T);
// 6. Dem so nut trong tung muc
int Count_Level(int k,Tree T);
// 7. Duyet cay theo muc

// 8. Tra ve nut co gia tri nho nhat
Node FindMin(Tree T);
// 9. Tra ve nut co gia tri lon nhat
Node FindMax(Tree T);
// Chuong trinh chinh-------------------------------------
int main()
{
	Tree T;
	T=MakeEmpty(NULL);
	ElementType X;
	do{
		printf("Nhap gia tri nut (Nhap <0 de thoat): ");
		scanf("%d", &X);
		if(X>=0)
			T=Insert(X,T);
	}while(X>=0);
	// 1. Tim kiem cay
	/*ElementType Y;
	printf("Nhap gia tri can tim: ");
	scanf("%d", &Y);
	Node kqtk = Search(Y, T);
	if(kqtk == NULL)
		printf("Tim khong thay gia tri %d\n", Y);
	else
		printf("Gia tri %d co tren cay\n", Y);	*/
		int tongsonut= nb_nodes(T);
		printf("-->Tong so nut cua cay la: %d\n", tongsonut);
		
		int sonutla = nb_leaves(T);
		printf("-->So nut tren cay la: %d\n", sonutla);
		
		int sonuttg = nb_interiornodes(T);
		printf("-->So nut trung gian cua cay la: %d\n", sonuttg);
		
		printf("Duyet tien tu\n");
		PreOder(T);
		printf("\n");
		
		printf("Duyet trung tu\n");
		InOder(T);
		printf("\n");
		
		printf("Duyet hau tu\n");
		PosOder(T);
		printf("\n");
		
		Node kqmin = FindMin(T);
		printf("-->Gia tri nho nhat tren cay la %d\n", kqmin->Element);
		
		Node kqmax = FindMax(T);
		printf("-->Gia tri lon nhat tren cay la %d\n", kqmax->Element);
		int k;
		printf("Nhap so muc can dem: ");
		scanf("%d", &k);
		int kqdem = Count_Level(k+1, T);
		printf("-->So nut o muc %d la %d \n", k,kqdem);
		
	
	
	getch();
	return 1;
	
}
// 1. Tim kiem cay
Node Search(ElementType X, Tree T)
{
	if(T==NULL)
		return NULL;
	if(X> T->Element)
		return Search(X, T->Right);
	else
		if(X < T->Element)
			return Search(X, T->Left);
		else
			return T;			
}
// 2. Dem so nut tren cay (de quy - khong de quy)
int nb_nodes( Tree T)
{
	if(IsEmpty_Tree(T))
		return 0;
	else
		return nb_nodes(T->Left) + nb_nodes(T->Right) + 1;	
}
// 3. Dem so nut la tren cay (de quy - khong de quy)
int nb_leaves( Tree T)
{
	int dem=0;
	if(!IsEmpty_Tree(T))
	{
		if(T->Left==NULL && T->Right==NULL)
			dem++;
		else
			dem = nb_leaves(T->Left) + nb_leaves(T->Right);	
	}
	return dem;
}

// 4. Dem so nut trung gian (de quy - khong de quy)
int nb_interiornodes(Tree T)
{
	return nb_nodes(T) - 1 - nb_leaves(T);
}
// 5. Duyet tien tu - trung tu - hau tu
void PreOder(Tree T)
{
	printf("%d\t", T->Element);
	if(T->Left!=NULL)
		PreOder(T->Left);
	if(T->Right!=NULL)
		PreOder(T->Right);	
}
void InOder(Tree T)
{
	if(T->Left!=NULL)
		InOder(T->Left);
	printf("%d\t", T->Element);	
	if(T->Right!=NULL)
		InOder(T->Right);
}
void PosOder(Tree T)
{
	if(T->Left!=NULL)
		PosOder(T->Left);
	if(T->Right!=NULL)
		PosOder(T->Right);
	printf("%d\t", T->Element);	
}
// 6. Dem so nut trong tung muc
int Count_Level(int k,Tree T)
{
	int dem=0;
	if(T!=NULL)
	{
		k--;
		if(T->Left!=NULL)
			dem = dem + Count_Level(k, T->Left);
		if(k==0)
			dem++;
		if(T->Right!=NULL)
			dem = dem + Count_Level(k, T->Right);	
	}
	return dem;
}
// 8. Tra ve nut co gia tri nho nhat
Node FindMin(Tree T)
{
	if(T==NULL)
		return NULL;
	else
		if(T->Left==NULL)
			return T;
		else
			return FindMin(T->Left);	
}
// 9. Tra ve nut co gia tri lon nhat
Node FindMax(Tree T)
{
	if(T==NULL)
		return NULL;
	else
		if(T->Right==NULL)
			return T;
		else
			return FindMax(T->Right);		
}
// Dinh nghia ham-----------------------------------------
//Tao cay rong
Tree MakeEmpty(Tree T)
{
	if(T!=NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

//Kiem tra cay rong?
int IsEmpty_Tree(Tree  T)
	{
		  return (T==NULL);
	}

//Xac dinh nut con trai
Node LeftChild(Tree  p)
	{ 	if (p!=NULL) 
			return p->Left; 
		else 
			return NULL; 
	} 

//Xac dinh nut con pahi
Node RightChild(Tree  p)
	{ 	if (p!=NULL)
			return p->Right;
		else 
			return NULL; 
	} 

//Kiem tra cp phai la nut la ?
int IsLeaf(Tree p)
	{ 	if(p!=NULL)
			return ((LeftChild(p)==NULL) &&(RightChild(p)==NULL));
		else 
			return 0; 
	} 

//Chen 1 phan tu vao cay
Tree Insert(ElementType X,Tree &T)
{
	if(T==NULL)
	{
		//Creat and return a one-node tree
		//T= (TreeNode*)malloc(sizeof(struct TreeNode) );
		T= new TreeNode;
		if(T==NULL)
			printf("Out of space!");//Loi
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else
		if(X < T->Element)
			T->Left = Insert(X, T->Left);
		else
			if(X > T->Element)
				T->Right = Insert(X,T->Right);
				//else x is in this tree already; we'll do nothing
	return T;
}
/*
Tree Delete(ElementType X,Tree T)
{
	Node TmpCell;

	if(T== NULL)
		printf("Element not found");
	else
		if (X < T->Element)
			T->Left = Delete(X, T->Left);
		else
			if(X > T->Element)
				T-> Right = Delete(X, T->Right);
			else
				//Nut co 2 con
				if(T->Left!=NULL && T->Right!=NULL)
				{
					TmpCell = FindMin(T->Right);
					T->Element = TmpCell->Element;
					T->Right = Delete(T->Element, T->Right);
				}
				else
				{
					TmpCell = T;
					//Nut co 1 con ben phai
					if (T->Left == NULL)
						T = T->Right;
					//Nut co 1 con ben trai
					else if (T->Right == NULL)
						T = T->Left ;
					//Xoa nut
					free(TmpCell);
				}
		return T;

}
*/
ElementType Retrieve(Node P)
{
	return P->Element;
}



