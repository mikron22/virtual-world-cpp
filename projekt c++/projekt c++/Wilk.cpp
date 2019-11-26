#include "stdafx.h"
#include "Wilk.h"




Wilk::Wilk(Swiat &swiat, Punkt polozenie) : Zwierze(swiat)
{
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si³a = 9;
	this->inicjatywa = 5;
	this->znak = 'w';
}

void Wilk::rozmnazanie()
{
	Punkt nowy = swiat.czystePoleObok(polozenie.X, polozenie.Y);
	if (nowy.X == polozenie.X && nowy.Y == polozenie.Y) return;
	Wilk* nowa = new Wilk(this->swiat, nowy);
	char* tekst = new char[30];
	sprintf(tekst, "Wlasnie urodzil sie wilk");
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
	this->swiat.dodajOrganizm(nowa);
}


Wilk::~Wilk()
{
}



