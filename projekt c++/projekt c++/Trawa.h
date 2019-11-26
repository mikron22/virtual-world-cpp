#pragma once
#include "Roœlina.h"
class Trawa :
	public Roslina
{
public:
	Trawa(Swiat & swiat, Punkt polozenie);
	~Trawa();
	void rozprzesrzen(Punkt nowy) final;
};

