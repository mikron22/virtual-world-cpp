#pragma once
#include "Zwierz�.h"
class Lis :
	public Zwierze
{
public:
	Lis(Swiat &swiat, Punkt polozenie);
	~Lis();
	void kolizja(int x, int y) final;
	void rozmnazanie() final;
};

