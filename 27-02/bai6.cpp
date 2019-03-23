#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace  std;

#define MaxLength 100
struct SinhVien
{
	char MSSV[10];
	char HoTen[50];
	float DiemTX, DiemThi,DiemMH;
	char XepLoai[20];
};
typedef int Position;
typedef SinhVien ElementType;
typedef struct 
{
	ElementType Elements[MaxLength];
	Position Last;
}List;

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

void Read_List(List *L);
void Print_List(List L);
void Tinh_Diem(List &L);
void Xep_Loai(List &L);
int DemSL(List L);
void Sort_List1(List &L);
void Sort_List2(List &L);
//ham chinh
int main()
{
	List ds; Makenull_List(&ds);
	Read_List(&ds);
	Tinh_Diem(ds);
	Xep_Loai(ds);
	Print_List(ds);
	
	int kq= DemSL(ds);
	printf("So luong sinh vien co diem tu 5.0 tro len la: %d\n", kq);
	Sort_List1(ds);
	Sort_List2(ds);
	
	printf("Sap xep theo MSSV\n");
	Sort_List2(ds);
	Print_List(ds);
	getch();
	return 1;
} 

void Read_List(List *L)
{
	ElementType X;
	int n;
	Makenull_List(L);
	printf("NHAP DANH SACH\n");
	printf("-Nhap so luong phan tu: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		printf("-Nhap phan tu thu %d: \n", i+1);
		fflush(stdin);
		printf("-Nhap MSSV: ");
		gets(X.MSSV);
		printf("-Nhap ho ten: ");
		gets(X.HoTen);
		printf("-Diem thuong xuyen: ");
		scanf("%f", &X.DiemTX);
		printf("-Diem thi: ");
		scanf("%f", &X.DiemThi);
		//X.DiemMH = (X.DiemTX+X.DiemThi)/2;
		Insert_List(X, End_List(*L), L);
	}
}
void Print_List(List L)
{
	if(isEmpty_List(L))
		printf("Danh sach rong\n");
	else
	{
		printf("CAC PHAN TU TRONG DANH SACH\n");
		for(Position i=First_List(L); i<End_List(L); i=Next(i, L))
		{
			printf("+MSSV: %s\n", L.Elements[i-1].MSSV); 
			printf("+Ho ten: %s\n", L.Elements[i-1].HoTen);
			printf("+Diem TX: %f\n", L.Elements[i-1].DiemTX);
			printf("+Diem thi: %f\n", L.Elements[i-1].DiemThi);
			printf("+Diem mon hoc: %f\n", L.Elements[i-1].DiemMH);
			printf("+Xep loai: %s\n", L.Elements[i-1].XepLoai);
			printf("--------------------\n");
		}
	}
}
void Tinh_Diem(List &L)
{
	if(isEmpty_List(L))
		printf("Danh sach rong\n");
	else
	{
		printf("TINH DIEM CHO CAC PHAN TU TRONG DANH SACH\n");
		for(Position i=First_List(L); i<End_List(L); i=Next(i, L))
		{
			L.Elements[i-1].DiemMH =(L.Elements[i-1].DiemTX+ L.Elements[i-1].DiemThi)/2;
		}
	}		
}	
void Xep_Loai(List &L)
{
	if(isEmpty_List(L))
		printf("Danh sach rong\n");
	else
	{
		printf("XEP LOAI CHO CAC PHAN TU TRONG DANH SACH\n");
		for(Position i=First_List(L); i<End_List(L); i=Next(i, L))
		{
			if(L.Elements[i-1].DiemMH>=8.5)
				strcpy(L.Elements[i-1].XepLoai, "Gioi");
			if(L.Elements[i-1].DiemMH>=7.0 && L.Elements[i-1].DiemMH<8.5)
				strcpy(L.Elements[i-1].XepLoai, "Kha");
			if(L.Elements[i-1].DiemMH>=5.5 && L.Elements[i-1].DiemMH<7.0)	
				strcpy(L.Elements[i-1].XepLoai, "Trung binh kha");
			if(L.Elements[i-1].DiemMH>=4.0 && L.Elements[i-1].DiemMH<5.5)	
				strcpy(L.Elements[i-1].XepLoai, "Trung binh");
			if(L.Elements[i-1].DiemMH<4.0)
				strcpy(L.Elements[i-1].XepLoai, "Yeu");
		}
	}		

}
int DemSL(List L)
{
	int dem=0;
	if(isEmpty_List(L))
		printf("Danh sach rong\n");
	else
	{
		printf("DEM SO LUONG SINH VIEN\n");
		for(Position i=First_List(L); i<End_List(L); i=Next(i, L))
		{
			if(L.Elements[i-1].DiemMH>=5)
				dem++;
		}
	}
	return dem;		
}
void Sort_List1(List &L)
{
	printf("SAP XEP CHO CAC PHAN TU TRONG DANH SACH\n");
	for (Position i=First_List(L); i<End_List(L); i=Next(i, L))
	{
		for(Position j=Next(i, L); j<End_List(L); j=Next(j, L))
		{
			if(L.Elements[j-1].DiemMH < L.Elements[i-1].DiemMH)
			{
				ElementType t;
				t = L.Elements[i-1];
				L.Elements[i-1] = L.Elements[j-1];
				L.Elements[j-1] = t;
			}
		}
	}
}
void Sort_List2(List &L)
{
	printf("SAP XEP CHO CAC PHAN TU TRONG DANH SACH\n");
	for (Position i=First_List(L); i<End_List(L); i=Next(i, L))
	{
		for(Position j=Next(i, L); j<End_List(L); j=Next(j, L))
		{
			if(strcmp(L.Elements[j-1].MSSV , L.Elements[i-1].MSSV)<0)
			{
				ElementType t;
				t = L.Elements[i-1];
				L.Elements[i-1] = L.Elements[j-1];
				L.Elements[j-1] = t;
			}
		}
	}
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
		if (strcmp (Retrieve(P,L).MSSV, X.MSSV)==0)
			found =1;
		else
			P=Next(P,L);
	}
	return P;
}






