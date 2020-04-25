#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mutacje.h"


using namespace std;

void Mutacje::zamiana(Gen* tablicaGenow, int n)
{
	int pozycja01 = rand() % n;
	int pozycja02 = rand() % n;

	//cout << "zamiana pozycji  " << pozycja01 << " z pozycja " << pozycja02 << endl;

	// zamieniamy losowo 2 geny pozycjami
	Gen pom = tablicaGenow[pozycja01];
	tablicaGenow[pozycja01] = tablicaGenow[pozycja02];
	tablicaGenow[pozycja02] = pom;
}


void Mutacje::inwersja(Gen* tablicaGenow, int n)
{	
	int pozycja01 = rand() % n;
	int pozycja02 = rand() % n;
	
	while (pozycja01 == pozycja02)	// zeby obszar odwracania nie był wielkosci 0
	{
		pozycja01 = rand() % n;
	}
	if (pozycja01 > pozycja02)	// zeby na pozycji01 byla zawsze liczba <= niz na pozycji 02
	{
		int pom = pozycja01;
		pozycja01 = pozycja02;
		pozycja02 = pom;
	}
	
	//cout << endl << "Inwersja pozycji od  " << pozycja01 << " do " << pozycja02 << endl;

	int rozmiarInwersji = pozycja02 - pozycja01 +1;
	Gen* pom = new Gen[rozmiarInwersji];	// tworzymy tablice pomocnicza
	for (int i = 0; i < rozmiarInwersji; i++)
	{
		pom[i] = tablicaGenow[pozycja01 + i];	// utworzenie kopii fragmentu ktory ma podlegac inwersji
	}
	for (int i = 0; i < rozmiarInwersji; i++)
	{
		tablicaGenow[pozycja02 - i] = pom[i];	// wklejenie fragmentu w odwrotnej kolejnosci
	}
}