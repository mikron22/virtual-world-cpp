#pragma once
#include "Zwierzê.h"
class ¯ó³w :
	public Zwierze
{
public:
	¯ó³w(Swiat &swiat, Punkt polozenie);
	~¯ó³w();
	bool odbicie() final;
	void rozmnazanie() final;
	void akcja() final;
};

