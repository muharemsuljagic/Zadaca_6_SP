#ifndef DIONICE_HXX
#define DIONICE_HXX

#include <iostream>
#include "dionica.hxx"
#include "binTreeID.hxx"
#include <fstream>
#include <string>

class Dionice 
{

  public:
    Dionice() : _idCounter(1){}
    
    Dionica* dodajDionicu (Dionica& nova);
    Dionica* dodajDionicu (Dionica&& nova);
    
    Dionica* nadjiPoId (const int& id);
    
   void ucitajIzFajla (const std::string&);
   void pisiUFajl (const std::string&);
  
  private:
    
    void ispisiOdCvora (std::ostream& ,const  binTreeId<Dionica> :: Node*) const;
    
   
    int _idCounter;
    binTreeId<Dionica> _dionice;
    
};
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
    std::cout<<"-------------------------------\n\n\n------------------------------\n\n";
    _dionice.print();
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
     std::cout<<"---"<<value<<std::endl;
     while (input[i] != ',' && i<s)
     {
       value.push_back(input[i]);
       ++i;
     }
     std::cout<<"----"<<value<<" //"<<std::endl;
     ++i;
   };
   
   
   getline(myf,input);
   
   while(!myf.eof())
   {
     value="";
     Dionica temp;
     i=0;
     f(i,value,input);
     temp.setId(std::stoi(value));
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
     _dionice.push(temp);
     getline(myf,input);
   } 
  }
  else
  {
    throw std::string("Incorrect filepath\n");
  }
}
#endif

