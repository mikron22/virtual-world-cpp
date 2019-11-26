#include "stdafx.h"
#include "Roœlina.h"






Roslina::Roslina(Swiat & swiat) : Organizm(swiat)
{
}

void Roslina::akcja()
{
	int szansa = rand() % 30;
	if (szansa != 15) return;

	int pole = rand() % 4;
	int nowyX;
	int nowyY;
	int sX = this->swiat.getRozmiar().X;
	int sY = this->swiat.getRozmiar().Y;
	while (true) {
		nowyX = polozenie.X;
		nowyY = polozenie.Y;
		pole = rand() % 4;
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
			break;
		}
	}

	if (swiat.czyPuste(nowyX, nowyY) == NULL) {
		Punkt nowy;
		nowy.X = nowyX;
		nowy.Y = nowyY;
		rozprzesrzen(nowy);
	}
}

void Roslina::kolizja(int x, int y)
{
	return;
}
