#include "stdafx.h"
#include "Lista_Organizmow.h"

using namespace std;
Vektor_Organizmow::Vektor_Organizmow()
{
	organizmy.clear();
}


Vektor_Organizmow::~Vektor_Organizmow()
{
}

vector<Organizm*> Vektor_Organizmow::getOrganizmy()
{
	return organizmy;
}

Organizm* Vektor_Organizmow::getOrganizm(int i)
{
	if (i > (int)organizmy.size()) {
		throw exception{
			"Nie ma takiego organizmu"
		};
	}
	return organizmy[i];
}

Organizm * Vektor_Organizmow::getOstatniOrganizm()
{
	return organizmy[organizmy.size()- 1];
}

void Vektor_Organizmow::dodajOrganizm(Organizm* o)
{
	organizmy.push_back(o);

}

void Vektor_Organizmow::usunOrganizm(Organizm * o)
{
	for (int i = 0; i < (int)organizmy.size(); i++) {
		if (organizmy[i] == o) {
			organizmy.erase(organizmy.begin() + i);
		}
	}
}

void Vektor_Organizmow::rysujOrganizmy()
{
	for (int i = 0; i < (int)organizmy.size(); i++) {
		organizmy[i]->rysowanie();
	}
}

void Vektor_Organizmow::sortuj()
{
	//sortowanie po wieku
	int m = 1;
	while (m > 0) {
		m = 0;
		for (int i = 0; i + 1 < (int)organizmy.size(); i++) {
			int wiek1 = organizmy[i]->getWiek();
			int wiek2 = organizmy[i + 1]->getWiek();

			if (wiek1 < wiek2) {
				Organizm* temp = organizmy[i];
				organizmy[i] = organizmy[i + 1];
				organizmy[i + 1] = temp;
				m++;
			}
		}
	}

	//sortowanie po inicjatywie
	m = 1;
	while (m > 0) {
		m = 0;
		for (int i = 0; i + 1 < (int)organizmy.size(); i++) {
			int ini1 = organizmy[i]->getInicjatywa();
			int ini2 = organizmy[i + 1]->getInicjatywa();

			if (ini1 < ini2) {
				Organizm* temp = organizmy[i];
				organizmy[i] = organizmy[i + 1];
				organizmy[i + 1] = temp;
				m++;
			}
		}
	}
}
