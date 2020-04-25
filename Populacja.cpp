#include "Populacja.h"
#include "FunkcjaCelu.h"
#include "Selekcja.h"
#include "Mutacje.h"
#include "Krzyzowanie.h"


void Populacja::utworzPopulacje(string nazwaPliku, int liczbaOsobnikow)
{
	Populacja::liczbaOsobnikow = liczbaOsobnikow;
	OperacjeNaPlikach operacje;
	
	
	/*
		Odczytujemy z pliku caly zbior danych
	*/
	liczbaGenow = operacje.sprawdzLiczbeGenow(nazwaPliku);
	Gen* tablicaGenow = new Gen[liczbaGenow];
	//cout << "liczba genow: " << liczbaGenow <<  endl;
	operacje.odczytajDane(nazwaPliku, tablicaGenow);
	
	osobnik = new Osobnik[liczbaOsobnikow];
	osobnikNowy = new Osobnik[liczbaOsobnikow];

	for (int i = 0; i < liczbaOsobnikow; i++)
	{
		osobnik[i].inicjalizuj(tablicaGenow, liczbaGenow);
		osobnikNowy[i].inicjalizujZerami(liczbaGenow);
	}


	int liczbaRodzicow = liczbaOsobnikow * 2;
	rodzic = new Osobnik[liczbaRodzicow];
	for (int i = 0; i < liczbaRodzicow; i++)
	{
		rodzic[i].inicjalizujZerami(liczbaGenow);
	}
	
	
	
}

void Populacja::ocena()
{
	FunkcjaCelu f1;
	for (int i = 0; i < liczbaOsobnikow; i++)
	{
		osobnik[i].wartoscFunkcjiCelu = f1.obliczDlugoscTrasy(osobnik[i]);
	}
}


void Populacja::wypiszNajlepszego()
{
	double min = osobnik[0].wartoscFunkcjiCelu;
	int indeksNajlepszego = 0;
	for (int i = 0; i < liczbaOsobnikow; i++)
	{
		if (osobnik[i].wartoscFunkcjiCelu < min)
		{
			min = osobnik[i].wartoscFunkcjiCelu;
			indeksNajlepszego = i;
		}
	}
	//cout << "NAJLEPSZY osobnik ma numer " << indeksNajlepszego << ". Dlugosc trasy wynosi " << osobnik[indeksNajlepszego].wartoscFunkcjiCelu << endl << endl;
	cout << osobnik[indeksNajlepszego].wartoscFunkcjiCelu << endl;
}

void Populacja::wypiszPopulacje()
{
	for (int i = 0; i < liczbaOsobnikow; i++)
	{
		cout << "*****************************************************" << endl;
		cout << "Osobnik numer " << i << ". Dlugosc trasy wynosi " << osobnik[i].wartoscFunkcjiCelu << endl << endl;
		osobnik[i].wypiszGeny();
	}
}

void Populacja::wypiszRodzicow()
{
	for (int i = 0; i < liczbaOsobnikow*2; i++)
	{
		cout << "*****************************************************" << endl;
		cout << "Rodzic numer " << i << ". Dlugosc trasy wynosi " << rodzic[i].wartoscFunkcjiCelu << endl << endl;
		rodzic[i].wypiszGeny();
	}
}

void Populacja::wypiszOsobnikiNowe()
{
	for (int i = 0; i < liczbaOsobnikow; i++)
	{
		cout << "*****************************************************" << endl;
		cout << "OsobnikNowy numer " << i << ". Dlugosc trasy wynosi " << osobnikNowy[i].wartoscFunkcjiCelu << endl << endl;
		osobnikNowy[i].wypiszGeny();
	}
}


void Populacja::selekcjaPrzezTurniej(double ulamkowyRozmiarTurnieju)
{
	Selekcja s1;
	int liczbaRodzicow = liczbaOsobnikow * 2;
	s1.inicjalizuj(liczbaOsobnikow, liczbaRodzicow);	// liczba osobnikow w populacji
	s1.turniej(osobnik, ulamkowyRozmiarTurnieju, liczbaRodzicow, rodzic);
	//s1.wypiszRodzicow();
}

void Populacja::krzyzowanie(double Px)
{
	Krzyzowanie k1;
	int j = 0;
	int i = 0;
	double liczba;

	for (i,j; i < liczbaOsobnikow*2; i+=2, j++)
	{
		liczba = double(rand()) / RAND_MAX;
		if (liczba < Px)
		{
			k1.PMX(&rodzic[i], &rodzic[i + 1]);
		}
		for (int k = 0; k < liczbaGenow; k++)
		{
			osobnikNowy[j].tablicaGenow[k].ID = rodzic[i].tablicaGenow[k].ID;
			osobnikNowy[j].tablicaGenow[k].pozycja_x = rodzic[i].tablicaGenow[k].pozycja_x;
			osobnikNowy[j].tablicaGenow[k].pozycja_y = rodzic[i].tablicaGenow[k].pozycja_y;
		}
			osobnikNowy[j].wartoscFunkcjiCelu = rodzic[i].wartoscFunkcjiCelu;
	}
		
}




void Populacja::selekcjaPrzezRuletke()
{
	Selekcja s1;
	int liczbaRodzicow = liczbaOsobnikow * 2;


	s1.inicjalizuj(liczbaOsobnikow, liczbaRodzicow);	// liczba osobnikow w populacji
	s1.ruletka(osobnik, liczbaRodzicow, rodzic);
	
	//s1.wypiszRodzicow();
}


void Populacja::mutacja(double Pm, int typMutacji)
{
	Mutacje m1;
	double liczba = 0;
	for (int i = 0; i < liczbaOsobnikow; i++)
	{
		liczba = double(rand()) / RAND_MAX;
		if (liczba < Pm)
		{
			if (typMutacji == 0)
			{
				m1.zamiana(osobnik [i].tablicaGenow, liczbaGenow);
			}
			else if(typMutacji == 1)
			{
				m1.inwersja(osobnik[i].tablicaGenow, liczbaGenow);
			}
		}

	}
}

void Populacja::nadpiszPoprzedniaPopulacje(bool elitaryzm)
{
	double min = osobnik[0].wartoscFunkcjiCelu;
	int indeksNajlepszego = 0;
	if (elitaryzm == true)
	{
		for (int i = 0; i < liczbaOsobnikow; i++)
		{
			if (min > osobnik[i].wartoscFunkcjiCelu)
			{
				min = osobnik[i].wartoscFunkcjiCelu;
				indeksNajlepszego = i;
			}
		}
		//cout << "ELITARYZM " << endl;
	}

	for (int i = 0; i < liczbaOsobnikow; i++)
	{
		if (i == indeksNajlepszego)
		{
			continue;
		}
		for (int j = 0; j < liczbaGenow; j++)
		{
			
			osobnik[i].tablicaGenow[j].ID = osobnikNowy[i].tablicaGenow[j].ID;
			osobnik[i].tablicaGenow[j].pozycja_x = osobnikNowy[i].tablicaGenow[j].pozycja_x;
			osobnik[i].tablicaGenow[j].pozycja_y = osobnikNowy[i].tablicaGenow[j].pozycja_y;
		}
		osobnik[i].wartoscFunkcjiCelu = osobnikNowy[i].wartoscFunkcjiCelu;
	}
}

void Populacja::algorytmLosowy()
{
	/*
		mieszamy losowo kazdego osobnika i sprawdzamy jaka wartosc osiagnie
	*/
	Mutacje m1;

	for (int i = 0; i < liczbaOsobnikow; i++)
	{
		for (int j = 0; j < liczbaGenow; j++)
		{
			m1.zamiana(osobnik[i].tablicaGenow, liczbaGenow);
		}
	}


}
