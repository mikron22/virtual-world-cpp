#pragma once
#include "Zwierz�.h"
class ��w :
	public Zwierze
{
public:
	��w(Swiat &swiat, Punkt polozenie);
	~��w();
	bool odbicie() final;
	void rozmnazanie() final;
	void akcja() final;
};

