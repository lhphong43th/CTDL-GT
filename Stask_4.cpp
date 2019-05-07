#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>
using namespace std;

#define MaxLength  20
typedef char ElementType;
typedef struct{
	ElementType   Elements[MaxLength];
	int Top;
}Stack;

// Khai bao nguyen mau ham-------------------------------
void Makenull_Stack(Stack *S);
int IsEmpty_Stack(Stack S);
int IsFull_Stack(Stack S);
ElementType Top(Stack S);
void Push(ElementType X, Stack *S);
void Pop(Stack *S);

bool DauNgoac( char mo, char dong);
bool KiemTra( char bt[]);


// Chuong trinh chinh-------------------------------------
int main()
{
	char bieuthuc[50];
	printf("Nhap chuoi bieu thuc: ");
	gets(bieuthuc);
	if(KiemTra(bieuthuc))
		printf("Bieu thuc can bang\n");
	else
		printf("Bieu thuc khong can bang\n");	
	
	return 1;
}
bool DauNgoac( char mo, char dong)
{
	if(mo=='(' && dong==')')
		return true;
	if(mo=='[' && dong==']')
		return true;
	if(mo=='{' && dong=='}')
		return true;
	return false;			
}
bool KiemTra(char bt[])
{
	Stack S;
	Makenull_Stack(&S);
	int i;
	for(i=0; i<strlen(bt); i++)
	{
		if(bt[i]=='(' || bt[i]=='[' || bt[i]=='{')
			Push(bt[i], &S);
		else
			if(bt[i]==')' ||bt[i]==']' ||bt[i]=='}')
			{
				if(IsEmpty_Stack(S) || !DauNgoac(Top(S), bt[i]))
				{
					printf("Sai o ki tu thu %d\n", i+1);
					return false;
				}
				else
					Pop(&S);	
			}	
	}
	if(IsEmpty_Stack(S))
		return true;
	else
	{
		 printf("Thieu dau ngaoc o vi tri thu %d\n", i+1);
		 return false;	
	}
			
}

// Dinh nghia ham-----------------------------------------
void Makenull_Stack(Stack *S)
{
	S->Top = MaxLength;
}
int IsEmpty_Stack(Stack S)
{
	return (S.Top == MaxLength);
}
int IsFull_Stack(Stack S)
{
	return (S.Top == 0);
}
ElementType Top(Stack S)
{
	if (!IsEmpty_Stack(S))
		return S.Elements[S.Top];
	else
		printf("\n Ngan xep rong");
}
void Pop(Stack *S)
{
	if (!IsEmpty_Stack(*S))
		S->Top ++;
	else
		printf("\n Ngan xep rong");
}
void Push(ElementType X, Stack *S)
{

	if (IsFull_Stack(*S))
		printf("\n Ngan xep day");
	else
	{

		S->Top--;
		S->Elements[S->Top] =X;

	}
}

