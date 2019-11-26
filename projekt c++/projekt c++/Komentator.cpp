#include"stdafx.h"
#include"Komentator.h"
#include"conio2.h"
#include"Stale.h"


Komentator::Komentator()
{
	wyczysc();
}

void Komentator::wyczysc()
{
	komentarze.clear();
	char* tekst = new char[30];
	sprintf(tekst, "Krzsztof Orlowski 172149");
	Komentarz *k = new Komentarz(tekst);
	dodajKomentarz(k);
	char* pusty = "";
	Komentarz *p = new Komentarz(pusty);
	dodajKomentarz(p);
	dodajKomentarz(p);
}

void Komentator::dodajKomentarz(Komentarz * kom)
{
	komentarze.push_back(kom);
}

void Komentator::wypiszKomentarze()
{
	for (int i = 0; i < komentarze.size(); i++) {
		gotoxy(KOMENTARZ_X, KOMENTARZ_Y + i);
		komentarze[i]->wypisz();
	}
}


Komentator::~Komentator()
{
}
