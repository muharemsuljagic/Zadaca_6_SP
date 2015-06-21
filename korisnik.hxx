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
	void setJmbg( const std::string& jmbg){ _JMBG = jmbg; }
	void setIme(const std::string& ime) { _Ime = ime; }
	void setPrezime(const std::string & prezime ) { _Prezime = prezime;}
	void setBalans( double balans ) { _Balans = balans;}
	void setAdresa( const std::string& adresa) { _Adresa = adresa;}
	void seteMail( const std::string& email) { _eMail = email;}
	void setTel( const std::string& tel ) { _tel = tel;}

	int getId() const { return _ID;}
	const  std::string getJMBG() const { return _JMBG;}
	const std::string getIme() const  { return _Ime;}
	const std::string getPrezime()const { return _Prezime;}
	double getBalans ()const { return _Balans; }
	const std::string getAdresa()const { return _Adresa;}
	const std::string geteMail() const{ return _eMail;}
	const std::string getTel()const { return _tel;}

	Korisnik()= default;
	Korisnik(int Id,const std::string& Jmbg,const std::string& Ime,const std::string& Prezime, double Balans,const std::string& Adresa,const std::string& eMail, const std::string& tel): _ID(Id),_JMBG(Jmbg),_Ime(Ime),_Prezime(Prezime),_Balans(Balans),_Adresa(Adresa),_eMail(eMail),_tel(tel){}
	Korisnik(std::string& jmbg,const std::string& ime, const std::string& prezime, double balans,const std::string& adresa,const std::string& email,const std::string& tel): _ID(0),_JMBG(jmbg),_Ime(ime),_Prezime(prezime),_Balans(balans),_Adresa(adresa),_eMail(email),_tel(tel){}
	~Korisnik()=default;
	
	 bool operator > ( const Korisnik& b) const 
	 {
	   return _ID > b._ID;
	   
	 }
	 bool operator < ( const Korisnik& b) const 
	 {
	   return _ID < b._ID;
	   
	 }
	 
	 bool operator == ( const Korisnik& b) const
	 {
	    return ( _ID==b._ID );  
	   
	  }
	 
	 bool operator !=( const Korisnik & b ) const
	 {
	    return ( _ID!=b._ID );  
	 }

	void promjeniBalans(const double& b)
	  {
	    _Balans+=b;
	  }
	 
	 friend std::ostream& operator << ( std::ostream&,const Korisnik&);
	 
};

/*std::ostream& operator << (std::ostream& izlaz, const Korisnik& a)
{
		izlaz << a.getIme() <<"  " <<a.getPrezime()<<"." << endl;
		izlaz <<"ID: " << a.getId()<<"."<<endl;
		izlaz <<"Balans: " <<a.getBalans()<<" KM" << endl;
		return izlaz;
}
*/

std::ostream& operator << (std::ostream& izlaz, const Korisnik& a)
{
  izlaz<<a.getId() <<","<<a.getJMBG()<<","<<a.getIme()<<","<<a.getPrezime()<<","<<a.getBalans()<<","<<a.getAdresa()<<","<<a.geteMail()<<","<<a.getTel()<<endl;
  return izlaz;
  
}
#endif
