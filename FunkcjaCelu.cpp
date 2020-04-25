#include "FunkcjaCelu.h"
#include <math.h>


double FunkcjaCelu::obliczDlugoscTrasy(Osobnik osobnik)
{
	int n = osobnik.rozmiar;
	double dlugoscTrasy = 0;

	int ii;
	double Vx;
	double Vy;
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			ii = 0;
		}
		else
		{
			ii = i+1;
		}
		// wspolrzedne wektora to wspolrzednaKonca-wspolrzednaPoczatku
		Vx = osobnik.tablicaGenow[ii].pozycja_x - osobnik.tablicaGenow[i].pozycja_x;
		Vy = osobnik.tablicaGenow[ii].pozycja_y - osobnik.tablicaGenow[i].pozycja_y;
		dlugoscTrasy += sqrt(Vx * Vx + Vy * Vy);	// z Pitagorasa
	}
	return dlugoscTrasy;
}
