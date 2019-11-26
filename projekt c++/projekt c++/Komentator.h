#pragma once
#include<vector>
#include"Komentarz.h"

using namespace std;
class Komentator
{
	vector<Komentarz*> komentarze;
public:
	Komentator();
	void wyczysc();
	void dodajKomentarz(Komentarz* kom);
	void wypiszKomentarze();
	~Komentator();
};

