#ifndef _dionica_hxx_
#define _dionica_hxx_
#include <iostream>

using namespace std;

class Dionica
{
	private:
	int _ID;
	std::string _Sifra;
	std::string _Naziv;
	double _Cijena;

	public:
	
	void setId( int Id) { _ID = Id;}
	void setSifra(const std::string& sifra) { _Sifra = sifra ; }
	void setNaziv( const std::string& naziv) { _Naziv = naziv;}
	void setCijena( double cijena) { _Cijena = cijena ; }
	
	int getId() { return _ID; }
	std::string getSifra() { return _Sifra;}
	std::string getNaziv() { return _Naziv;}
	double getCijena() { return _Cijena;}
	
	Dionica() = default;
	Dionica(int Id,const std::string& Sifra,const std::string& Naziv,double Cijena):_ID(Id),_Sifra(Sifra),_Naziv(Naziv),_Cijena(Cijena){}
	
	~Dionica()= default;

	bool operator >( const Dionica& b)
	{
		return _ID > b._ID;
	}

	bool operator == ( const Dionica& b)
	{
		return( _ID == b._ID && _Sifra == b._Sifra && _Naziv == b._Naziv && _Cijena== b._Cijena ) ;
	}


	bool operator != ( const Dionica& b)
	{
		return( _ID != b._ID ||  _Sifra != b._Sifra || _Naziv != b._Naziv || _Cijena != b._Cijena ) ;

	}
	
};




#endif
