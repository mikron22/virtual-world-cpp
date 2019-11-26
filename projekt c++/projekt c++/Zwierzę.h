#pragma once
#include "Organizm.h"
class Zwierze :
	public Organizm
{
public:
	Zwierze();
	Zwierze(Swiat &swiat);
	void akcja() override;
	virtual void rozmnazanie() = 0;
	void kolizja(int x, int y) override;
};

