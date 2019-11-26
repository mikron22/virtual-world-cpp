#pragma once
class Vektor_Organizmow;
#include"Stale.h"
#include"Lista_Organizmow.h"
#include"Komentator.h"

class Swiat
{
	Vektor_Organizmow* organizmy;
	Komentator* komentator;
	Punkt rozmiar;
public:
	Swiat();
	Swiat(Vektor_Organizmow* organizmy);
	Swiat(int X, int Y);
	~Swiat();
	Punkt getRozmiar();
	Organizm* czyPuste(int x, int y);
	Punkt czystePoleObok(int x, int y);
	void wypelnijLosowo();
	void sortuj();
	void wykonajTure();
	void rysujSwiat();
	void dodajKomentarz(Komentarz* kom);
	void wypiszKomentarze();
	void resetujKomentarze();
	void dodajOrganizm(Organizm* o);
	void usunOrganizm(Organizm* o);
	bool czlowiekZyje();
	void rysujPlansze();
};

