#pragma once
#include "Organizm.h"
#include <time.h>
class Roslina :
	public Organizm
{
public:
	Roslina(Swiat & s);
	void akcja() override;
	void kolizja(int x, int y) final;
	virtual void rozprzesrzen(Punkt nowy) = 0;
};

