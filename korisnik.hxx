#ifndef _korisnik_hxx_
#define _korisnik_hxx_

#include<iostream>

using namespace std;

class Korisnik
{
	private:
	int _ID;
	std::string _JMBG;
	std::string _Ime;
	std::string _Prezime;
	double _Balans;
	std::string _Adresa;
	std::string _eMail;
	std::string _tel;
		
	public:
	void setId ( int ID ) { _ID = ID; }
	void setIme(const std::string& ime) { _Ime = ime; }
	void setPrezime(const std::string & prezime ) { _Prezime = prezime;}
	void setBalans( double balans ) { _Balans = balans;}
	void setAdresa( const std::string& adresa) { _Adresa = adresa;}
	void seteMail( const std::string& email) { _eMail = email;}
	void setTel( const std::string& tel ) { _tel = tel;}

	int getId() { return _ID;}
	std::string getJMBG() { return _JMBG;}
	std::string getIme() { return _Ime;}
	std::string getPrezime() { return _Prezime;}
	double getBalans () { return _Balans; }
	std::string getAdresa() { return _Adresa;}
	std::string geteMail() { return _eMail;}
	std::string getTel() { return _tel;}

	Korisnik()= default;
	Korisnik(int Id,const std::string& Jmbg,const std::string& Ime,const std::string& Prezime, double Balans,const std::string& Adresa,const std::string& eMail, const std::string& tel): _ID(Id),_JMBG(Jmbg),_Ime(Ime),_Prezime(Prezime),_Balans(Balans),_Adresa(Adresa),_eMail(eMail),_tel(tel){}

	~Korisnik()=default;
	
	 bool operator > ( const Korisnik& b) const 
	 {
	   return _ID > b._ID;
	   
	 }
	 bool operator == ( const Korisnik& b) const
	 {
	    return ( _ID==b._ID && _Ime==b._Ime && _Prezime==b._Prezime && _Balans==b._Balans && _Adresa==b._Adresa && _eMail==b._eMail && _tel==b._tel );  
	   
	  }
	 
	 bool operator !=( const Korisnik & b ) const
	 {
	    return ( _ID!=b._ID || _Ime!=b._Ime || _Prezime!=b._Prezime || _Balans!=b._Balans || _Adresa!=b._Adresa || _eMail!=b._eMail || _tel!=b._tel);  
	 }
	 
	 friend std::ostream& operator << ( std::ostream&,const Korisnik&);
	 
};

std::ostream& operator << (std::ostream& izlaz, const Korisnik& a)
{
		izlaz << a.getIme() <<"  " <<a.getPrezime()<<"." << endl;
		izlaz <<"ID: " << a.getId()"."<<endl;
		izlaz <<"Balans: " <<getBalans() << endl;
		return izlaz;
}

#endif
