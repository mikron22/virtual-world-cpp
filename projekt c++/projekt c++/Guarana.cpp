#include "stdafx.h"
#include "Guarana.h"


Guarana::Guarana(Swiat & swiat, Punkt polozenie) : Roslina(swiat)
{
	this->swiat = swiat;
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si³a = 0;
	this->inicjatywa = 0;
	this->znak = 'g';
}

Guarana::~Guarana()
{
}

void Guarana::rozprzesrzen(Punkt nowy)
{
	Guarana* nowa = new Guarana(this->swiat, nowy);
	this->swiat.dodajOrganizm(nowa);
	char* tekst = new char[30];
	sprintf(tekst, "Guarana sie rozprzestrzenia");
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
}

void Guarana::kolizja(Organizm * atakujacy)
{
	int s = atakujacy->getSi³a();
	s += 3;
	atakujacy->setSi³a(s);
	Organizm::kolizja(atakujacy);
}
