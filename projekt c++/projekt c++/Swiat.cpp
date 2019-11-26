#include "stdafx.h"
#include "Swiat.h"
#include <iostream>
#include "conio2.h"
#include"Antylopa.h"
#include"Lis.h"
#include"Organizm.h"
#include"Owca.h"
#include"Roœlina.h"
#include"Stale.h"
#include"Swiat.h"
#include"Wilk.h"
#include"Zwierzê.h"
#include"¯ó³w.h"
#include"Lista_Organizmow.h"
#include"Trawa.h"
#include"Mlecz.h"
#include"Guarana.h"
#include"Wilcze_Jagody.h"
#include"Barszcz_Sosnowskiego.h"
#include"Czlowiek.h"
#include"Guarana.h"

using namespace std;


Swiat::Swiat()
{

}

Swiat::Swiat(Vektor_Organizmow * organizmy)
{
	int x = 0;
	int y = 0;
	gotoxy(0, 0);
	cputs("Podaj szerokosc planszy\n");
	int znak;
	while (true) {
		znak = getche();
		znak = znak - '0';
		if (znak >= 0 && znak < 10) {
			x *= 10;
			x += znak;
			znak = 1;
		}
		else {
			while (kbhit()) {
				getch();
			}
			break;
		}
	}
	cputs("\nPodaj wysokosc planszy\n");
	while (true) {
		znak = getche();
		znak = znak - '0';
		if (znak >= 0 && znak < 10) {
			y *= 10;
			y += znak;
			znak = 1;
		}
		else {
			while (kbhit()) {
				getch();
			}
			break;
		}
	}
	this->rozmiar.X = x;
	this->rozmiar.Y = y;
	this->organizmy = organizmy;
	this->komentator = new Komentator();
}

Swiat::Swiat(int X, int Y)
{
	this->rozmiar.X = X;
	this->rozmiar.Y = Y;
}


Swiat::~Swiat()
{
}

Punkt Swiat::getRozmiar()
{
	return rozmiar;
}

Organizm* Swiat::czyPuste(int x, int y)
{
	for (int i = 0; i < organizmy->getOrganizmy().size(); i++) {
		Punkt p = organizmy->getOrganizm(i)->getPolozenie();
		if (p.X == x && p.Y == y) return organizmy->getOrganizm(i);
	}
	return NULL;
}

Punkt Swiat::czystePoleObok(int x, int y)
{
	int pole = rand() % 4;
	int nowyX;
	int nowyY;
	int sX = this->getRozmiar().X;
	int sY = this->getRozmiar().Y;
	for (int i = 0; i < 4; i++) {
		nowyX = x;
		nowyY = y;
		switch (pole) {
		case 0:
			nowyX++;
			break;
		case 1:
			nowyX--;
			break;
		case 2:
			nowyY++;
			break;
		case 3:
			nowyY--;
			break;
		}
		if ((nowyX >= 0) && (nowyX < sX) && (nowyY >= 0) && (nowyY < sY)) {
			if (czyPuste(nowyX, nowyY) == NULL) {
				Punkt pusty(nowyX, nowyY);
				return pusty;
			}
		}
	}
	Punkt brak(x, y);
	return brak;
}




void Swiat::sortuj()
{
	organizmy->sortuj();
}



void Swiat::wykonajTure()
{
	resetujKomentarze();
	sortuj();

	for (int i = 0; i < (int)organizmy->getOrganizmy().size(); i++) {
		Organizm* o = organizmy->getOrganizm(i);
		o->akcja();
	}
	for (int i = 0; i < (int)organizmy->getOrganizmy().size(); i++) {
		Organizm* o = organizmy->getOrganizm(i);
		int w = o->getWiek();
		o->setWiek(w + 1);
	}
	char* tekst = new char[30];
	if (czlowiekZyje() == false) {
		tekst = "Nacisnij dowolny przycisk...";
	}
	else {
		tekst = "Nacisnij strzalke lub m";
	}
	Komentarz * kom = new Komentarz(tekst);
	dodajKomentarz(kom);

	rysujSwiat();
	wypiszKomentarze();


}

void Swiat::rysujSwiat()
{
	clrscr();
	rysujPlansze();
	organizmy->rysujOrganizmy();
}

void Swiat::dodajKomentarz(Komentarz * kom)
{
	komentator->dodajKomentarz(kom);
}

void Swiat::wypiszKomentarze()
{
	komentator->wypiszKomentarze();
}

void Swiat::resetujKomentarze()
{
	komentator->wyczysc();
}

void Swiat::dodajOrganizm(Organizm * o)
{
	organizmy->dodajOrganizm(o);
	organizmy->getOstatniOrganizm()->setSwiat(*this);
}

void Swiat::usunOrganizm(Organizm * o)
{
	organizmy->usunOrganizm(o);
}

bool Swiat::czlowiekZyje()
{
	for (int i = 0; i < organizmy->getOrganizmy().size(); i++) {
		if (dynamic_cast<Czlowiek*>(organizmy->getOrganizm(i))) {
			return true;
		}
	}
	return false;
}

void Swiat::rysujPlansze()
{
	for (int j = -1; j <= PLANSZA_Y + rozmiar.Y; j++) {
		if ((j == -1) || (j == PLANSZA_Y + rozmiar.Y)) {
			for (int i = -1; i <= PLANSZA_X + rozmiar.X; i++) {
				gotoxy(i + PLANSZA_X, j + PLANSZA_Y);
				putch('#');
			}
		}
		else {
			for (int i = -1; i <= PLANSZA_X + rozmiar.X; i++) {
				if (i == -1 || i == PLANSZA_X + rozmiar.X) {
					gotoxy(i + PLANSZA_X, j + PLANSZA_Y);
					putch('#');
				}
				else {
					gotoxy(i + PLANSZA_X, j + PLANSZA_Y);
					putch('.');
				}
			}
		}
	}
}

void Swiat::wypelnijLosowo()
{
	Punkt p(0, 0);
	//czlowiek
	int i = 0;
	while (i < 1) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new Czlowiek(*this, p));
			i++;
		}
	}
	//wilki
	i = 0;
	while (i < 3) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new Wilk(*this, p));
			i++;
		}
	}
	//owce
	i = 0;
	while (i < 3) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new Owca(*this, p));
			i++;
		}
	}
	//¿ó³wie
	i = 0;
	while (i < 3) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new ¯ó³w(*this, p));
			i++;
		}
	}
	//antylopy
	i = 0;
	while (i < 3) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new Antylopa(*this, p));
			i++;
		}
	}
	//lisy
	i = 0;
	while (i < 3) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new Lis(*this, p));
			i++;
		}
	}
	//trawa
	i = 0;
	while (i < 3) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new Trawa(*this, p));
			i++;
		}
	}
	//mlecze
	i = 0;
	while (i < 3) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new Mlecz(*this, p));
			i++;
		}
	}
	//jagody
	i = 0;
	while (i < 3) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new Wilcze_Jagody(*this, p));
			i++;
		}
	}
	//barszcze
	i = 0;
	while (i < 3) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new Barszcz_Sosnowskiego(*this, p));
			i++;
		}
	}
	//guarany
	i = 0;
	while (i < 3) {
		p.X = rand() % rozmiar.X;
		p.Y = rand() % rozmiar.Y;
		if (czyPuste(p.X, p.Y) == NULL) {
			dodajOrganizm(new Guarana(*this, p));
			i++;
		}
	}
}
