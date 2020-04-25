#include "Osobnik.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Osobnik::inicjalizuj(Gen* przestrzenGenow, int n)
{
	wartoscFunkcjiCelu = -1;
	tablicaGenow = new Gen[n];
	int* tab = new int[n];
	rozmiar = n;

	int liczbaLosowa;
	for (int i = 0; i < n; i++)
	{
		liczbaLosowa = rand() % n;
		if (sprawdzLiczbe(liczbaLosowa, tab) == false)
		{
			i -= 1;
		}
		else
		{
			tab[i] = liczbaLosowa;
		}
	}
	

	/*
		teraz tworzymy osobnika ktory bedzie posiadac losowa kolejnosc genow
	*/

	for (int i = 0; i < n; i++)
	{
		tablicaGenow[i].ID = przestrzenGenow[tab[i]].ID;
		tablicaGenow[i].pozycja_x = przestrzenGenow[tab[i]].pozycja_x;
		tablicaGenow[i].pozycja_y = przestrzenGenow[tab[i]].pozycja_y;
	}

	delete[]tab;
}

void  Osobnik::inicjalizuj(int n, int krokInicjalizacji)
{
	rozmiar = n;
	wartoscFunkcjiCelu = -1;
	tablicaGenow = new Gen[n];
	for (int i = 0; i < n; i++)
	{
		tablicaGenow[i].ID = i*krokInicjalizacji;
		tablicaGenow[i].pozycja_x = i * krokInicjalizacji;
		tablicaGenow[i].pozycja_y = i * krokInicjalizacji;
	}

}

void Osobnik::inicjalizuj(string nazwaPliku)
{
	wartoscFunkcjiCelu = -1;
	//cout << "Inicjalizacja z pliku" << endl;
}

void Osobnik::inicjalizuj(int n)
{

	rozmiar = n;
	wartoscFunkcjiCelu = -1;
	tablicaGenow = new Gen[n];	// utworzenie 
	int i;
	
	for (int i = 0; i < n; i++)
	{
		tablicaGenow[i].ustawWartosci(-1, -1, -1);

	}

	int liczbaLosowa;
	for(int i = 0; i < n; i++)
	{
		liczbaLosowa = rand() % n + 1;
		if (sprawdzLiczbe(liczbaLosowa, tablicaGenow) == false)
		{
			i -= 1;
		}
		else
		{
			tablicaGenow[i].ID = liczbaLosowa;
			tablicaGenow[i].pozycja_x = liczbaLosowa;
			tablicaGenow[i].pozycja_y = liczbaLosowa;
		}
	}

}

void Osobnik::inicjalizujZerami(int n)
{
	wartoscFunkcjiCelu = -1;
	tablicaGenow = new Gen[n];
	rozmiar = n;


	for (int i = 0; i < n; i++)
	{
		
		tablicaGenow[i].ID = 0;
		tablicaGenow[i].pozycja_x = 0;
		tablicaGenow[i].pozycja_y = 0;

	}
}

void Osobnik::inicjalizujOsobnik1()
{

	rozmiar = 9;
	tablicaGenow = new Gen[9];

	tablicaGenow[0].ID = 1;
	tablicaGenow[1].ID = 2;
	tablicaGenow[2].ID = 3;
	tablicaGenow[3].ID = 4;
	tablicaGenow[4].ID = 5;
	tablicaGenow[5].ID = 6;
	tablicaGenow[6].ID = 7;
	tablicaGenow[7].ID = 8;
	tablicaGenow[8].ID = 9;

}
void Osobnik::inicjalizujOsobnik2()
{
	rozmiar = 9;
	tablicaGenow = new Gen[9];

	tablicaGenow[0].ID = 9;
	tablicaGenow[1].ID = 3;
	tablicaGenow[2].ID = 7;
	tablicaGenow[3].ID = 8;
	tablicaGenow[4].ID = 2;
	tablicaGenow[5].ID = 6;
	tablicaGenow[6].ID = 5;
	tablicaGenow[7].ID = 1;
	tablicaGenow[8].ID = 4;
}

bool Osobnik::sprawdzLiczbe(int liczba, Gen* tab)
{
	int n = rozmiar;
	int i;
	for (i = 0; i < n; i++)
	{
		if (tab[i].ID == liczba)
			return false;

	}
	return true;
}

bool Osobnik::sprawdzLiczbe(int liczba, int* tab)
{
	int n = rozmiar;
	int i;
	for (i = 0; i < n; i++)
	{
		if (tab[i] == liczba)
			return false;

	}
	return true;
}


void Osobnik::wypiszGeny()
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << "Gen " << i << ":   " << tablicaGenow[i].ID << "  " << tablicaGenow[i].pozycja_x <<"  " << tablicaGenow[i].pozycja_y << endl;
	}
}

