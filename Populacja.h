#pragma once
#include "Osobnik.h"
#include "OperacjeNaPlikach.h"

using namespace std;


class Populacja
{

public: 
	Osobnik* osobnik;
	Osobnik* osobnikNowy;
	Osobnik* rodzic;
	int liczbaOsobnikow;
	int liczbaGenow;
	
	// odczytuje i tworzy populacje oraz alokuje pamiec dla nowych pokolen
	void utworzPopulacje(string nazwaPliku, int liczbaOsobnikow);	
	
	void ocena();
	void selekcjaPrzezRuletke();
	void selekcjaPrzezTurniej(double ulamkowyRozmiarTurnieju);
	void krzyzowanie(double Px);
	
	//void mutacja(double Pm,int typMutacji);

	void nadpiszPoprzedniaPopulacje(bool elitaryzm);
	void mutacja(double Pm, int typMutacji);
	void algorytmLosowy();
	//void algorytmZachlanny();

	void wypiszNajlepszego();
	void wypiszPopulacje();
	void wypiszRodzicow();
	void wypiszOsobnikiNowe();
};

