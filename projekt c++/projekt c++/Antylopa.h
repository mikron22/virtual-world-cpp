#pragma once
#include "Zwierzê.h"
class Antylopa :
	public Zwierze
{
public:
	Antylopa(Swiat &swiat, Punkt polozenie);
	void akcja() final;
	void kolizja(Organizm * o) final;
	~Antylopa();
	void rozmnazanie() final;
};

