#include "Selekcja.h"
#include "FunkcjaCelu.h"

void Selekcja::inicjalizuj(int rozmiar, int liczbaRodzicow)
{
	n = rozmiar;
	Selekcja::liczbaRodzicow = liczbaRodzicow;
	tablicaRodzicow = new int[liczbaRodzicow];

	for (int i = 0; i < liczbaRodzicow; i++)
	{
		tablicaRodzicow[i] = -1;
	}
}

void Selekcja::ruletka(Osobnik* osobnik, int liczbaRodzicow, Osobnik* rodzic)
{
	FunkcjaCelu f1;
	for (int i = 0; i < n; i++)
	{
		osobnik[i].wartoscFunkcjiCelu = f1.obliczDlugoscTrasy(osobnik[i]);
		//cout << "Wartosc funkcji CELU osobnika [" << i << "]:  "  << osobnik[i].wartoscFunkcjiCelu << endl;
	}

	/*

		Obliczamy funkcje przystosowania. Im trasa jest krótsza tym wartosc funkcji przystosowania ma byc większa
		Wyznaczamy maximum funkcji celu i odejmujemy od maximum funkcji celu funkcje celu osobnika.

	*/
	int* funkcjaPrzystosowania = new int[n];
	int maximum = -1;
	for (int i = 0; i < n; i++)		// znajdujemy maximum funkcji celu
	{
		if (osobnik[i].wartoscFunkcjiCelu > maximum)
		{
			maximum = osobnik[i].wartoscFunkcjiCelu;
		}
	}
	//cout << "Maximum = " << maximum << endl;


	/*
		Obliczamy funkcje przystosowania i jej sume dla wszystkich osobnikow.
	*/
	double sumaFunkcjiPrzystosowania = 0;
	for (int i = 0; i < n; i++)		// znajdujemy maximum funkcji celu
	{
		funkcjaPrzystosowania[i] = maximum - osobnik[i].wartoscFunkcjiCelu;
		sumaFunkcjiPrzystosowania += funkcjaPrzystosowania[i];
		//cout << "Wartosc funkcji PRZYSTOSOWANIA osobnika [" << i << "]:  " << funkcjaPrzystosowania[i] << endl;
	}

	/*
		Im wieksza wartosc funkcji przystosowania tym powinna byc wieksza szansa ze osobnik zostanie rodzicem.
		Aby obliczyc prawdopodobienstwo pzostania rodzicem liczymy:  iloraz funkcji przystosowania osobnika
		i sumy funkcji przystosowania wszystkich osobnikow
	*/

	double* prawdopodobienstwo = new double[n];
	for (int i = 0; i < n; i++)		// znajdujemy maximum funkcji celu
	{
		prawdopodobienstwo[i] = funkcjaPrzystosowania[i] / double(sumaFunkcjiPrzystosowania);
		//cout << "Prawdopodobienstwo ze osobnik [" << i << "] zostanie rodzicem wynosi " << prawdopodobienstwo[i] << endl;
	}

	/*
		losujemy liczbe z zakresu (0;1) i sprawdzamy na przedziale ktorego z osobnikow znajduje sie ta liczba
		robimy to tak dlugo az wybierzemy wzsystkich rodzicow. 
	*/
	for (int i = 0; i < liczbaRodzicow; i++)
	{	
		double pom = 0;
		double liczbaLosowa = double(rand()) / RAND_MAX; // liczba z zakresu (0;1)
		//cout << "Liczba ktora poszukiwana jest w zbiorze ma wartosc " << liczbaLosowa << endl;
		int itr = 0;
		while (pom < liczbaLosowa)
		{

			pom += prawdopodobienstwo[itr];
			itr++;
		}
		tablicaRodzicow[i] = itr - 1;
		//cout << "Osobnik [" << tablicaRodzicow[i] << "] zostal rodzicem" << endl;
	}

	/*
	zapisujemy do tablicy rodzic dane rodzicow
	*/
	for (int i = 0; i < liczbaRodzicow; i++)
	{
		for (int j = 0; j < osobnik[0].rozmiar; j++)
		{
			rodzic[i].tablicaGenow[j].ID = osobnik[tablicaRodzicow[i]].tablicaGenow[j].ID;
			rodzic[i].tablicaGenow[j].pozycja_x = osobnik[tablicaRodzicow[i]].tablicaGenow[j].pozycja_x;
			rodzic[i].tablicaGenow[j].pozycja_y = osobnik[tablicaRodzicow[i]].tablicaGenow[j].pozycja_y;
		}

	}
}

void Selekcja::turniej(Osobnik* osobnik, double ulamkowyRozmiarTurnieju, int liczbaRodzicow, Osobnik* rodzic)
{
	FunkcjaCelu f1;
	int rozmiarTurnieju = n * ulamkowyRozmiarTurnieju;
	//cout << "Rozmiar turnieju " << rozmiarTurnieju << endl;
	/*
		obliczamy dlugosc trasy dla kazdego osobnika i zapisujemy w jego w zmiennej osobnika
	*/
	for (int i = 0; i < n; i++)
	{
		osobnik[i].wartoscFunkcjiCelu = f1.obliczDlugoscTrasy(osobnik[i]);
		//cout << "Wartosc funkcji CELU osobnika [" << i << "]:  " << osobnik[i].wartoscFunkcjiCelu << endl;
	}

	/*
		Losujemy odpowiednia liczbe osobnikow i wybieramy tego z najlepiej przystosowanego,
		czyli tego dla ktorego dlugosc trasy jest najmniejsza
	*/

	for (int k = 0; k < liczbaRodzicow; k++)
	{
		int losowyOsobnik = rand() % n;
		int idRodzica = losowyOsobnik;
		double min = osobnik[losowyOsobnik].wartoscFunkcjiCelu;
		for (int i = 1; i < rozmiarTurnieju; i++)
		{
			losowyOsobnik = rand() % n;
			if (osobnik[losowyOsobnik].wartoscFunkcjiCelu < min)
			{
				idRodzica = losowyOsobnik;
				min = osobnik[losowyOsobnik].wartoscFunkcjiCelu;
			}
		}
		tablicaRodzicow[k] = idRodzica;
		//cout << "Rodzicem zostal osobnik [" << idRodzica << "]" << endl;

	}
	
	/*
		zapisujemy do tablicy rodzic dane rodzicow
	*/
	for (int i = 0; i < liczbaRodzicow; i++)
	{
		for (int j = 0; j < osobnik[0].rozmiar; j++)
		{
			rodzic[i].tablicaGenow[j].ID = osobnik[tablicaRodzicow[i]].tablicaGenow[j].ID;
			rodzic[i].tablicaGenow[j].pozycja_x = osobnik[tablicaRodzicow[i]].tablicaGenow[j].pozycja_x;
			rodzic[i].tablicaGenow[j].pozycja_y = osobnik[tablicaRodzicow[i]].tablicaGenow[j].pozycja_y;
		}
		
	}

	//cout << rozmiarTurnieju;
}

void Selekcja::wypiszRodzicow()
{	

	cout << "**********************  rodzice  ***********************" << endl;
	for (int i = 0; i < liczbaRodzicow; i++)
	{
		cout << "[" << i << "]:  " << tablicaRodzicow[i] << endl;
	}
}
