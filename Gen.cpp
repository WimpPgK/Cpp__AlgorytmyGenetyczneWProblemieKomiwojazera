#include "Gen.h"

Gen::Gen()
{
	ID = -1;
	pozycja_x = -1;
	pozycja_y = -1;
}
void Gen::ustawWartosci(int a, int x, int y)
{
	ID = a;
	pozycja_x = x;
	pozycja_y = y;
}
