#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Ha�im Ensar Kavak 2018280027

int basariY,dogrular=0;    //her yerde eri�mek istedim

void A(int* ilk,int* ikinci,int* cvp,int sayac,int boyut)
{
	int cevap,i,d,y;
	basariY=0;
	srand(time(NULL));
	
	for(i=sayac;i<boyut;i++)		//sayac ve boyut tekrar 10 soru sormam gerekirse diye.
	{
		*(ilk+i)=1+rand()%9;										//say�lar� olu�turmayla cevab� almay� ayn� for da yapt�m.
		*(ikinci+i)=1+rand()%9;
		printf("%d) %d kere %d ka�t�r?==>",i+1,*(ilk+i),*(ikinci+i));
		scanf("%d",&cevap);
		*(cvp+i)=cevap;
		if((*(ilk+i))*(*(ikinci+i))==*(cvp+i))
		{
			dogrular++;
			d=1+rand()%4;
			switch(d)
			{
				case 1: printf("�ok G�zel\n");
				break;
				case 2: printf("M�kemmel\n");
				break;
				case 3: printf ("Aferin\n");
				break;
				case 4: printf("B�yle Devam Et\n");
				break;
			}
			printf("\n");
		}
		else
		{
			y=1+rand()%4;
			switch(y)
			{
				case 1: printf("Hay�r. L�tfen tekrar deneyin\n");
				break;
				case 2: printf(" Yanl��. L�tfen bir daha deneyin\n");
				break;
				case 3: printf (" Pes etmeyin\n");
				break;
				case 4: printf("Hay�r. Denemeye devam edin\n");
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
	printf("*************�ZET TABLO****************\n\n");
	printf("-----SORULAR--------��RENC�N�N CEVABI---ASIL CEVAP\n\n");
	for(i=0;i<(10*j);i++)
	{
		printf("%d) %d kere %d ka�t�r?	  %d		%d\n",i+1,*(ilk+i),*(ikinci+i),*(cvp+i),(*(ilk+i))*(*(ikinci+i)));
	}
	printf("\n��rencinin ba�ar� y�zdesi= Y�zde %d",basariY);
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
		printf("\nBa�ar� y�zdeniz ==> Y�zde  %d \n",basariY);
		if(basariY<85 && basariY>75)							//tekrar 10 soru kullanmam gerekmezse dizilerin boyutlar�n� bo�una
		{														// b�y�tmemek i�in if kulland�m.
			printf("Bu y�zden 10 soru daha cevaplamal�s�n.\n\n");
			j+=10;													// dizilerin istedi�im k�s�mlar�na gitmek i�in i ve j kulland�m.
			i++;        
			ilkRakam=(int *)realloc(ilkRakam,(soruS*i)*sizeof(int));
			ikinciRakam=(int *)realloc(ikinciRakam,(soruS*i)*sizeof(int));
			cevaplar=(int *)realloc(cevaplar,(soruS*i)*sizeof(int));
		}
		if(basariY<75)
		{
			printf("�z�lme ve �arp�m tablosunu bir daha �al��.\n\n\n\n");
			break;
		}
		if(basariY>85)
		{
			printf("Aferin ba�ard�n!\n\n\n\n");
			break;
		}
	}while(basariY<85 && basariY>75);
	
	B(ilkRakam,ikinciRakam,cevaplar,i);
}

//Kaynaklar
// Ders sunumlar�
//http://zeynepbote.blogcu.com/c-de-rand-srand-time-null-komutu-ve-kullanim-ornekleri/9906228
