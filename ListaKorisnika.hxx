#ifndef _ListaKorisnika_HXX_
#define _ListaKorisnika_HXX_


#include<iostream>
#include "korisnik.hxx"
#include "bst2.hxx"

using namespace std;

class ListaKorisnika
{	
	private:
	binTree<Korisnik> lista;
	int _idCounter=1;
	
	public:
	ListaKorisnika()=default;
	
	
	Korisnik* dodajKorisnika(Korisnik&);

	void ispisiKorisnike() const;	

};

void ListaKorisnika::ispisiKorisnike() const
{
	lista.print();
}

Korisnik* ListaKorisnika::dodajKorisnika(Korisnik& _korisnik)
{
	_korisnik.setId(_idCounter++);
	return lista.push(_korisnik);

}



#endif
