#pragma once
#include "Ro�lina.h"
class Mlecz :
	public Roslina
{
public:
	Mlecz(Swiat & swiat, Punkt polozenie);
	~Mlecz();
	void akcja() final;
	void rozprzesrzen(Punkt nowy) final;
};

