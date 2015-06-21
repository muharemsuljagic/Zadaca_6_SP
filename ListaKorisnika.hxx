#ifndef _ListaKorisnika_HXX_
#define _ListaKorisnika_HXX_


#include<iostream>
#include "korisnik.hxx"
#include "binTreeID.hxx"
#include "bstkljuc.hxx"
#include "Kljuc.hxx"
#include <fstream>

class ListaKorisnika
{	
	private:
	int _idCounter=1;
	binTreeId<Korisnik> _lista;
	bstkljuc<string> _poImenu;
	bstkljuc<string> _poPrezimenu;
	void ispisiOdCvora (std::ostream& ,const  binTreeId<Korisnik> :: Node*) const;
	Korisnik* dodajKorisnikaSaId(Korisnik & novi);
	
	public:
	ListaKorisnika()=default;
	const binTreeId<Korisnik>& getKorisnici()const {return _lista;}
  const bstkljuc<string>& getPoImenu ()const {return _poImenu;}
  const bstkljuc<string>& getPoPrezimenu () const {return _poPrezimenu;}
	void ucitajIzFajla (const std::string&);
  void pisiUFajl (const std::string&);
	
	Korisnik* dodajKorisnika(Korisnik);
  
	void ispisiKorisnike() const;	
  
	const sortiranaLista<int>* traziPoImenu(const std::string& ime);
	const sortiranaLista<int>* traziPoPrezimenu (const std::string& prezime);
  
	Korisnik* nadjiPoId(const int& id);
  void ocisti()
  {
    _poImenu.freeTree();
    _poPrezimenu.freeTree();
    _lista.freeTree();
  }    
};

void ListaKorisnika::ucitajIzFajla (const std::string& filepath)
{
  int id=0;
  std::ifstream myf;
  myf.open(filepath);
  if(myf.is_open())
  {
   std::string input;
   std::string value;
   int i;
   
   auto f = [](int& i,std::string& value,std::string& input)-> void
   {
     auto s=input.size();
     while (input[i] != ',' && i<s)
     {
       value.push_back(input[i]);
       ++i;
     }
     ++i;
   };
   
   
   getline(myf,input);
   int newid;
   while(!myf.eof())
   {
     value="";
     Korisnik temp;
     i=0;
     f(i,value,input);
     newid = std::stoi(value);
     temp.setId(newid);
     if(newid > id)
     {
       id=newid;
     }
     value="";
     f(i,value,input);
     temp.setJmbg(value);
     value="";
     f(i,value,input);
     temp.setIme(value);
     value="";
     f(i,value,input);
     temp.setPrezime(value);
     value="";
     f(i,value,input);
     temp.setBalans(stod(value));
     value="";
     f(i,value,input);
     temp.setAdresa(value);
     value="";
     f(i,value,input);
     temp.seteMail(value);
     value="";
     f(i,value,input);
     temp.setTel(value);
     dodajKorisnikaSaId(temp);
     getline(myf,input);
   } 

   _idCounter=id+1;
  }
  else
  {
    throw std::string("Incorrect filepath\n");
  }
}

Korisnik* ListaKorisnika :: dodajKorisnikaSaId (Korisnik& k)
{
 auto p =  _lista.push(k);
 _poImenu.push(k.getIme(),k.getId());
 _poPrezimenu.push(k.getIme(),k.getId());
 return p;
}

void ListaKorisnika:: ispisiOdCvora (std::ostream& o,const binTreeId<Korisnik> :: Node* pok)const
{
  if(pok -> _left == nullptr && pok->_right==nullptr)
  {
    o<<pok->info;
    return;
  }
  if(pok -> _left != nullptr)
  {
    ispisiOdCvora (o,pok->_left);
  }
  
  o<<pok->info;


  if(pok -> _right != nullptr)
  { 
    ispisiOdCvora (o,pok->_right);
  }

}


void ListaKorisnika::pisiUFajl (const std::string& filepath)
{
  if(_lista.empty())
  {
    return;
  }
  
  std::ofstream myf;
  myf.open(filepath);
  if(myf.is_open())
  {
    ispisiOdCvora(myf,_lista.getRoot());
    myf.close();
  }
  else
  {
    throw std::string ("Incorrect filepath\n");
  }
}


void ListaKorisnika::ispisiKorisnike() const
{
	_lista.print();
}

Korisnik* ListaKorisnika::dodajKorisnika(Korisnik korisnik)
{  
  korisnik.setId(_idCounter++);
	auto pok = _lista.push(korisnik);
  _poImenu.push(korisnik.getIme(),korisnik.getId());
  _poPrezimenu.push(korisnik.getPrezime(),korisnik.getId());
  return pok;
}

Korisnik* ListaKorisnika :: nadjiPoId(const int& id)
{
  return _lista.searchId(id);
}

const sortiranaLista<int>* ListaKorisnika :: traziPoImenu (const std::string& ime)
{
  return _poImenu.findByKey(ime);
}
const sortiranaLista<int>* ListaKorisnika :: traziPoPrezimenu (const std::string& prezime)
{
  return _poPrezimenu.findByKey(prezime);
}

#endif
