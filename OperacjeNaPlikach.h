#pragma once
#include <string>
#include <fstream>
#include "Gen.h"

using namespace std;

class OperacjeNaPlikach
{
public:
	void odczytajDane(string nazwaPliku, Gen* tablicaGenow);
	int sprawdzLiczbeGenow(string nazwaPliku);
	void zapiszDoTXT();
	void zapiszDoXML();
};

