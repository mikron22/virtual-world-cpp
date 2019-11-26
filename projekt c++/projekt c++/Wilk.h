#pragma once
#include "Zwierzê.h"
class Wilk :
	public Zwierze
{
public:
	Wilk(Swiat &swiat, Punkt polozenie);
	void rozmnazanie() final;
	~Wilk();
};

