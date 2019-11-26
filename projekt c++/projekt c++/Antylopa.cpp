#include "stdafx.h"
#include "Antylopa.h"



Antylopa::Antylopa(Swiat & swiat, Punkt polozenie) : Zwierze(swiat)
{
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si³a = 4;
	this->inicjatywa = 4;
	this->znak = 'a';
}

void Antylopa::akcja()
{
	int pole;
	int sX = this->swiat.getRozmiar().X;
	int sY = this->swiat.getRozmiar().Y;
	int nowyX;
	int nowyY;
	while (true) {
		nowyX = polozenie.X;
		nowyY = polozenie.Y;
		pole = rand() % 8;
		switch (pole) {
		case 0:
			nowyX++;
			nowyX++;
			break;
		case 1:
			nowyX--;
			nowyX--;
			break;
		case 2:
			nowyY++;
			nowyY++;
			break;
		case 3:
			nowyY--;
			nowyY--;
			break;
		case 4:
			nowyX++;
			nowyY--;
			break;
		case 5:
			nowyX--;
			nowyY--;
			break;
		case 6:
			nowyX++;
			nowyY++;
			break;
		case 7:
			nowyX--;
			nowyY++;
			break;
		}
		if ((nowyX >= 0) && (nowyX < sX) && (nowyY >= 0) && (nowyY < sY)) {
			break;
		}
	}
	if (swiat.czyPuste(nowyX, nowyY) == NULL) {
		polozenie.X = nowyX;
		polozenie.Y = nowyY;
	}
	else {
		Zwierze::kolizja(nowyX, nowyY);
	}
}

void Antylopa::kolizja(Organizm * o)
{
	if (rand() % 2 == 0) { 
		Organizm::kolizja(o);
		return;
	}
	Punkt nowy = swiat.czystePoleObok(polozenie.X, polozenie.Y);
	if (nowy.X == polozenie.X && nowy.Y == polozenie.Y) {
		Organizm::kolizja(o);
	}
	else {
		o->setPolozenie(this->polozenie);
		this->polozenie = nowy;
		char* tekst = new char[30];
		sprintf(tekst, "Antylopa ucieka przed walka");
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
	}
}

Antylopa::~Antylopa()
{
}

void Antylopa::rozmnazanie()
{
	Punkt nowy = swiat.czystePoleObok(polozenie.X, polozenie.Y);
	if (nowy.X == polozenie.X && nowy.Y == polozenie.Y) return;
	Antylopa* nowa = new Antylopa(this->swiat, nowy);
	char* tekst = new char[30];
	sprintf(tekst, "Wlasnie urodzila sie antylopa");
	Komentarz *k = new Komentarz(tekst);
	swiat.dodajKomentarz(k);
	this->swiat.dodajOrganizm(nowa);
}
