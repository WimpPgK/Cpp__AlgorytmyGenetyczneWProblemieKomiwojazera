#pragma once
#include "Gen.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Osobnik
{
private:
	
	bool sprawdzLiczbe(int liczba, Gen* tab);
	bool sprawdzLiczbe(int liczba, int* tab);

public:
	int rozmiar;			// ilosc genow
	Gen* tablicaGenow;		// tablica w ktorej przechowywana jest cala informacja genetyczna
	double wartoscFunkcjiCelu;

	void inicjalizuj(Gen* przestrzenGenow, int n);
	void inicjalizuj(int n, int krokInicjalizacji); // inicjalizacja z jakims krokiem w celach testowych
	void inicjalizuj(string nazwaPliku);			// inicjalizacja z pliku
	void inicjalizuj(int n);						// inicjalizacja liczbami losowymi bez powtorzen
	void inicjalizujZerami(int n);
	void inicjalizujOsobnik1();						// inicjalizacja ustalonymi w kodzie danymi w celach testowych
	void inicjalizujOsobnik2();

	void wypiszGeny();
	

};

