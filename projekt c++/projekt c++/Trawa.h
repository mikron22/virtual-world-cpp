#pragma once
#include "Ro�lina.h"
class Trawa :
	public Roslina
{
public:
	Trawa(Swiat & swiat, Punkt polozenie);
	~Trawa();
	void rozprzesrzen(Punkt nowy) final;
};

