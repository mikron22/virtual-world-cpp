#include "stdafx.h"
#include "Owca.h"



Owca::Owca(Swiat &swiat, Punkt polozenie) : Zwierze(swiat)
{
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si³a = 4;
	this->inicjatywa = 4;
	this->znak = 'o';
}


Owca::~Owca()
{
}

void Owca::rozmnazanie()
{
	Punkt nowy = swiat.czystePoleObok(polozenie.X, polozenie.Y);
	if (nowy.X == polozenie.X && nowy.Y == polozenie.Y) return;
	Owca* nowa = new Owca(this->swiat, nowy);
	char* tekst = new char[30];
	sprintf(tekst, "Wlasnie urodzila sie owca");
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
	this->swiat.dodajOrganizm(nowa);
}
