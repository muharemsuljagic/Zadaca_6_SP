#ifndef _korisnikDionica_hxx_
#define _korisnikDionica_hxx_
#include <iostream>

using namespace std;

class korisnikDionica
{
private:
    int idKorisnik;
    int idDionice;
    int brojDionica;
    bool prodaja;

public:
    korisnikDionica(int id_kor, int id_dio, int broj, bool prod):idKorisnik(id_kor),idDionice(id_dio),brojDionica(broj),prodaja(prod)){};
    void setIDkorisnik(int id_kor);
    void setIDdionice(int id_dio);
    void setBrojDionica(int broj);
    void setProdaja(bool prod);
    int getIDkorisnik();
    int getIDdionice();
    int getBrojDionica();
    bool getProdaja();
    bool operator==(korisnikDionica korisnik);
    bool operator <( const korisnikDionica objekat) const;
    bool operator>( const korisnikDionica objekat) const;
};

void korisnikDionica::setIDkorisnik(int id_kor)
    {
        idKorisnik=id_kor;
    }


void korisnikDionica::setIDdionice(int id_dio)
    {
        idDionice=id_dio;
    }


void korisnikDionica::setBrojDionica(int broj)
    {
        brojDionica=broj;
    }


void korisnikDionica::setProdaja(bool prod)
    {
        prodaja=prod;
    }


int korisnikDionica::getIDkorisnik()
    {
        return idKorisnik;
    }


int korisnikDionica::getIDdionice()
    {
        return idDionice;
    }


int korisnikDionica::getBrojDionica()
    {
        return brojDionica;
    }


bool korisnikDionica::getProdaja()
    {
        return prodaja;
    }

bool korisnikDionica::operator==(korisnikDionica korisnik)
    {
        if(idKorisnik==korisnik.idKorisnik)
            return true;
        return false;

    }

bool korisnikDionica::operator<( const korisnikDionica objekat) const

{
    if ( idDionice ==  objekat.idDIonice)
    return idKorisnik < objekat.idKorisnik;
    else
    return idDionice < objekat idDIonice;

}

bool korisnikDionica::operator>( const korisnikDionica objekat) const

{
    if ( idDionice ==  objekat.idDIonice)
    return idKorisnik > objekat.idKorisnik;
    else
    return idDionice > objekat idDIonice;
}

#endif // _korisnikDionica_hxx_
