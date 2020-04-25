#include "Gen.h"

#pragma once
class Mutacje
{
public:
	void zamiana(Gen* tablicaGenow, int n);		// wymienia ze sobą 2 losowe pozycje
	void inwersja(Gen* tablicaGenow, int n);	// losuje 2 punkty i odwraca kolejnosc genow miedzy tymi punktami
};

