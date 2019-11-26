#include "stdafx.h"
#include "Wilcze_Jagody.h"




Wilcze_Jagody::Wilcze_Jagody(Swiat & swiat, Punkt polozenie) : Roslina(swiat)
{
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si³a = 99;
	this->inicjatywa = 0;
	this->znak = 'j';
}

Wilcze_Jagody::~Wilcze_Jagody()
{
}

void Wilcze_Jagody::rozprzesrzen(Punkt nowy)
{
	Wilcze_Jagody* nowa = new Wilcze_Jagody(this->swiat, nowy);
	this->swiat.dodajOrganizm(nowa);
	char* tekst = new char[30];
	sprintf(tekst, "Jagoda sie rozprzestrzenia");
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
}

void Wilcze_Jagody::kolizja(Organizm * atakujacy)
{
	char* tekst = new char[50];
	sprintf(tekst, "%c zjadl wilcza jagode", atakujacy->getZnak());
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
	swiat.usunOrganizm(atakujacy);
	swiat.usunOrganizm(this);
}
