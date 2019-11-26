#pragma once
class Organizm;
#include"Organizm.h"
#include<vector>
using namespace std;
class Vektor_Organizmow
{
	vector<Organizm*> organizmy;
public:
	Vektor_Organizmow();
	~Vektor_Organizmow();
	vector<Organizm*> getOrganizmy();
	Organizm* Vektor_Organizmow::getOrganizm(int i);
	Organizm* Vektor_Organizmow::getOstatniOrganizm();
	void sortuj();
	void dodajOrganizm(Organizm* o);
	void usunOrganizm(Organizm* o);
	void rysujOrganizmy();
};

