#include "stdafx.h"
#include "Lis.h"


Lis::Lis(Swiat &swiat, Punkt polozenie) : Zwierze(swiat)
{
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si³a = 3;
	this->inicjatywa = 7;
	this->znak = 'l';
}



Lis::~Lis()
{
}

void Lis::kolizja(int x, int y)
{
	Organizm *obronca = swiat.czyPuste(x, y);
	if (obronca->getSi³a() > this->si³a) {
		return;
	}
	else Zwierze::kolizja(x, y);
}

void Lis::rozmnazanie()
{
	Punkt nowy = swiat.czystePoleObok(polozenie.X, polozenie.Y);
	if (nowy.X == polozenie.X && nowy.Y == polozenie.Y) return;
	Lis* nowa = new Lis(this->swiat, nowy);
	char* tekst = new char[30];
	sprintf(tekst, "Wlasnie urodzil sie lis");
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
	this->swiat.dodajOrganizm(nowa);
}
