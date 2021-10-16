#pragma once 
#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <string> 
#include <Windows.h> 
#include <conio.h> 
#include <cstdio> 
#include <vector>
using namespace std;


class olionoppa
{
public:
	olionoppa(string _pelinnimi, string _tekijät, string tiedosto);
	~olionoppa(void){}
	string pelinnimi;
	string tekijät;
	int noppa1;
	int noppa2;
	int panos = 0;
	int summa = 0;
	int valinta;
	int pelitili = 0;
	char vastaus;
	char tuplaus;
	int tuplausvastaus;
	int tuplaussumma;
	int tuplausnoppa1;
	int tuplausnoppa2;
	void aloitus();
	void asetaPanos();
	void aloitaPeli();
	void tulostaSäännöt();
	void tulostaHistoria();
	vector<int> voitot;
	void kirjoita();
	string tiedostoNimi = "Pelivoitot.dat";
	
private:


};

