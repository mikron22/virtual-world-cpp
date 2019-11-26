#include "stdafx.h"
#include "Barszcz_Sosnowskiego.h"



Barszcz_Sosnowskiego::Barszcz_Sosnowskiego(Swiat & swiat, Punkt polozenie) : Roslina(swiat)
{
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si³a = 10;
	this->inicjatywa = 0;
	this->znak = 'b';
}

Barszcz_Sosnowskiego::~Barszcz_Sosnowskiego()
{
}




void Barszcz_Sosnowskiego::rozprzesrzen(Punkt nowy)
{
	Barszcz_Sosnowskiego* nowa = new Barszcz_Sosnowskiego(this->swiat, nowy);
	this->swiat.dodajOrganizm(nowa);
	char* tekst = new char[30];
	sprintf(tekst, "Barszcz sie rozprzestrzenia");
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
}

void Barszcz_Sosnowskiego::akcja()
{
	Organizm* o1 = swiat.czyPuste(polozenie.X - 1, polozenie.Y);
	Organizm* o2 = swiat.czyPuste(polozenie.X + 1, polozenie.Y);
	Organizm* o3 = swiat.czyPuste(polozenie.X, polozenie.Y - 1);
	Organizm* o4 = swiat.czyPuste(polozenie.X, polozenie.Y + 1);
	if (dynamic_cast<Zwierze*>(o1)) {
		char* tekst = new char[30];
		sprintf(tekst, "%c zostal zabity przez barszcz sosnowskiego", o1->getZnak());
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		swiat.usunOrganizm(o1);
	}
	if (dynamic_cast<Zwierze*>(o2)) {
		char* tekst = new char[50];
		sprintf(tekst, "%c zostal zabity przez barszcz sosnowskiego", o2->getZnak());
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		swiat.usunOrganizm(o2);
	}
	if (dynamic_cast<Zwierze*>(o3)) {
		char* tekst = new char[30];
		sprintf(tekst, "%c zostal zabity przez barszcz sosnowskiego", o3->getZnak());
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		swiat.usunOrganizm(o3);
	}
	if (dynamic_cast<Zwierze*>(o4)) {
		char* tekst = new char[30];
		sprintf(tekst, "%c zostal zabity przez barszcz sosnowskiego", o4->getZnak());
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		swiat.usunOrganizm(o4);
	}
}

void Barszcz_Sosnowskiego::kolizja(Organizm * atakujacy)
{
	swiat.usunOrganizm(atakujacy);
	swiat.usunOrganizm(this);
}
