#include "olionoppa.h"
#include <fstream>

		string k�ytt�j�tunnus;




olionoppa::olionoppa(string _pelinnimi, string _tekij�t, string tiedosto)
{
	pelinnimi = _pelinnimi;
	tekij�t = _tekij�t;
	tiedosto = tiedostoNimi;
	
}

void olionoppa::aloitus()
{
		int valinta = 0;
		cout << pelinnimi << endl;
		cout << endl;
		cout << "Tekij�t: " << tekij�t <<  endl;
		cout << endl;
		cout << endl;
		cout << "Sy�t� k�ytt�j�tunnus" << endl;
		cin >> k�ytt�j�tunnus;
		cout << "k�ytt�j�tunnus: " << k�ytt�j�tunnus << endl;
		cout << endl;
		cout << "Talleta pelitilillesi rahaa." << endl;
		cin >> pelitili;
		cout << endl;
		cout << "Talletit tilillesi " << pelitili << " euroa." << endl;
		cout << endl;
		cout << "Paina 'ENTER' jatkaaksesi" << endl;
		_getch();

	do {
		system("CLS");
		cout << "P��VALIKKO" << endl;
		cout << endl;
		cout << "(1) Aseta panos" << endl;
		cout << "(2) Aloita peli" << endl;
		cout << "(3) N�yt� s��nn�t" << endl;
		cout << "(4) N�yt� pelihistoria" << endl;
		cout << "(5) Nosta rahat" << endl;
		cout << endl;
		cout << "K�ytt�j�tunnus: " << k�ytt�j�tunnus << endl;
		cout << endl;
		cout << "Pelitilin saldo: " << pelitili << " euroa." << endl;
		cout << "T�m�nhetkinen panos: " << panos << " euroa." << endl;
		cin >> valinta;
		
		switch (valinta)
		{
		case 1: {
			asetaPanos();
			break; }

		case 2: {
			aloitaPeli();
			break;
		}
		case 3: {
			tulostaS��nn�t();
			break; }
		case 4:
		{
			cout << "K�ytt�j�n  " << k�ytt�j�tunnus << "  pelihistoria:" << endl;
			cout << "Voitot: " << endl;
			_getch();
			tulostaHistoria();
			break;
		}
		case 5:
			kirjoita();
			exit(0);
		}

	} while (valinta != 0);

}

void olionoppa::asetaPanos()
{
	system("CLS");
	cout << endl;
	do {
		cout << "Aseta panos." << endl;
		cin >> panos;
		cout << "Panos asetettu." << endl;
		cout << endl;
		cout << "Paina 'ENTER' jatkaaksesi." << endl;
	} while (panos > pelitili);
	_getch();
}

void olionoppa::aloitaPeli()
{
	
		cout << endl;
		cout << "Asetit panokseksi " << panos << " euroa." << endl;
		cout << "Pelitilin saldo: " << pelitili << " euroa." << endl;
		cout << endl;
		srand(time(0));

		for (int k = 0; k < 1; k++) {
			noppa1 = (rand() % 6) + 1;
			noppa2 = (rand() % 6) + 1;
		}

		summa = noppa1 + noppa2;
		Sleep(1500);
		cout << "Heitet��n nopat:" << endl;
		Sleep(2000);
		cout << "Ensimm�inen noppa: " << noppa1 << endl;
		Sleep(2500);
		cout << "Toinen noppa: " << noppa2 << endl;
		Sleep(1500);
		cout << endl;
		cout << "Tulos: " << summa << endl;

		if (summa == 7 || summa == 11) {
			cout << "VOITTO! Pelitilillesi siirrettiin " << panos * 2 << " euroa." << endl;
			pelitili = pelitili + panos * 2;
			voitot.push_back(panos * 2);
			cout << "Pelitilin saldo: " << pelitili << " euroa." << endl;
			cout << "Haluatko tuplata voittosi?" << " K/E" << endl;
			cin >> tuplaus;

			if (tuplaus == 'K' || tuplaus == 'k')
			{
				cout << "Valitse pieni (2-6) tai iso (7-11): " << endl;
				cin >> tuplausvastaus;
				tuplausnoppa1 = (rand() % 6) + 1;
				tuplausnoppa2 = (rand() % 5) + 1;
				tuplaussumma = tuplausnoppa1 + tuplausnoppa2;

				if (tuplaussumma < 7 && tuplausvastaus < 7) {
					cout << "Nopanheitoista tuli summa: " << tuplaussumma << " Voitit! pelitilillesi siirret��n: " << panos * 4 << " euroa." << endl;
					pelitili = pelitili + panos * 2;
					voitot.push_back(panos * 2);
				}

				else if (tuplaussumma >= 7 && tuplausvastaus >= 7) {
					cout << "Nopanheitoista tuli summa: " << tuplaussumma << " Voitit! pelitilillesi siirret��n: " << panos * 4 << " euroa." << endl;
					pelitili = pelitili + panos * 2;
					voitot.push_back(panos * 2);
				}

				else
				{
					cout << "H�visit!" << endl;
					cout << "Nopanheitoista tuli summa: " << tuplaussumma << endl;
					pelitili = pelitili - (panos * 3);
					cout << "Pelitilin saldo: " << pelitili << " euroa. " << endl;
					voitot.push_back(-panos * 3);
				}
			}
		}

		if (summa == 2 || summa == 3 || summa == 12) {
			cout << "H�visit" << endl;
			pelitili = pelitili - panos;
			cout << "Pelitilin saldo: " << pelitili << " euroa." << endl;
			voitot.push_back(-panos);
		}

		if (summa == 1 || summa == 4 || summa == 5 || summa == 6 || summa == 8 || summa == 9 || summa == 10) {
			cout << endl;
			cout << "Ei voittoa." << endl;
		}

		cout << "Paina 'ENTER' jatkaaksesi" << endl;
		fflush(stdin);
		_getch();
		system("CLS");

		if (pelitili == 0) {
			cout << endl;
			cout << "Peli ohi. Rahat loppuivat." << endl;
			exit(0);
		}

}

void olionoppa::tulostaS��nn�t()
{
	system("CLS");

	cout << "Uhkapeli nimelt��n Amerikkilainen noppa. Pelaaja tallettaa pelirahaa ja t�m�n j�lkeen p��tt�� panoksen." << endl; 
	cout << "Seuraavaksi heitet��n kahta noppaa." << endl;
	cout << endl;
	cout << "Voittoluvut: 7, 11, voittaessa saat panoksesi kaksinkertaisena" << endl;
	cout << "Menet�t panoksen kun luku on: 2, 3, 12" << endl;
	cout << "Muussa tapauksessa peli jatkuu." << endl;
	cout << endl;
	cout << "Paina 'ENTER' jatkaaksesi p��valikkoon." << endl;
	_getch();
}

void olionoppa::tulostaHistoria()
{

	system("CLS");
	for (auto panos : voitot)
	{
		cout << panos << " euroa." << endl;
	}
	_getch();
}

void olionoppa::kirjoita()
{
	cout << endl;
	cout << "Lopetit pelin." << endl;
	cout << "Nostit " << pelitili << " euroa." << endl;
	ofstream tiedosto(tiedostoNimi);
	if (tiedosto) {
		tiedosto << k�ytt�j�tunnus << endl;
		tiedosto << pelitili << endl;
		tiedosto.close();
	}
}