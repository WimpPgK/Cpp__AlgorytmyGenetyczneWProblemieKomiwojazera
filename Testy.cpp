#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Testy.h"
#include "Osobnik.h"
#include "Krzyzowanie.h"
#include "Gen.h"
#include "OperacjeNaPlikach.h"
#include "Mutacje.h"
#include "FunkcjaCelu.h"
#include "Selekcja.h"
#include "Populacja.h"


bool Testy::testuj()
{	
	/*
			Pane testowy. Aby uruchomic test nalezy odkomentowac jedna z ponizszych dzialajacych linii
	*/
	
	//bool gen = testGen();
	//bool krzyzowanie = testKrzyzowanie();					//DZIALA
	//bool mutacje = testMutacje();							//DZIALA
	//bool operacjeNaPlikach = testOperacjeNaPlikach();		//DZIALA
	//bool osobnik = testOsobnik();
	//bool funkcjaCelu = testFunkcjaCelu();					//DZIALA
	//bool selekcja = testSelekcja();						// Turniej sprawdzony, ruletka nie sprawdzona
	//bool populacja = testPopulacja();

	
		testPopulacja(); 



	//bool algorytmLosowy = testAlgorytmLosowy();







	//cout << "*********************************" << endl;
	//cout << "Testowanie programu:" << endl;
	
	//cout << "Klasa Gen:                   " << (gen ? "ok" : "fail") << endl;
	//cout << "Klasa Krzyzowanie:           " << (krzyzowanie ? "ok" : "fail") << endl;
	//cout << "Klasa Mutacje:               " << (mutacje ? "ok" : "fail") << endl;
	//cout << "Klasa OperacjeNaPlikach:     " << (operacjeNaPlikach ? "ok" : "fail") << endl;
	//cout << "Klasa Osobnik:               " << (osobnik ? "ok" : "fail") << endl;

	/*
	if (!gen || !krzyzowanie || !mutacje || !operacjeNaPlikach || !osobnik)
	{
		cout << "Test zakonczyl sie porazka!" << endl;
		return false;
	}
	else
	{
		cout << "Test zakonczyl sie sukcesem!" << endl;
		return true;
	}
	*/
	return false;
}

bool Testy::testGen()
{
	return true;
}


bool Testy::testKrzyzowanie()
{	/*

	int n = 10;
	Osobnik osobnik01;
	Osobnik osobnik02;

	osobnik01.inicjalizujOsobnik1();		// inicjalizacja stalymi wartosciami wpisanymi w kodzie funkcji
	osobnik02.inicjalizujOsobnik2();		// inicjalizacja stalymi wartosciami wpisanymi w kodzie funkcji
	
	cout << "************************************************" << endl;
	cout << "Geny osobnika 1 PRZED mutacja: " << endl;
	osobnik01.wypiszGeny();
	cout << "Geny osobnika 2 PRZED mutacja: " << endl;
	osobnik02.wypiszGeny();

	Krzyzowanie k1;
	k1.PMX(&osobnik01, &osobnik02);

	cout << endl << "************************************************" << endl;
	cout << "Geny osobnika 1 PO mutacji: " << endl;
	osobnik01.wypiszGeny();
	cout << "Geny osobnika 2 PO mutacji: " << endl;
	osobnik02.wypiszGeny();

	*/

	return true;
}



bool Testy::testOperacjeNaPlikach()
{	
	/*
	OperacjeNaPlikach operacje;
	Osobnik o1;
	Gen* g = new Gen[53];

	operacje.odczytajDane("berlin52.tsp", g);

	cout << "Odczytane dane z pliku berlin52.tsp" << endl;
	for (int i = 0; i < 52; i++)
	{
		cout << "ID: " << g[i].ID << "   pozycja_x: " << g[i].pozycja_x << "   pozycja_y: " << g[i].pozycja_y << endl;
	}
	*/
	return true;
}
bool Testy::testOsobnik()
{
	return true;
}

bool Testy::testFunkcjaCelu()
{
	/*
	Osobnik o1;
	FunkcjaCelu f1;


	o1.inicjalizuj(10);	// inicjalizacja losowymi wartosciami
	cout << "Geny osobnika" << endl;


	cout << "Dlugosc trasy wynosi " << f1.obliczDlugoscTrasy(o1) << endl;*/
	return false;
}


bool Testy::testSelekcja()
{	
	/*
	int rozmiarPopulacji = 100;
	int liczbaRodzicow = 2 * rozmiarPopulacji;
	int rozmiarOsobnika = 300;
	Osobnik* populacja = new Osobnik[rozmiarPopulacji];
	
	for (int i = 0; i < rozmiarPopulacji; i++)
	{
		populacja[i].inicjalizuj(rozmiarOsobnika);
	}
	

	Selekcja s1;
	s1.inicjalizuj(rozmiarPopulacji, liczbaRodzicow);
	//s1.ruletka(populacja, liczbaRodzicow);
	s1.turniej(populacja, 0.12, liczbaRodzicow);	
	//s1.wypiszRodzicow();

	*/
	return true;
}

bool Testy::testPopulacja()
{
	Populacja p1;
	int liczbaEpok = 1000;
	int rozmiarPopulacji = 1000;
	double Pm = 0.1;			// prawdopodobienstwo mutacji
	double Px = 0.7;			// prawdopodobienstwo krzyzowania
	int typMutacji = 1;			// 0 - zamiana, 1 - inwersja
	bool elitaryzm = true;


	p1.utworzPopulacje("fl417.tsp", rozmiarPopulacji);
	p1.ocena();						// POPRAWNE
	for (int i = 0; i < liczbaEpok; i++)
	{
		p1.selekcjaPrzezTurniej(0.2);	// POPRAWNE
		//p1.selekcjaPrzezRuletke();	// POPRAWNE
		p1.krzyzowanie(Px);
		//p1.wypiszOsobnikiNowe();
		
		// OBA TYPY MUTACJI POPRAWNE
		p1.nadpiszPoprzedniaPopulacje(elitaryzm);
		p1.mutacja(Pm, typMutacji);

		p1.ocena();

		p1.wypiszNajlepszego();
	}
	p1.wypiszNajlepszego();
	//p1.wypiszPopulacje();
	

	//p1.wypiszPopulacje();
	
	//p1.wypiszRodzicow();
	//p1.wypiszOsobnikiNowe();
	return true;
}







bool Testy::testAlgorytmLosowy()
{
	int liczbaEpok = 100;
	int wielkoscPupulacji = 100;
	double najkrotszaSciezka;


	Populacja p1;

	p1.utworzPopulacje("fl417.tsp", wielkoscPupulacji);
	p1.ocena();
	najkrotszaSciezka = p1.osobnik[0].wartoscFunkcjiCelu;
	for (int i = 0; i < liczbaEpok; i++)
	{	
		for (int j = 0; j < wielkoscPupulacji; j++)
		{
			if (najkrotszaSciezka > p1.osobnik[j].wartoscFunkcjiCelu)
			{
				najkrotszaSciezka = p1.osobnik[j].wartoscFunkcjiCelu;
				cout << "Po losowaniu numer " << i * 100 + j << " najkrotsza sciezka wynosi " << najkrotszaSciezka << endl;
			}
		}
		p1.algorytmLosowy();
		p1.ocena();

	}
	
					

	return true;
}
