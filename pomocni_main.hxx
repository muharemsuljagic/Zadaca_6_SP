#ifndef _POMOCNI_MAIN_ZADATAK_5_HXX_
#define _POMOCNI_MAIN_ZADATAK_5_HXX_
#include<iostream>

#include "admin.hxx"

using namespace std;

int pocetna()
{
	int sw;
	cout << endl;
	cout << "Dobro došli. " << endl;
	cout << "- - - - - - - - - - - - - - - - - - - " << endl;
	cout << "1. Prijava.\n0. Izlaz.\n" ;
	cout << "- - - - - - - - - - - - - - - - - - - " << endl;
	cout <<"Izaberi: " ; 
	cin >> sw;
	return sw;
}

int admin()
{
	int sw;
	cout << endl;
	cout << "- - - - - - - - - - - - - - - - - - - " << endl;
	cout << "          Dobro došli nazad.          " << endl;
	//cout << "            getName() \n";
	cout <<"- - - - - - - - - - - - - - - - - - - \n";
	cout << "1. Dodaj korisnika.\n2. Dodaj dionicu.\n3. Kupi dionicu.\n4. Stavi dionicu na prodaju.\n5. Ispis korisnika po ID.\n6. Ispis korisnika po imenu.\n";
	cout << "7. Ispis korisnika po prezimenu.\n8. Ispis dionica po ID.\n9. Ispis dionica po nazivu.\n10. Traži korisnike po imenu.\n11. Traži korisnike po prezimenu.\n";
	cout << "12. Traži dionicu po nazivu.\n13. Učitaj iz fajla.\n14. Upiši u fajl.\n";
	cout << "- - - - - - - - - - - - - - - - - - - " << endl;
	cout<<"0. Izlaz.\n"; 
	cout << "- - - - - - - - - - - - - - - - - - - " << endl;
	cout <<"Izaberi: " ; 
	cin >> sw;
	cout <<"\n";
	return sw;
}

int kupovina()
{
		int sw;
		cout <<"\n";
		cout <<"- - - - - - - - - - - - - - - - - - - \n";
		cout <<"1. Kupovina dionica od korisnika.\n2. Kupovina slobodnih dionica.\n0. Izlaz.\n";
		cout <<"- - - - - - - - - - - - - - - - - - - \n";
		cout <<"Izaberi: ";
		cin >> sw;
		cout <<"\n";
		return sw;
	
}


#endif
