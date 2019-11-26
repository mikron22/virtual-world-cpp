#pragma once
#include "Roœlina.h"
class Guarana :
	public Roslina
{
public:
	Guarana(Swiat & swiat, Punkt polozenie);
	~Guarana();
	void rozprzesrzen(Punkt nowy) final;
	void kolizja(Organizm * atakujacy) final;
};

