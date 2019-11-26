#include "stdafx.h"
#include "Zwierzê.h"
#include <iostream>


Zwierze::Zwierze()
{
}

Zwierze::Zwierze(Swiat &swiat): Organizm(swiat)
{

}

void Zwierze::akcja()
{
	int pole;
	int sX = this->swiat.getRozmiar().X;
	int sY = this->swiat.getRozmiar().Y;
	int nowyX;
	int nowyY;
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
		polozenie.X = nowyX;
		polozenie.Y = nowyY;
	}
	else {
		kolizja(nowyX, nowyY);
	}
}

void Zwierze::kolizja(int x, int y)
{
	Organizm *obronca = swiat.czyPuste(x, y);
	if (obronca->getZnak() == this->getZnak()) {
		rozmnazanie();
		return;
	}
	if (obronca->odbicie() == true) {
		return;
	}
	obronca->kolizja(this);

}
