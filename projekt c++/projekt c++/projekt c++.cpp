// projekt c++.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include<time.h>
#include"Organizm.h"
#include"Roślina.h"
#include"Stale.h"
#include"Swiat.h"
#include"Zwierzę.h"
#include"Lista_Organizmow.h"

int main()
{
	srand((int)time(NULL));
	Vektor_Organizmow* organizmy = new Vektor_Organizmow();
	Swiat s = Swiat(organizmy);
	Swiat & swiat = s;
	swiat.wypelnijLosowo();
	swiat.rysujSwiat();
	swiat.wypiszKomentarze();
	if (getch() == 0) {
		while (kbhit()) getch();
	}
	while(true) {
		if (swiat.czlowiekZyje() == false) {
			if (getch() == 0) {
				while (kbhit()) getch();
			}
		}
		swiat.wykonajTure();
	}
    return 0;
}

