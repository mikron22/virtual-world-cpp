#pragma once
#include "Roœlina.h"
class Wilcze_Jagody :
	public Roslina
{
public:
	Wilcze_Jagody(Swiat & swiat, Punkt polozenie);
	~Wilcze_Jagody();
	void rozprzesrzen(Punkt nowy) final;
	void kolizja(Organizm * atakujacy) final;
};