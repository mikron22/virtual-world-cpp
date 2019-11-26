#pragma once
class Swiat;

#include"Stale.h"
#include"conio2.h"
#include"Swiat.h"


class Organizm
{
protected:
	int si�a;
	int inicjatywa;
	int wiek;
	char znak;
	Punkt polozenie;
	Swiat& swiat;
public:
	Organizm();
	Organizm(Swiat &swiat);
	Organizm(Organizm & o);
	Organizm(Organizm* o);
	int getSi�a() const;
	int getInicjatywa() const;
	int getWiek() const;
	char getZnak() const;
	Punkt getPolozenie() const;
	void setSi�a(int si�a);
	void setWiek(int wiek);
	void setPolozenie(Punkt p);
	void setSwiat(Swiat& swiat);
	virtual void akcja() = 0;
	virtual void kolizja(int x, int y) = 0;
	virtual void kolizja(Organizm* atakujacy);
	virtual bool odbicie() { return false; }
	Organizm* operator=(Organizm* o);
	void rysowanie();

};

