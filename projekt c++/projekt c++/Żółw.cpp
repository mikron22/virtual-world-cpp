#include "stdafx.h"
#include "��w.h"
#include<iostream>





��w::��w(Swiat & swiat, Punkt polozenie) : Zwierze(swiat)
{
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si�a = 2;
	this->inicjatywa = 1;
	this->znak = 'z';
}

��w::~��w()
{
}

bool ��w::odbicie()
{
	if (rand() % 2 == 0) {
		char* tekst = new char[30];
		sprintf(tekst, "Zolw odbija atak");
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		return true;
	}
	return false;
}

void ��w::rozmnazanie()
{
	Punkt nowy = swiat.czystePoleObok(polozenie.X, polozenie.Y);
	if (nowy.X == polozenie.X && nowy.Y == polozenie.Y) return;
	��w* nowa = new ��w(this->swiat, nowy);
	char* tekst = new char[30];
	sprintf(tekst, "Wlasnie urodzil sie zolw");
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
	this->swiat.dodajOrganizm(nowa);


}

void ��w::akcja()
{
	if (rand() % 4 == 0) {
		Zwierze::akcja();
	}
}
