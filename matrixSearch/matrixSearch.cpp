# include<fstream>
# include<iostream>

using namespace std;

void MatrisOku(char[],int[][100],int&,int&);
void SonucYaz(char[],int[][2],int);
int Arama(const int [][100],const int[][100],int[][2],int,int,int,int); 

/* ilk parametre AnaMatris,ikinci parametre arananMatris,
 ucuncu parametre bulunan sonuçlarin indislerinin yazildigi matris.
 Diger parametrelerde sirasiyla ana matrisin ve aranan matrisin satir ve sutun degeleri.
 fonksiyon geriye aranan matrsinin ana matris icersinde kac defa gectigini dondurecek.
 */

int main()
{
  char dosyaAdi1[]="AnaMatris.txt";
  char dosyaAdi2[]="ArananMatris.txt";
  char dosyaAdi3[]="Sonuc.txt";
  int anaMatris[100][100]; // maksimum 100*100 boyutunda oldugunu varsayin
  int arananMatris[100][100]; //// maksimum 100*100 boyutunda oldugunu varsayin
  int sonuclar[100][2]; // aranan matrisin maksimum 100 defa bulunabilecegini varsayin
  
  int satir,sutun; //ana matrisin satir ve sutun degerleri
  int arananSatir, arananSutun; // aranan matrisin satir ve sutun degerleri
  int sonucSayisi;
  
  
  MatrisOku(dosyaAdi1,anaMatris,satir,sutun); // Dosyadan Ana matrisi oku
  MatrisOku(dosyaAdi2,arananMatris,arananSatir,arananSutun); // Dosyadan Aranan matrisi oku
  
  sonucSayisi=Arama(anaMatris,arananMatris,sonuclar,satir,sutun,arananSatir,arananSutun); // Arama Islemi
  
  SonucYaz(dosyaAdi3,sonuclar,sonucSayisi);
}

/* Örnek dosyadan okuma ve yazma kodlarý:

Dosyaya veri yazdýrmak için:

int sayi = 5;
ofstream yazdir("dosyaAdi.txt", ios::app); 
yazdir << sayi << endl;// 5 degerini dosyaya yazdirir
yazdir.close();// dosyaya yazma iþlemi sonlandirilir


Dosyadan veri okumak için:

ifstream oku;
oku.open(“dosyaAdi.txt”);
oku>>degiskenAdi; // burada tek deger okunup degiskene atandi. Birden fazla deger okumak icin dongu kullaniniz.
oku.close();//dosyadan okuma islemi sonlandirilir

*/


//Aþaðýdaki fonksiyonlarýn içini doldurarak ödevinizi kodlayýnýz.
void MatrisOku(char dosyaAdi[],int matris[][100],int &satir,int &sutun)
{   
 ifstream oku; // okuma üzerinde bir dosya aç
 oku.open(dosyaAdi);
 oku>>satir>>sutun; // ilk iki satýr okumak için (dizinin iki boyutu)
 for(int i = 0; i < satir; i++)
 {
    for(int j = 0; j < sutun; j++ )
	{
	    oku >> matris[i][j]; // dosyadan dizinin elemanlarý oku ve diziye at (dosyanýn üçüncü satýr ve sonra
		cout << matris[i][j]<< ' '; // debug amacýyla diziyi ekrana yazdýrdýk
	}
	cout << '\n';
 } //65.satýr
 cout << '\n';
 oku.close(); // dosya kapat 
}//60.satýr
void SonucYaz(char dosyaAdi[],int sonuclar[][2],int sonucSayisi)
{
 ofstream yazdir(dosyaAdi, ios::app); // yazma amacýyla bir dosya aç
 yazdir << sonucSayisi << endl;// ilk satýrda sounsayýsýs yazdýr ve alt satýra geç
 for(int i = 0; i < sonucSayisi; i++)
 {
    for(int j = 0; j < 2; j++ )
	{
	        yazdir << sonuclar[i][j] << ' ';
		cout << sonuclar[i][j]<< ' ';
 	}
	yazdir << endl;
	cout << '\n';
 }//81.satýr
 yazdir.close();	
}//77.satýr
int Arama(const int anaMatris[][100],const int arananMatris[][100],int sonuc[][2],int satir,int sutun,int arananSatir,int arananSutun)
{
 int count=0; // souncSayýsý
 int bulundu, i,j,p,q; // arama algoritma için 4 tane döngü sayacý tanýmladýk ve eðer arana matris
//bulundu ise bulundu degiþkenin deðeri bir olsun bool veri tipinde de tanýmlasak olurdu
 for(i=0; i<satir; i++)
 {
   for(j=0; j<sutun; j++)
   {// ana Matrisi içinde tara 
      bulundu=1;
      for(p=0; p<arananSatir; p++)
      { //elemanlari tek tek aliyoruz ve bizim aranan matris boyutlarýna göre arama yapýyoruz
         for(int q=0; q< arananSutun; q++)
         {
            if(anaMatris[i+p][j+q] != arananMatris[p][q])//eger eleman komularýna eþit deðilse 
            {
               bulundu=0;//yani aranan matris bulunamdý  
               break; // ve birsonraki elemana geçiyoruz 
              
            }
         }
      }
      if(bulundu==1) // eðer matris bulundý ise 
      {
      	   ++count; // sonucsayýsý artýr
           printf("aranan matris bu indislerde bulundu : %d, %d\n",i ,j); // debug amacýyla sonuçlar ekrana da gözüksün
           sonuc[count-1][0]=i; // sonuçlar sonuc matrise aktardýk (sonuç dosyasý)
           sonuc[count-1][1]=j;
           
       
      }
   }
   if(bulundu==1)
   {
   	    ++count;
        printf("\naranan matris bu indislerde bulundu %d, %d\n",i ,j);
        sonuc[count-1][0]=i;
        sonuc[count-1][1]=j;
        
      
   }
 }
 return count;	// sonuç sayýsýs döndür
}
