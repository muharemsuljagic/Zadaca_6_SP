#ifndef _korisnikDionica_hxx_
#define _korisnikDionica_hxx_
#include <iostream>

using namespace std;

class korisnikDionica
{
private:
    int _idKorisnik;
    int _idDionice;
   
    int _brojDionica;
    int _prodaja;

public:
    
    korisnikDionica(int id_kor, int id_dio, int broj, int prod):_idKorisnik(id_kor),_idDionice(id_dio),_brojDionica(broj),_prodaja(prod)){};
    
    void setIDkorisnik(int id_kor);
    void setIDdionice(int id_dio);
    void setBrojDionica(int broj);
    void setProdaja(int prod);
    
    
    int getIDkorisnik();
    int getIDdionice();
    int getBrojDionica();
    int getProdaja() { return _prodaja;}
    
    bool operator==(korisnikDionica korisnik);
    bool operator <( const korisnikDionica objekat) const;
    bool operator>( const korisnikDionica objekat) const;
};

void korisnikDionica::setIDkorisnik(int id_kor)
    {
        _idKorisnik=id_kor;
    }


void korisnikDionica::setIDdionice(int id_dio)
    {
        _idDionice=id_dio;
    }


void korisnikDionica::setBrojDionica(int broj)
    {
        _brojDionica=broj;
    }


void korisnikDionica::setProdaja(int prod)
    {
        _prodaja=prod;
    }


int korisnikDionica::getIDkorisnik()
    {
        return _idKorisnik;
    }


int korisnikDionica::getIDdionice()
    {
        return _idDionice;
    }


int korisnikDionica::getBrojDionica()
    {
        return _brojDionica;
    }


bool korisnikDionica::getProdaja()
    {
        return _prodaja;
    }

bool korisnikDionica::operator==(korisnikDionica korisnik)
    {
        if(_idKorisnik==korisnik._idKorisnik && _idDionice == korisnik._idDionice)
            return true;
	else return false;

    }

bool korisnikDionica::operator<( const korisnikDionica objekat) const

{
    if ( _idDionice ==  objekat._idiIonice)
	return _idKorisnik < objekat._idKorisnik;
    else
	return _idDionice < objekat._idDionice;

}

bool korisnikDionica::operator>( const korisnikDionica objekat) const

{
    if ( _idDionice ==  objekat._idDionice)
	return _idKorisnik > objekat._idKorisnik;
    else
	return _idDionice > objekat._idDionice;
}

#endif // _korisnikDionica_hxx_
