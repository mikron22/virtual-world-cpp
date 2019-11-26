#pragma once
#include "Roœlina.h"
#include "Zwierzê.h"
class Barszcz_Sosnowskiego :
	public Roslina
{
public:
	Barszcz_Sosnowskiego(Swiat & swiat, Punkt polozenie);
	~Barszcz_Sosnowskiego();
	void rozprzesrzen(Punkt nowy) final;
	void akcja() final;
	void kolizja(Organizm * atakujacy) final;
};

