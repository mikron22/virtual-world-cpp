#include "stdafx.h"
#include "Organizm.h"
#include "Ro�lina.h"


Organizm::Organizm(Organizm & o) : swiat(swiat), si�a(si�a), inicjatywa(inicjatywa), wiek(wiek), polozenie(polozenie), znak(znak)
{
}

Organizm::Organizm(Organizm * o) : swiat(swiat), si�a(si�a), inicjatywa(inicjatywa), wiek(wiek), polozenie(polozenie), znak(znak)
{
	this->swiat = o->swiat;
}



Organizm::Organizm(): swiat(Swiat())
{
}

Organizm::Organizm(Swiat &swiat) : swiat(swiat)
{
}


int Organizm::getSi�a() const
{
	return si�a;
}

int Organizm::getInicjatywa() const
{
	return inicjatywa;
}

int Organizm::getWiek() const
{
	return wiek;
}

char Organizm::getZnak() const
{
	return znak;
}

Punkt Organizm::getPolozenie() const
{
	return polozenie;
}

void Organizm::setSi�a(int si�a)
{
	this->si�a = si�a;
}

void Organizm::setWiek(int wiek)
{
	this->wiek = wiek;
}

void Organizm::setPolozenie(Punkt p)
{
	this->polozenie = p;
}

void Organizm::setSwiat(Swiat & swiat)
{
	this->swiat = swiat;
}

void Organizm::kolizja(Organizm * atakujacy)
{
	if (atakujacy->getSi�a() >= this->getSi�a()) {
		char* tekst = new char[30];
		if (dynamic_cast<Roslina*>(this)) {
			sprintf(tekst, "%c zjada %c", atakujacy->getZnak(), this->znak);
		}
		else {
			sprintf(tekst, "%c pokonuje %c", atakujacy->getZnak(), this->znak);
		}
		Komentarz* k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		swiat.usunOrganizm(this);
		atakujacy->setPolozenie(this->polozenie);
	}
	else {
		char* tekst = new char[30];
		sprintf(tekst, "%c zostal pokonany przez %c", atakujacy->getZnak(), this->znak);
		Komentarz* k = new Komentarz(tekst);
		swiat.dodajKomentarz(k);
		swiat.usunOrganizm(atakujacy);
	}
}

Organizm * Organizm::operator=(Organizm * o)
{
	this->inicjatywa = o->inicjatywa;
	this->polozenie = o->polozenie;
	this->wiek = o->wiek;
	this->si�a = o->si�a;
	this->swiat = o->swiat;
	return this;
}

void Organizm::rysowanie()
{
	gotoxy(polozenie.X + PLANSZA_X, polozenie.Y + PLANSZA_Y);
	putch(znak);
}




