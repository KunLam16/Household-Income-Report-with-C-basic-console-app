#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct
{
    char TenChuHo[10];
    char DiaChiHo[10];
    char MaHo[10];
    int SoNguoi;
    int ThuNhap;
    char GhiChu[20];
    int ThuNhapBinhQuan;

} HoGiaDinh;
void Nhap(HoGiaDinh A[],int n)
{
    int i;
    for (i=1;i<=n;i++)
    {
        printf("Nhap vao ten cua chu ho thu %d:\n",i);
        fflush(stdin);
        gets(A[i].TenChuHo);fflush(stdin);

        printf("Nhap vao ma so cua ho thu %d:\n",i);
        gets(A[i].MaHo);fflush(stdin);

        printf("Nhap vao dia chi cua ho thu %d:\n",i);
        gets(A[i].DiaChiHo);fflush(stdin);

        printf("Nhap vao so nguoi cua ho thu %d:\n",i);
        scanf("%d",&A[i].SoNguoi);

        printf("Nhap vao tong thu nhap trong nam cua ho thu %d:\n",i);
        scanf("%d",&A[i].ThuNhap);

    }
}
void Tinh(HoGiaDinh A[],int n)
{
    int i;
    int TongSoNguoi=0;

    for (i=1;i<=n;i++)
     TongSoNguoi=TongSoNguoi+A[i].SoNguoi;
     printf("Phuong My Dinh co tong so nguoi trong cac ho gia dinh la %d nguoi\n",TongSoNguoi);
    for (i=1;i<=n;i++)
        A[i].ThuNhapBinhQuan=A[i].ThuNhap/A[i].SoNguoi;

}
void In1(HoGiaDinh A[],int n)
{
    int i;
    for (i=1;i<=n;i++)
    {
        if (A[i].ThuNhapBinhQuan<5000000) strcpy(A[i].GhiChu,"Huong Tro Cap");  else strcpy(A[i].GhiChu,"Khong Huong Tro Cap");
    }
    printf("Thong tin cua cac ho gia dinh co nhieu hon 10 nguoi:");
    printf("\n\n                 BANG THONG TIN CUA CAC HO GIA DINH NHIEU HON 10 NGUOI  \n");
    printf("======================================================================================================== \n");
    printf("| STT |   MA HO GD   |     TEN CHU HO     |    TONG THU NHAP TRONG NAM    |          GHI CHU           | \n");
    printf("======================================================================================================== \n");
    for (i=1;i<=n;i++)
        if(A[i].SoNguoi>10)
        {
    printf("| %3d |  %-10s  |  %-16s  |  %-27d  |    %-20s    | \n",i,A[i].MaHo,A[i].TenChuHo,A[i].ThuNhap,A[i].GhiChu);
    printf("-------------------------------------------------------------------------------------------------------- \n");
        }
    printf("=========================================================================================================\n");
}
void SapXep(HoGiaDinh A[],int n)
{
    int i,j;
    HoGiaDinh tg;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
         if (A[i].ThuNhap<A[j].ThuNhap)
        {

            tg=A[i];
            A[i]=A[j];
            A[j]=tg;
        }
}
void In2(HoGiaDinh A[],int n)
{
    int i;
    printf("Bang sau khi sap xep la: \n\n");
    printf("\n\n                 BANG THONG TIN CUA CAC HO GIA DINH   \n");
    printf("======================================================================================================== \n");
    printf("| STT |   MA HO GD   |     TEN CHU HO     |    TONG THU NHAP TRONG NAM    |          GHI CHU           | \n");
    printf("======================================================================================================== \n");
    for (i=1;i<=n;i++)
        {
    printf("| %3d |  %-10s  |  %-16s  |  %-27d  |    %-20s    | \n",i,A[i].MaHo,A[i].TenChuHo,A[i].ThuNhap,A[i].GhiChu);
    printf("-------------------------------------------------------------------------------------------------------- \n");
        }
    printf("=========================================================================================================\n");
}
int main()
{
    HoGiaDinh M[20];
    int n;
    printf("Nhap vao so ho gia dinh: ");scanf("%d",&n);
    Nhap(M,n);
    Tinh(M,n);
    In1(M,n);
    SapXep(M,n);
    In2(M,n);
    getch();
}
