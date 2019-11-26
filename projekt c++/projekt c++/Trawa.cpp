#include "stdafx.h"
#include "Trawa.h"





Trawa::Trawa(Swiat & swiat, Punkt polozenie) : Roslina(swiat)
{
	this->swiat = swiat;
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si³a = 0;
	this->inicjatywa = 0;
	this->znak = 't';
}

Trawa::~Trawa()
{
}

void Trawa::rozprzesrzen(Punkt nowy)
{
	Trawa* nowa = new Trawa(this->swiat, nowy);
	this->swiat.dodajOrganizm(nowa);
	char* tekst = new char[30];
	sprintf(tekst, "Trawa sie rozprzestrzenia");
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
}
