#pragma once
#include "Zwierz�.h"
class Owca :
	public Zwierze
{
public:
	Owca(Swiat &swiat, Punkt polozenie);
	void rozmnazanie() final;
	~Owca();
};

