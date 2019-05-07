#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;


typedef int ElementType;

typedef struct Node *PtrToNode;

typedef PtrToNode Stack;
typedef PtrToNode Position;

struct Node
{
	ElementType Element;
	Position    Next;
};


// Khai bao nguyen mau ham-------------------------------

void Makenull_Stack( Stack& S );
int IsEmpty_Stack( Stack S );
void Push( ElementType X, Stack S );
void Pop(Stack S);
ElementType Top(Stack S);

char* sosangchuoi(int n, int coso);
char* chuyen10sang2816(int n, int k);
int chuoisangso(char c, int coso);
int chuyen2816sang10(char *bt, int k);
// Chuong trinh chinh-------------------------------------
int main()
{

	int n, k;
	printf("Nhap n can chuyen doi: ");
	scanf("%d", &n);
	printf("Nhap co so k: ");
	scanf("%d", &k);
	char* kqcd= chuyen10sang2816(n, k);
	printf("So %d khi chuyen sang he co so %d la %s\n", n, k, kqcd);
	 
	char bt[50];
	int k1;
	printf("-----------------------\n");
	fflush(stdin);
	printf("Nhap chuoi bieu thuc: ");
	gets(bt);
	printf("Nhap co so bieu thuc: ");
	scanf("%d", &k1);
	int kqcd2= chuyen2816sang10(bt, k1);
	printf("Gia tri %s trong he co so %d khi chuyen sang co so 10 %d\n", bt, k1, kqcd2);
	return 1;
}
char* sosangchuoi(int n, int coso)
{
	char *s= new char[2];
	s[1]='\0';
	if(coso==2 || coso==8)
		s[0]= n + 48;
	if( coso==16)
	{
		if(n<10)
			s[0] = n + 48;
		else
			s[0]= n + 55;	
		}
		return s;	
}
char* chuyen10sang2816( int n, int k)
{
	Stack S;
	Makenull_Stack(S);
	char *kq = new char[100];
	strcpy(kq, "");
	int sodu;
	while(n!=0)
	{
		sodu = n%k;
		Push(sodu, S);
		n = n/k;
	}
	while(!IsEmpty_Stack(S))
	{
		strcat(kq, sosangchuoi(Top(S), k));
		Pop(S);
		
	}
	return kq;
	
}
int chuoisangso( char c, int coso)
{
	if(coso==2 || coso==8)
		return c-48;
	if(coso==16)
	{
		if(c>'0' && c<='9')
			return c-48;
		else
			return c-55;	
		}	
}
int chuyen2816sang10(char *bt, int k)
{
	int len = strlen(bt);
	int i=len-1;
	int n=0;
	while(i>=0)
	{
		n = n+ chuoisangso(bt[i], k)*pow(k,len-1-i);
		i--;
	}
	return n;	
}
// Dinh nghia ham-----------------------------------------
/*Tao 1 stack rong*/
void  Makenull_Stack( Stack &S )
{
	S = new Node;
	S->Next = NULL;
}

/* Kiem tra stack rong? */
int IsEmpty_Stack( Stack S )
{
	return S->Next == NULL;
}

/* Chen phan tu X vao stack  */
void  Push( ElementType X, Stack S )
{
	Position TmpCell, P;
	P = S;

	/*TmpCell =(List)malloc( sizeof( struct Node ) );*/
	TmpCell = new Node;
	if( TmpCell == NULL )
		cout<<"Out of space!!!" ;

	TmpCell->Element = X;

	TmpCell->Next = P->Next;

	P->Next = TmpCell;
}

/* Lay phan tu dau ra khoi stack */
void	Pop(Stack S )
{
	Position P, TmpCell;

	P = S;
	if( P->Next!=NULL )
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		delete TmpCell;
	}
}



/* Tim phan tu dau tien */
ElementType    Top( Stack S )
{
	return S->Next->Element;
}

