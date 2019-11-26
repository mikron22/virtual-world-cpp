#include "stdafx.h"
#include "Komentarz.h"
#include"conio2.h"




Komentarz::Komentarz(char * tekst)
{
	this->tekst = tekst;
}

void Komentarz::wypisz()
{
	cputs(tekst);
}

Komentarz::~Komentarz()
{
	delete tekst;
}
