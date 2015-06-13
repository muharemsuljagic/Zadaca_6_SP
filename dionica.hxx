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
	double _Ukupno;
	double _Preostalo;

	public:
	
	void setUkupno(int ukupno) { _Ukupno = ukupno;}
	void setPreostalo(int preostalo) { _Preostalo = preostalo ; }
	void setId( int Id) { _ID = Id;}
	void setSifra(const std::string& sifra) { _Sifra = sifra ; }
	void setNaziv( const std::string& naziv) { _Naziv = naziv;}
	void setCijena( double cijena) { _Cijena = cijena ; }
	
	double getUkupno() { return _Ukupno;}
	double getPreostalo() { return _Preostalo;}	
	int getId() { return _ID; }
	const std::string getSifra() { return _Sifra;}
	const std::string getNaziv() { return _Naziv;}
	double getCijena() { return _Cijena;}
	
	Dionica() = default;
	Dionica(int Id,const std::string& Sifra,const std::string& Naziv,double Cijena,double Ukupno):_ID(Id),_Sifra(Sifra),_Naziv(Naziv),_Cijena(Cijena),_Ukupno(Ukupno)
	{
		_Preostalo = Ukupno;
	}
	
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
