// soru3.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;
int main()
{
	// Deðiþken deðerlerimizi tanýmlýyoruz.
	int sayi;
	int tahmin;
	int hak = 0;
	int secenek;

	// Rastgele üretilecek sayý aralýðýný belirliyoruz.
	srand(time(NULL));
	sayi = 1000 + rand() % 8999;

	do {
		hak++; // Kullandýðýmýz tahmin haklarýnýn sayýlarýný her defasýnda 1 artýrarak sayý tahmin ediyoruz.
		cout << "Bir sayi tahmininde bulununuz : ";
		cin >> tahmin;

		if (sayi<tahmin && hak<20) // 20 tahmin hakký tanýyarak sayýnýn tahminden küçük olma durumunu belirliyoruz.
		{
			cout << "Buyuk Tahminde Bulundun!\n"; // Belirlenen þarta göre verilen metni yazdýrýyoruz.
		}
		
		else if (sayi>tahmin && hak<20) // 20 tahmin hakký tanýyarak sayýnýn tahminden büyük olma durumunu belirliyoruz.
			cout << "Kucuk Tahminde Bulundun!\n"; // Belirlenen þarta göre verilen metni yazdýrýyoruz.
		
		else if (sayi == tahmin) // Doðru tahmin etme durumu.
			cout << hak << ". hakkinizda bildiniz!\n"; // Tahminimizi kaçýncý seferde tutturduðumuzu yazdýrýyoruz.
		
		else
			cout << "Dogru tahminde bulunamadiniz!.\n"; // Tahmin haklarý dolduðu halde bilememiþsek bu metni yazdýrýyoruz.
	}

	while (tahmin != sayi && hak<20); // Tahmin sayýya eþit olmadýðý sürece 20 defa tekrarlama þartý döngüsü.

	getch();

	return 0;
}

