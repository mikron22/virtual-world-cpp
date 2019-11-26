#pragma once
#include "Zwierzê.h"
class Czlowiek :
	public Zwierze
{
protected:
	int moc; //0  mozna uruchomic, 10 - 6 uruchomiona, 5 - 1 odnawianie
public:
	Czlowiek(Swiat &swiat, Punkt polozenie);
	void akcja() final;
	void kolizja(Organizm * o) final;
	void rozmnazanie() { return; };
	~Czlowiek();
};

