#include "stdafx.h"
#include "Czlowiek.h"




Czlowiek::Czlowiek(Swiat & swiat, Punkt polozenie) : Zwierze(swiat)
{
	this->polozenie = polozenie;
	this->wiek = 0;
	this->si³a = 5;
	this->inicjatywa = 4;
	this->znak = 'C';
	this->moc = 0;
}

void Czlowiek::akcja()
{
	int nowyX = polozenie.X;
	int nowyY = polozenie.Y;
	int sX = this->swiat.getRozmiar().X;
	int sY = this->swiat.getRozmiar().Y;
	int znak = 1;
	while (znak == 1) {
		znak = getch();
		switch (znak) {
		case 0:
			if (kbhit()) {
				znak = getch();
				switch (znak)
				{
				case 75:
					nowyX--;	//lewo
					break;
				case 77:
					nowyX++;	//prawo
					break;
				case 80:
					nowyY++;	//dol
					break;
				case 72:
					nowyY--;	//gora
					break;
				default:
					znak = 1;
					break;
				}
			}
			break;
		case 'm':
			znak = 1;
			if (moc <= 0) {
				moc = 10;
			}
			break;
		default:
			znak = 1;
		}
	}
	if ((nowyX >= 0) && (nowyX < sX) && (nowyY >= 0) && (nowyY < sY)) {
		if (swiat.czyPuste(nowyX, nowyY) == NULL) {
			polozenie.X = nowyX;
			polozenie.Y = nowyY;
		}
		else {
			Zwierze::kolizja(nowyX, nowyY);
		}
	}
	if (moc > 5) {
		kolizja(this);
	}
	moc--;
	if (moc > 5) {
		char* tekst = new char[50];
		sprintf(tekst, "Moc czlowieka aktywna przez kolejne %d tur", moc - 5);
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
	}
	if (moc <= 5 && moc > 0) {
		char* tekst = new char[50];
		sprintf(tekst, "Moc czlowieka dostepna za %d tur", moc);
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
	}
}

void Czlowiek::kolizja(Organizm * o)
{
	if (moc < 5) {
		Organizm::kolizja(o);
		return;
	}
	Organizm* o1 = swiat.czyPuste(polozenie.X - 1, polozenie.Y);
	Organizm* o2 = swiat.czyPuste(polozenie.X + 1, polozenie.Y);
	Organizm* o3 = swiat.czyPuste(polozenie.X, polozenie.Y - 1);
	Organizm* o4 = swiat.czyPuste(polozenie.X, polozenie.Y + 1);
	if (o1) {
		char* tekst = new char[30];
		sprintf(tekst, "%c zostal spalony przez moc czlowieka", o1->getZnak());
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		swiat.usunOrganizm(o1);
	}
	else {
		delete o1;
	}
	if (o2) {
		char* tekst = new char[30];
		sprintf(tekst, "%c zostal spalony przez moc czlowieka", o2->getZnak());
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		swiat.usunOrganizm(o2);
	}
	else {
		delete o2;
	}
	if (o3) {
		char* tekst = new char[30];
		sprintf(tekst, "%c zostal spalony przez moc czlowieka", o3->getZnak());
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		swiat.usunOrganizm(o3);
	}
	else {
		delete o3;
	}
	if (o4) {
		char* tekst = new char[30];
		sprintf(tekst, "%c zostal spalony przez moc czlowieka", o4->getZnak());
		Komentarz *k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		swiat.usunOrganizm(o4);
	}
	else {
		delete o4;
	}
}

Czlowiek::~Czlowiek()
{
}
