#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Krzyzowanie.h"
#include "Gen.h"

using namespace std;

void Krzyzowanie::OX(Osobnik* osobnik01, Osobnik* osobnik02)
{
	int n = osobnik01->rozmiar;
	//cout << "Rozmiar osobnika z klasy krzyzowanie to: " << n << endl;
	int pom1 = rand() % n;
	int pom2 = rand() % n;

}

void Krzyzowanie::PMX(Osobnik* osobnik01, Osobnik* osobnik02)
{	
	int n = osobnik01->rozmiar;

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

	
	int rozmiarWycinka = pozycja02 - pozycja01 + 1;
	//cout << "rozmair wycinka " << rozmiarWycinka << endl;
	//cout << "Poczatek fragmentu: " << pozycja01 << "     Koniec fragmentu " << pozycja02 << endl;


	/*
		Tworzymy kopie fragmentow ktore bedziemy ze soba zamieniac
	*/
	Gen* pomOsobnik01 = new Gen[rozmiarWycinka];
	Gen* pomOsobnik02 = new Gen[rozmiarWycinka];
	for (int i = 0; i < rozmiarWycinka; i++)
	{
		pomOsobnik01[i].ID = osobnik01->tablicaGenow[pozycja01 + i].ID;
		pomOsobnik01[i].pozycja_x = osobnik01->tablicaGenow[pozycja01 + i].pozycja_x;
		pomOsobnik01[i].pozycja_y = osobnik01->tablicaGenow[pozycja01 + i].pozycja_y;
		//cout << "PomOsobnik " << i << "  = " << pomOsobnik01[i].ID << endl;
		pomOsobnik02[i].ID = osobnik02->tablicaGenow[pozycja01 + i].ID;
		pomOsobnik02[i].pozycja_x = osobnik02->tablicaGenow[pozycja01 + i].pozycja_x;
		pomOsobnik02[i].pozycja_y = osobnik02->tablicaGenow[pozycja01 + i].pozycja_y;
		//cout << "PomOsobnik " << i << "  = " << pomOsobnik02[i].ID << endl;
	}


	/*
		chcemy sprawdzic ile bedzie regol permutacji, czyli ile liczb we fragmecie nie powtarza sie
	*/
	int rozmiarTablicyPermutacji = 0;
	for (int i = 0; i < rozmiarWycinka; i++)
	{
		for (int j = 0; j < rozmiarWycinka; j++)
		{
			if (pomOsobnik01[i].ID == pomOsobnik02[j].ID)			
			{
				rozmiarTablicyPermutacji++;
				break;
			}
		}
	}
	rozmiarTablicyPermutacji = rozmiarWycinka - rozmiarTablicyPermutacji;

	//cout << "Liczba permutacji: " << rozmiarTablicyPermutacji << endl;
	/*
		Alokujemy pamiec i tworzymy tablice permutacji. Tablica permutacji jest macierza o wymiarze m x 2
		poniewaz kazda regola permutacji sklada sie z 2 liczb. Np. 3<->5 oznacza ze 3 zamieniane jest na 5 a 5 na 3.
	*/
	int** tablicaPermutacji = new int*[rozmiarTablicyPermutacji];
	for (int i = 0; i < rozmiarTablicyPermutacji; i++)
	{
		tablicaPermutacji[i] = new int[2];
	}


	int flaga = 0;
	int licznik = 0;

	for (int i = 0; i < rozmiarWycinka; i++)
	{
		for (int j = 0; j < rozmiarWycinka; j++)
		{
			if (pomOsobnik01[i].ID == pomOsobnik02[j].ID)	// jesli liczby sie powtarzaja to nie jest to regola permutacji
			{
				flaga = 1;
				break;
			}
		}
		if (flaga == 0)
		{
			tablicaPermutacji[licznik][0] = pomOsobnik01[i].ID;
	
			int pom2 = 0;
			int flaga2 = 0;
			int aaa = pomOsobnik02[i].ID;
			int bbb = 0;

			while (flaga2 == 0)
			{
				for (int k = 0; k < rozmiarWycinka; k++)
				{
					flaga2 = 1;
					if (aaa == pomOsobnik01[k].ID)
					{
						flaga2 = 0;
						aaa = pomOsobnik02[k].ID;
						break;
					}
				}
				if (flaga2 == 1)
				{
					break;
				}
				/*
				for (int k = 0; k < rozmiarWycinka; k++)
				{
					flaga2 = 1;
					if (aaa == pomOsobnik01[k].ID)
					{
						flaga2 = 0;
						aaa = pomOsobnik01[k].ID;
					}
				}
				*/
				
			}
			tablicaPermutacji[licznik][1] = aaa;
			licznik++;
		}
		flaga = 0;
	}
	/*
	cout << endl << "************ Tablica permutacji ******************" << endl;
	cout << "Rozmiar tablicy permutacji:  " << rozmiarTablicyPermutacji << endl;
	for (int i = 0; i < rozmiarTablicyPermutacji; i++)
	{
		cout <<"	" <<  tablicaPermutacji[i][0] << "<->" << tablicaPermutacji[i][1] << endl;
	}
	cout << "************************************************" << endl << endl;
	*/
	
	/* 
		Gdy mamy juz tablice permutacji to mozemy przystapic do zamiany calych wybranych sekcji
	*/

	for (int i = 0; i < rozmiarWycinka; i++)
	{
		osobnik01->tablicaGenow[pozycja01 + i].ID = pomOsobnik02[i].ID;
		osobnik01->tablicaGenow[pozycja01 + i].pozycja_x = pomOsobnik02[i].pozycja_x;
		osobnik01->tablicaGenow[pozycja01 + i].pozycja_y = pomOsobnik02[i].pozycja_y;

		osobnik02->tablicaGenow[pozycja01 + i].ID = pomOsobnik01[i].ID;
		osobnik02->tablicaGenow[pozycja01 + i].pozycja_x = pomOsobnik01[i].pozycja_x;
		osobnik02->tablicaGenow[pozycja01 + i].pozycja_y = pomOsobnik01[i].pozycja_y;

		//cout << osobnik01->tablicaGenow[pozycja01+i].ID << endl;
	}
	
	/*
		Po zamianei sektorow chcemy wypisac osobniki
	*/
	/*for (int i = 0; i < n; i++)
	{
		cout << "Osobnik [" << i << "]: " << osobnik02->tablicaGenow[i].ID << endl;
	
	}*/


	/*
		tworzymy kopie genow
	*/
	
	Gen* kopiaOsobnik01 = new Gen[n];
	Gen* kopiaOsobnik02 = new Gen[n];

	for (int i = 0; i < n; i++)
	{
		kopiaOsobnik01[i].ID = osobnik01->tablicaGenow[i].ID;
		kopiaOsobnik01[i].pozycja_x = osobnik01->tablicaGenow[i].pozycja_x;
		kopiaOsobnik01[i].pozycja_y = osobnik01->tablicaGenow[i].pozycja_y;
		
		kopiaOsobnik02[i].ID = osobnik02->tablicaGenow[i].ID;
		kopiaOsobnik02[i].pozycja_x = osobnik02->tablicaGenow[i].pozycja_x;
		kopiaOsobnik02[i].pozycja_y = osobnik02->tablicaGenow[i].pozycja_y;
	}


	
	/*
		dokonujemy zamian zgodnie z tablica permutacji w pozostałych fragmentach dzialajac na kopiach genow
	*/
	Gen pom;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < rozmiarTablicyPermutacji; j++)
		{
			
			if (i >= pozycja01 && i <= pozycja02)	// dla zamienionego fragmentu nie robimy nic
			{
				//cout << "Pomijam fragment dla i = "<< i << endl;
				continue;	
				
			}
			//cout << tablicaPermutacji[j][0] << endl;
			if (osobnik01->tablicaGenow[i].ID == tablicaPermutacji[j][0])
			{
				kopiaOsobnik01[i].ID = tablicaPermutacji[j][1];
				for (int k = 0; k < n; k++)
				{
					if (osobnik02->tablicaGenow[k].ID == tablicaPermutacji[j][1])
					{
						kopiaOsobnik01[i].pozycja_x = osobnik02->tablicaGenow[k].pozycja_x;
						kopiaOsobnik01[i].pozycja_y = osobnik02->tablicaGenow[k].pozycja_y;
					}
				}
			}
			if (osobnik01->tablicaGenow[i].ID == tablicaPermutacji[j][1])
			{
				kopiaOsobnik01[i].ID = tablicaPermutacji[j][0];
				for (int k = 0; k < n; k++)
				{
					if (osobnik02->tablicaGenow[k].ID == tablicaPermutacji[j][0])
					{
						kopiaOsobnik01[i].pozycja_x = osobnik02->tablicaGenow[k].pozycja_x;
						kopiaOsobnik01[i].pozycja_y = osobnik02->tablicaGenow[k].pozycja_y;
					}
				}
			}
			
			
			
			if (osobnik02->tablicaGenow[i].ID == tablicaPermutacji[j][0])
			{
				kopiaOsobnik02[i].ID = tablicaPermutacji[j][1];
				for (int k = 0; k < n; k++)
				{
					if (osobnik01->tablicaGenow[k].ID == tablicaPermutacji[j][1])
					{
						kopiaOsobnik02[i].pozycja_x = osobnik01->tablicaGenow[k].pozycja_x;
						kopiaOsobnik02[i].pozycja_y = osobnik01->tablicaGenow[k].pozycja_y;
					}
				}
			}
			if (osobnik02->tablicaGenow[i].ID == tablicaPermutacji[j][1])
			{
				kopiaOsobnik02[i].ID = tablicaPermutacji[j][0];
				for (int k = 0; k < n; k++)
				{
					if (osobnik01->tablicaGenow[k].ID == tablicaPermutacji[j][0])
					{
						kopiaOsobnik02[i].pozycja_x = osobnik01->tablicaGenow[k].pozycja_x;
						kopiaOsobnik02[i].pozycja_y = osobnik01->tablicaGenow[k].pozycja_y;
					}
				}

			}
	
		}
	}
	
	/*
		Po dokonaniu operacji na kopiach genow nadpisujemy stare tablice genow wartosciami zmodyfikowanymi
	*/

	for (int i = 0; i < n; i++)
	{
		osobnik01->tablicaGenow[i].ID = kopiaOsobnik01[i].ID;
		osobnik01->tablicaGenow[i].pozycja_x = kopiaOsobnik01[i].pozycja_x;
		osobnik01->tablicaGenow[i].pozycja_y = kopiaOsobnik01[i].pozycja_y;

		osobnik02->tablicaGenow[i].ID = kopiaOsobnik02[i].ID;
		osobnik02->tablicaGenow[i].pozycja_x = kopiaOsobnik02[i].pozycja_x;
		osobnik02->tablicaGenow[i].pozycja_y = kopiaOsobnik02[i].pozycja_y;
	}



	/*
		Zwalnianie pamieci
	*/
	delete[] pomOsobnik01;
	delete[] pomOsobnik02;
	delete[] kopiaOsobnik01;
	delete[] kopiaOsobnik02;

	
}

void Krzyzowanie::CX(Osobnik* osobnik01, Osobnik* osobnik02)
{
}
