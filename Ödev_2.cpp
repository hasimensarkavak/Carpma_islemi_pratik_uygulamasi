#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Haþim Ensar Kavak 2018280027

int basariY,dogrular=0;    //her yerde eriþmek istedim

void A(int* ilk,int* ikinci,int* cvp,int sayac,int boyut)
{
	int cevap,i,d,y;
	basariY=0;
	srand(time(NULL));
	
	for(i=sayac;i<boyut;i++)		//sayac ve boyut tekrar 10 soru sormam gerekirse diye.
	{
		*(ilk+i)=1+rand()%9;										//sayýlarý oluþturmayla cevabý almayý ayný for da yaptým.
		*(ikinci+i)=1+rand()%9;
		printf("%d) %d kere %d kaçtýr?==>",i+1,*(ilk+i),*(ikinci+i));
		scanf("%d",&cevap);
		*(cvp+i)=cevap;
		if((*(ilk+i))*(*(ikinci+i))==*(cvp+i))
		{
			dogrular++;
			d=1+rand()%4;
			switch(d)
			{
				case 1: printf("Çok GÜzel\n");
				break;
				case 2: printf("Mükemmel\n");
				break;
				case 3: printf ("Aferin\n");
				break;
				case 4: printf("Böyle Devam Et\n");
				break;
			}
			printf("\n");
		}
		else
		{
			y=1+rand()%4;
			switch(y)
			{
				case 1: printf("Hayýr. Lütfen tekrar deneyin\n");
				break;
				case 2: printf(" Yanlýþ. Lütfen bir daha deneyin\n");
				break;
				case 3: printf (" Pes etmeyin\n");
				break;
				case 4: printf("Hayýr. Denemeye devam edin\n");
				break;
			}
			printf("\n");
		}
	}
	basariY=dogrular*100/boyut;
}

void B(int* ilk,int* ikinci,int* cvp,int j)
{
	int i;
	printf("*************ÖZET TABLO****************\n\n");
	printf("-----SORULAR--------ÖÐRENCÝNÝN CEVABI---ASIL CEVAP\n\n");
	for(i=0;i<(10*j);i++)
	{
		printf("%d) %d kere %d kaçtýr?	  %d		%d\n",i+1,*(ilk+i),*(ikinci+i),*(cvp+i),(*(ilk+i))*(*(ikinci+i)));
	}
	printf("\nÖðrencinin baþarý yüzdesi= Yüzde %d",basariY);
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	int soruS=10,i=1,j=0;
	int *ilkRakam=(int*)malloc(soruS*sizeof(int));
	int *ikinciRakam=(int*)malloc(soruS*sizeof(int));
	int *cevaplar=(int*)malloc(soruS*sizeof(int));
	
	do
	{
		A(ilkRakam,ikinciRakam,cevaplar,j,(soruS*i));
		printf("\nBaþarý yüzdeniz ==> Yüzde  %d \n",basariY);
		if(basariY<85 && basariY>75)							//tekrar 10 soru kullanmam gerekmezse dizilerin boyutlarýný boþuna
		{														// büyütmemek için if kullandým.
			printf("Bu yüzden 10 soru daha cevaplamalýsýn.\n\n");
			j+=10;													// dizilerin istediðim kýsýmlarýna gitmek için i ve j kullandým.
			i++;        
			ilkRakam=(int *)realloc(ilkRakam,(soruS*i)*sizeof(int));
			ikinciRakam=(int *)realloc(ikinciRakam,(soruS*i)*sizeof(int));
			cevaplar=(int *)realloc(cevaplar,(soruS*i)*sizeof(int));
		}
		if(basariY<75)
		{
			printf("Üzülme ve çarpým tablosunu bir daha çalýþ.\n\n\n\n");
			break;
		}
		if(basariY>85)
		{
			printf("Aferin baþardýn!\n\n\n\n");
			break;
		}
	}while(basariY<85 && basariY>75);
	
	B(ilkRakam,ikinciRakam,cevaplar,i);
}

//Kaynaklar
// Ders sunumlarý
//http://zeynepbote.blogcu.com/c-de-rand-srand-time-null-komutu-ve-kullanim-ornekleri/9906228
