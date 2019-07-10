// soru2.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;
int main()
{
	//Deðiþken tanýmlarýmýzý yaptýk.
	int a, b, c, i;
	int sayac = 0, toplam = 0;
	int iSay, jSay; 

	for (i = 100; i <= 999; i++) // Sayý deðerimizi 100'den baþlatarak 999'a kadar bir döngüye sokuyoruz.
	{
		// Aþaðýda sayýlarýmýzýn basamak deðerlerini bulmamýzý saðlayacak formüller yazýyoruz. 
		a = i % 10; // Birler basamaðý
		b = (i % 100) / 10; // Onlar basamaðý
		c = (i - 10 * b - a) / 100; // Yüzler basamaðý

		if (a != b && b != c && a != c) // Sayýlarýmýza rakamlarýnýn farklý olmasý þartýný saðlýyoruz.
		{
			cout << " " << i; // Sayýlarýmýzý yazdýrýyoruz.
			sayac++;
		}
	}

	cout << "\n3 BASAMAKLI RAKAMLARI FARKLI " << sayac << " SAYI VARDIR."; // Sayýlarýn adetini yazdýrýyoruz.

	for (iSay = 100; iSay<999; iSay++) // 3 basamaklý sayýlar arasýnda yeni bir döngü kuruyoruz.
	{
		toplam = 0; // Toplam bir deðer bulacaðýmýz için bu toplam deðerini ilk olarak 0'a eþitliyoruz.

		for (jSay = 1; jSay <= iSay / 2; jSay++) // Sayýlarýmýzýn bölenlerini hesaplayacak döngüyü baþlatýyoruz.
		{
			if (iSay%jSay == 0) // Mükemmel sayýlarýmýzý hesaplayacak iþlemi gerçekleþtiriyoruz.
				toplam += jSay;
		}

		if (toplam == iSay) //Mükemmel sayý olma þartýný saðlayacak döngüyü kuruyoruz.
			cout << "\n3 BASAMAKLI MUKEMMEL SAYILAR : " << toplam; // Ve toplam mükemmel sayýlarýmýzý yazdýrýyoruz.
	}

	getch();

	return 0;
}



