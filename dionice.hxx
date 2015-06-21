#ifndef DIONICE_HXX
#define DIONICE_HXX

#include <iostream>
#include "dionica.hxx"
#include "binTreeID.hxx"
#include <fstream>
#include <string>
#include "Kljuc.hxx"
#include "bstkljuc.hxx"
class Dionice 
{

  public:
    Dionice() : _idCounter(1){}
    
    Dionica* dodajDionicu (Dionica nova);
    const binTreeId<Dionica>& getDionice()const{return _dionice;}
    const bstkljuc<std::string>& getPoNazivu ()const {return _poNazivu;}
    Dionica* nadjiPoId (const int& id);
    void ucitajIzFajla (const std::string&);
    void pisiUFajl (const std::string&);
    const sortiranaLista<int>* traziPoNazivu (const std::string&);
    void ocisti ()
    {
      _dionice.freeTree();
      _poNazivu.freeTree();
    }
    private:
    
    void ispisiOdCvora (std::ostream& ,const  binTreeId<Dionica> :: Node*) const;
    Dionica* dodajDionicuSaId (Dionica& nova);
    
   
    int _idCounter;
    binTreeId<Dionica> _dionice;
    bstkljuc<std::string> _poNazivu;      
    
};


const sortiranaLista<int>* Dionice :: traziPoNazivu (const std::string& naziv)
{
  return  _poNazivu.findByKey(naziv);
}

Dionica* Dionice :: dodajDionicu (Dionica nova)
{
  nova.setId(_idCounter);
  ++_idCounter;
  auto pok = _dionice.push(nova);
  _poNazivu.push(pok->getNaziv(),pok->getId());
  return pok;
}
Dionica* Dionice :: dodajDionicuSaId (Dionica& nova)
{
  auto pok = _dionice.push(nova);
  _poNazivu.push(pok->getNaziv(),pok->getId());
  return pok;
}
void Dionice :: ispisiOdCvora (std::ostream& o,const binTreeId<Dionica> :: Node* pok)const
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
  
//  o<<(pok->info).getId()<<","<<(pok->info).getSifra()<<","<<(pok->info).getNaziv()<<","<<(pok->info).getCijena()<<","<<(pok->info).getUkupno()<<","<<(pok->info).getPreostalo()<<"\n";
  o<<pok->info;


  if(pok -> _right != nullptr)
  { 
    ispisiOdCvora (o,pok->_right);
  }

}


void Dionice :: pisiUFajl (const std::string& filepath)
{
  if(_dionice.empty())
  {
    return;
  }
  
  std::ofstream myf;
  myf.open(filepath);
  if(myf.is_open())
  {
    ispisiOdCvora(myf,_dionice.getRoot());
    myf.close();
  }
  else
  {
    throw std::string ("Incorrect filepath\n");
  }
}
void Dionice :: ucitajIzFajla (const std::string& filepath)
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
     Dionica temp;
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
     temp.setSifra(value);
     value="";
     f(i,value,input);
     temp.setNaziv(value);
     value="";
     f(i,value,input);
     temp.setCijena(stod(value));
     value="";
     f(i,value,input);
     temp.setUkupno(stoi(value));
     value="";
     f(i,value,input);
     temp.setPreostalo(stoi(value));
     dodajDionicuSaId(temp);
     getline(myf,input);
   } 

   _idCounter=id+1;
  }
  else
  {
    throw std::string("Incorrect filepath\n");
  }
}

Dionica* Dionice :: nadjiPoId (const int& id)
{
  return _dionice.searchId(id);
}
#endif

