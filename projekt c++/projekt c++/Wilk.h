#pragma once
#include "Zwierz�.h"
class Wilk :
	public Zwierze
{
public:
	Wilk(Swiat &swiat, Punkt polozenie);
	void rozmnazanie() final;
	~Wilk();
};

