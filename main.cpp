#include <iostream>
#include <cstdlib>
#include <ctime>


#include "Testy.h"

using namespace std;

int main()
{
	srand(time(NULL));
	
	Testy t1;
	t1.testuj();
	

	return 0;
}