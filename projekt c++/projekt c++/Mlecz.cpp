#include "stdafx.h"
#include "Mlecz.h"





Mlecz::Mlecz(Swiat & swiat, Punkt polozenie) : Roslina(swiat)
{
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si³a = 0;
	this->inicjatywa = 0;
	this->znak = 'm';
}

Mlecz::~Mlecz()
{
}

void Mlecz::akcja()
{
	Roslina::akcja();
	Roslina::akcja();
	Roslina::akcja();
}

void Mlecz::rozprzesrzen(Punkt nowy)
{
	Mlecz* nowa = new Mlecz(this->swiat, nowy);
	this->swiat.dodajOrganizm(nowa);
	char* tekst = new char[30];
	sprintf(tekst, "Mlecz sie rozprzestrzenia");
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
}
