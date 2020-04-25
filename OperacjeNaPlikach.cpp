#include "OperacjeNaPlikach.h"
#include <iostream>
#include <fstream>
#include <string>

void OperacjeNaPlikach::odczytajDane(string nazwaPliku, Gen* tablicaGenow)
{	
	fstream dane;
	string separator = " ";
	string kodKoncaPliku = "EOF";

	dane.open(nazwaPliku.c_str(), ios::in);   // zamieniamy string dataFile na c_string czyli char*

	if (dane.good() == false)	// jesli nie uda sie otworzyc pliku
	{
		cout << "Nie mozna otworzyc pliku" << endl;
	}
	else
	{
		string linia;
		string wartosc;
		int licznik = 0;

		for (int i = 0; i < 4; i++)
		{
			getline(dane, linia);
			wartosc = linia.substr(linia.find(" "));	// pobieramy z lini wszystko co jest po separatorze
		}


		int n = stoi(wartosc);	// rzutujemy pobrana wielkosc zbioru miast do inta

		// pomijamy 2 kolejne linie
		getline(dane, linia);
		getline(dane, linia);


		int iterator = 0;
		while (!dane.eof())     // dopoki plik sie nie skonczy
		{
			getline(dane, linia);
			if (linia == kodKoncaPliku)	// jesli napotkamy znak konca pliku to przestajemy pobierac dane
			{
				break;
			}


			string pom = linia;

			tablicaGenow[iterator].ID = stoi(pom.substr(0, pom.find(" ")));
			pom = pom.substr(pom.find(" ") + 1);	// przesuwamy sie za separator i obcinamy pierwsza czesc napisy
			tablicaGenow[iterator].pozycja_x = stod(pom.substr(0, pom.find(" ")));
			pom = pom.substr(pom.find(" ") + 1);
			tablicaGenow[iterator].pozycja_y = stod(pom.substr(0, pom.find(" ")));

			//cout << "Id = " << tablicaGenow[iterator].ID << "      pozycja_x = " << tablicaGenow[iterator].pozycja_x << "        pozycja_y = " << tablicaGenow[iterator].pozycja_y << endl;
			iterator++;
		}

	}
	dane.close();
}
int OperacjeNaPlikach::sprawdzLiczbeGenow(string nazwaPliku)
{

	fstream dane;
	string separator = " ";
	string kodKoncaPliku = "EOF";

	dane.open(nazwaPliku.c_str(), ios::in);   // zamieniamy string dataFile na c_string czyli char*

	if (dane.good() == false)	// jesli nie uda sie otworzyc pliku
	{
		cout << "Nie mozna otworzyc pliku" << endl;
		return -1;
	}
	else
	{
		string linia;
		string wartosc;
		int licznik = 0;

		for (int i = 0; i < 4; i++)
		{
			getline(dane, linia);
			wartosc = linia.substr(linia.find(" "));	// pobieramy z lini wszystko co jest po separatorze
		}
		dane.close();
		return stoi(wartosc); // rzutujemy pobrana wielkosc zbioru miast do inta
	}
	
}
void OperacjeNaPlikach::zapiszDoTXT()
{

}
void OperacjeNaPlikach::zapiszDoXML()
{

}