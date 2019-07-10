#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double aylikOdemeHesapla (double,double,double); //double türünden fonksiyon tanýmladýk.
int main(int argc, char *argv[]) {
	int i; //integer türünden bir i deðiþkeni tanýmladýk.
	double krediTutari, faizOrani, taksitSayisi, toplamKrediOdemesi=0; //double türünden deðiþkenlerimizi tanýmladýk.
	double kalanAnaParaBorcu=krediTutari, odenenFaizTutari, odenenAnaParaTutari; //double türünden, deðiþkenlerimizi tanýmladýk.
	
	//Ödev metninde belirtildiði gibi gerekli girdilerimizi aldýk.
	printf("Toplam Kredi Miktari : "); 
	scanf("%lf", &krediTutari);
	
	printf("Faiz Orani  : ");
	scanf("%lf", &faizOrani);
	
	printf("Taksit Sayisi  : ");
	scanf("%lf", &taksitSayisi);
	
	double aylikTaksitTutari = aylikOdemeHesapla (krediTutari, faizOrani ,taksitSayisi); //Hesaplamalar için double deðiþkenler

	printf("\nTaksit No \t\t   Taksit Tutari \t Odenen Faiz Tutari \t Odenen Ana Para Tutari \t Kalan Ana Para Borcu"); //Bulunan deðerleri yazdýrmak için
	
	kalanAnaParaBorcu=krediTutari; //Atama iþlemi
	
	for (i=1; i<=taksitSayisi; i++) { //taksit sayýsý>=i ise
	
		//kredi iþlemleri
		odenenFaizTutari = kalanAnaParaBorcu * (faizOrani/100); 
		odenenAnaParaTutari = aylikTaksitTutari - odenenFaizTutari ;
		kalanAnaParaBorcu = kalanAnaParaBorcu  - odenenAnaParaTutari;
		
		printf("\n   %d\t\t\t\t%.2lf\t\t         %.2lf\t\t\t  %.2lf\t\t\t      %.2lf", i, aylikTaksitTutari, odenenFaizTutari, odenenAnaParaTutari, kalanAnaParaBorcu); //Bulunan deðerleri yazdýrmak için	
		
   	    toplamKrediOdemesi = toplamKrediOdemesi + odenenAnaParaTutari; //Atama iþlemi yapýldý
	   
	}
	
	//Aylýk ödeme ve toplam kredi ödemesini yazdýrmak için
    printf("\n\nAylik Odemeniz : \t%.2lf", aylikTaksitTutari);
	printf("\nToplam Kredi Odemesi : \t%.2lf", aylikTaksitTutari*taksitSayisi);
	
	return 0;
	
}

double aylikOdemeHesapla (double krediTutari, double faiz, double taksitSayisi) { //Fonksiyonumuzu çaðýrdýk.
	//Faiz oraný hesaplama
	double faizOrani = faiz/100; 
	return  krediTutari * (faizOrani*pow(1+faizOrani,taksitSayisi) / (pow(1+faizOrani,taksitSayisi)-1) ); //Tutarlarý hesaplayýp döndürüyor.
} 
