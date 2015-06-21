#ifndef BST_KORISNIK_DIONICA_HXX
#define BST_KORISNIK_DIONICA_HXX
#include"bst2.hxx"
#include"korisnikDionica.hxx"
#include <iostream>
#include <fstream>
#include "sortirana_lista.hxx"
#include "Kljuc.hxx"
#include "bstkljuc.hxx"
#include <string>

class bstKorisnikDionica {

private:
	binTree<korisnikDionica> niz;
  bstkljuc<int> _idKorisnika;
  bstkljuc<int> _idDionice;
  void ispisiOdCvora(std::ostream&, const binTree<korisnikDionica>::Node*)const;
public:
     
       void upisiUfajl(const std::string &);
       void ucitajIZfajla(const std::string &);
       korisnikDionica * dodajVezu(const korisnikDionica&);
       korisnikDionica * oznaciProdano(korisnikDionica *,const int&);
       const sortiranaLista<int>* nadjiKorisnike (const int&);
       const sortiranaLista<int>* nadjiDionice (const int&); 
       korisnikDionica* nadjiVezu (const int&, const int&); 
};
void bstKorisnikDionica::ispisiOdCvora(std::ostream& o,const binTree<korisnikDionica> :: Node* root) const
{
  if(root -> _left == nullptr && root -> _right == nullptr)
  {
    o<<root->info;
    return;
  }
  if(root -> _left != nullptr)
  {
    ispisiOdCvora(o,root -> _left);
  }
  o<<root -> info;
  if(root -> _right  != nullptr)
  {
    ispisiOdCvora (o, root -> _right);
  }

}


const sortiranaLista<int>* bstKorisnikDionica :: nadjiKorisnike (const int& idDionice)
{
  return _idDionice.findByKey(idDionice);  
}


korisnikDionica* bstKorisnikDionica :: nadjiVezu (const int& idDionica, const int& idKorisnika)
{
  return niz.search(korisnikDionica(idKorisnika,idDionica,0,0));
}

const sortiranaLista<int>* bstKorisnikDionica :: nadjiDionice (const int& idKorisnika)
{
  return _idKorisnika.findByKey(idKorisnika);
}

korisnikDionica* bstKorisnikDionica :: oznaciProdano (korisnikDionica * kord,const int& prodaj)
{
  kord->prodaj(prodaj);
  return kord;
}


korisnikDionica* bstKorisnikDionica :: dodajVezu (const korisnikDionica& nova)
{
  _idDionice.push(nova.getIDdionice(),nova.getIDkorisnik());
  _idKorisnika.push(nova.getIDkorisnik(),nova.getIDdionice());
  return niz.push(nova);
}
void bstKorisnikDionica::ucitajIZfajla(const string& filepath)
{
  std::ifstream myf;
  myf.open(filepath);
  if(myf.is_open())
  {
    std::string input;
    std::string value;
    int i;
    auto f = [](int& i,std::string& value,std::string& input) -> void
    {
      auto s=input.size();
      while (input [i] != ',' && i<s)
      {
        value.push_back(input[i]);
        ++i;
      }
      ++i;
    };

    getline(myf,input);
    int newin;
    while (!myf.eof())
    {
      value="";
      korisnikDionica temp;
      i=0;
      f(i,value,input);
      newin = std::stoi(value);
      temp.setIDkorisnik(newin);
      value="";
      f(i,value,input);
      newin = std::stoi(value);
      temp.setIDdionice(newin);
      value="";
      f(i,value,input);
      newin = std::stoi(value);
      temp.setBrojDionica(newin);
      value="";
      f(i,value,input);
      newin = std::stoi(value);
      temp.setProdaja(newin);
      dodajVezu(temp);      
      getline(myf,input);

    }
  }
}

void bstKorisnikDionica::upisiUfajl(const std::string& filepath)
{
 if( niz.empty())
 {
    return;
 }

 std::ofstream myf;
 myf.open(filepath);
 if(myf.is_open())
 {
   ispisiOdCvora(myf,niz.getRoot());
 }
 else
 {
   throw std::string("Incorrect filepath\n");
 }
}

#endif
