#pragma once
#include "Osobnik.h"

class Selekcja
{
	
public:

	int* tablicaRodzicow;	// przechowuje indeksy osobnikow ktore beda rodzicami
	int n;					// liczba osobnikow w populacji
	int liczbaRodzicow;

	void inicjalizuj(int rozmiar, int liczbaRodzicow);	// rozmiar czyli liczba osobnikow w populacji
	void ruletka(Osobnik* osobnik, int liczbaRodzicow, Osobnik* rodzic);
	void turniej(Osobnik* osobnik, double ulamkowyRozmiarTurnieju, int liczbaRodzicow, Osobnik* rodzic);
	void elitaryzm(Osobnik* osobnik, double ulamkowyRozmiarElitaryzmu);
	void wypiszRodzicow();
};

