#ifndef BROKER_HXX
#define BROKER_HXX

#include <iostream>
#include "dionice.hxx"
#include "ListaKorisnika.hxx"
#include "korisnikDionica.hxx"
#include "bstKorisnikDionica.hxx"
class Broker
{
  private:

  void ispisiDionicuKorisnika(const int& , const int&);
  void ispisiKorisnika(const Korisnik*);
  void ispisiKorisnika(const Kljuc<std::string>*);
  void ispisiDionicu(const Dionica* );
  void ispisiDionicu(const Kljuc<std::string>*);
  
  template <typename U>
    void ispisiKorisnike(U);

    template <typename U>
    void IspisiDionice(U);
  public:

    Korisnik* DodajKorisnika(const Korisnik&);
    Dionica* DodajDionicu(const Dionica&); 
    void IspisiKorisnikePoId(); 
    void IspisiKorisnikePoImenu(); 
    void IspisiKorisnikePoPrezimenu(); 
    void IspisiDionicePoNazivu(); 
    void IspisiDionicePoId();

    void TraziKorisnikePoPrezimenu(const std::string&);    
    void TraziKorisnikePoImenu(const std::string&); 
    void TraziDionicePoNazivu(const std::string&);  
  
    void UcitajIzFajla(); 
    void PisiUFajl();  
    korisnikDionica* kupiDionicu(const int&, const int&, const int&);
    
    korisnikDionica* staviNaProdaju(const int&, const int&);  //implementirati

  private:

    Dionice _dionice;
    ListaKorisnika _korisnici;
    bstKorisnikDionica _veze;
 
  public:

};

korisnikDionica* Broker :: staviNaProdaju (const int& idKorisnik, const int& idDionice)
{
  auto korisnik = _korisnici.nadjiPoId(idKorisnik);
  auto dionica = _dionice.nadjiPoId(idDionice);
  if(korisnik == nullptr)
  {
    std::cout<<"Korisnik nije pronadjen\n";
    return nullptr;
  }
  if(dionica == nullptr)
  {
    std::cout<<"Dionica nije pronadjena\n";
    return nullptr;
  }
  
  auto veza = _veze.nadjiVezu(idDionice,idKorisnik);
  if(veza == nullptr)
  {
    std::cout<<"Korisnik nije vlasnik dionice\n";
    return nullptr;
  }
  std::cout<<"\n-----------------------------\nKorisnik:\n";
  std::cout<<korisnik -> getIme() <<" "<<korisnik -> getPrezime()<<std::endl;
  std::cout<<"Posjeduje :"<<veza -> getBrojDionica() <<" dionica\n";
  std::cout<<"Trenutno na prodaji je: "<<veza -> getProdaja()<<"dionica\n";

  while(1)
  {
    std::cout<<"Unesite broj dionica koji zelita staviti na prodaju"<<std::endl;
    int n;
    cin >> n;
    if (n<0 || n > (veza -> getBrojDionica() - veza -> getProdaja()))
    {
      std::cout<<"Korisnik nema dovoljno dionica u svome vlasništvu\n";
      std::cout<<"Novi unos (y/n)";
      char ch;
      cin >> ch;
      if(ch != 'y')
      {
        break;
      }
    }
    else
    {
      veza -> staviNaProdaju(n);
      std::cout<<"Dionice su stavljene na trziste\n";
      return veza;
    }
  }
  return nullptr;
  
}

void Broker :: UcitajIzFajla()
{
  _korisnici.ocisti();
  _dionice.ocisti();
  _veze.ocisti();
  _korisnici.ucitajIzFajla("txtfiles/korisnici.txt");
  _dionice.ucitajIzFajla("txtfiles/dionice.txt");
  _veze.ucitajIZfajla("txtfiles/veze.txt");
}
void Broker :: PisiUFajl ()
{
  _korisnici.pisiUFajl("txtfiles/korisnici.txt");
  _dionice.pisiUFajl("txtfiles/dionice.txt");
  _veze.upisiUfajl("txtfiles/veze.txt");
}

korisnikDionica* Broker :: kupiDionicu(const int& idDionice, const int& idKupca, const int& idProdavca=-1)
{
  if(idProdavca == -1)
  {
    auto pokDionice = _dionice.nadjiPoId(idDionice);
    auto pokKupca = _korisnici.nadjiPoId(idKupca);
    if(pokDionice == nullptr)
    {
      std::cout<<"Dionica nije pronadjena \n";
      return nullptr;
    }
    if(pokKupca == nullptr)
    {
      std::cout<<"Korisnik nije pronadjen \n";
      return nullptr;
    }
    std::cout<<"----------------------------\n";
    std::cout<<"Naziv dionice:"<<pokDionice -> getNaziv()<<"\n";
    std::cout<<"Sifra dionice:"<<pokDionice -> getSifra()<<"\n";
    std::cout<<"Broj slobodnih dionica:"<<pokDionice -> getPreostalo()<<"\n";
    std::cout<<"----------------------------\n";
    std::cout<<"Balans kupca:"<<pokKupca ->getBalans()<<"\n";
    std::cout<<"\n\n";
    int brDionica;
    while (1)
    {
      std::cout<<"Unesi broj dionica koji zelite kupiti\n";
      cin>>brDionica;
      if(brDionica * double(pokDionice ->getCijena())  > pokKupca -> getBalans())
      {
        std::cout<<"Kupac nema dovoljno novca na racunu\n";
        std::cout<<"Novi unos(y/n)\n";
        char in;
        cin>>in;
        if(in != 'y')
        {
          break;
        }
      } 
      else if(brDionica > pokDionice -> getPreostalo())
      {
        std::cout<<"Nema dovoljan broj slobodnih dionica\n";
        std::cout<<"Novi unos(y/n)\n";
        char in;
        cin>>in;
        if(in != 'y')
        {
          break;
        }
      }
      else
      {
        pokDionice -> prodaj(brDionica);
        pokKupca -> promjeniBalans(-(brDionica * double(pokDionice -> getCijena())));
        auto ptrveza = _veze.nadjiVezu(idDionice,idKupca);
        if(ptrveza == nullptr)
        {
        korisnikDionica temp(idKupca,idDionice,brDionica,0);
        ptrveza= _veze.dodajVezu(temp);       
        }
        else
        {
          ptrveza -> setBrojDionica(ptrveza -> getBrojDionica() + brDionica);
        }
        return ptrveza;
      }
     
    } return nullptr;
  }
  else
  {
    auto pokKupac=_korisnici.nadjiPoId(idKupca);
    auto pokVeza=_veze.nadjiVezu(idDionice,idProdavca);
    if(pokKupac == nullptr)
    {
      std::cout<<"Korisnik nije pronadjen"<<std::endl;
      return nullptr;
    }
    if(pokVeza == nullptr)
    {
      std::cout<<"Nije pronadjen prodavac"<<std::endl;
      return nullptr;
    }
    
    if(pokVeza ->getProdaja() == 0)
    {
      std::cout<<"Korisnik nema dionice na prodaju\n";
      return nullptr;
    }

    auto pokDionica = _dionice.nadjiPoId(idDionice);
    std::cout<<"--------------------------------\n";
    std::cout<<"Na prodaju je : "<<pokVeza->getProdaja()<<" dionica"<<std::endl;
    std::cout<<"Po cijeni: "<<pokDionica ->getCijena()<<std::endl;
    std::cout<<"\n";
    std::cout<<"Balans kupca je: "<<pokKupac ->getBalans()<<"\n";
    std::cout<<"\n\n";
    std::cout<<"---------------------------------\n";
    int brDionica;
    while(1)
    {
      std::cout<<"Unesi broj dionica za kupovinu\n";
      cin>>brDionica;
      if (brDionica > pokVeza->getProdaja())
      {
        std::cout<<"Tolikla kolicina dionica nije na prodaju\n";
        break;
      }
      if(brDionica * pokDionica -> getCijena() <= pokKupac -> getBalans())
      {
         pokVeza -> prodaj(brDionica);
         pokKupac -> promjeniBalans(brDionica * double(pokDionica -> getCijena()));
         std::cout<<"Transakcija uspjesno izvrsena\n";
         break;
      }
      else
      {
        std::cout<<"Kupac nema dovoljno novca\nNovi unos (y/n)\n)";
        char in;
        cin>>in;
        if(in != 'y')
        {
          break;
        }
      }
    }
    return pokVeza;

  }
}
Korisnik* Broker :: DodajKorisnika(const Korisnik& novi)
{
  return _korisnici.dodajKorisnika(novi);
}


Dionica* Broker :: DodajDionicu(const Dionica& nova)
{
  return _dionice.dodajDionicu(nova);
}


void Broker :: TraziKorisnikePoImenu (const std::string& ime)
{
  const sortiranaLista<int>* pok= _korisnici.traziPoImenu(ime);
  if(pok == nullptr)
  {
    std::cout<<"Ni jedan korisnik nije pronadjen\n";
    return;
  }
  auto it = pok->begin();
  while(it != pok->end())
  {
    auto pok = _korisnici.nadjiPoId(*it);
    ispisiKorisnika(pok);
    ++it;
  }
}



void Broker :: TraziKorisnikePoPrezimenu (const std::string& prezime)
{

  const sortiranaLista<int>* pok= _korisnici.traziPoPrezimenu(prezime);
  if(pok == nullptr)
  {
    std::cout<<"Ni jedan korisnik nije pronadjen\n";
    return;
  }
  auto it = pok->begin();
  while(it != pok->end())
  {
    auto pok = _korisnici.nadjiPoId(*it);
    ispisiKorisnika(pok);
    ++it;
  }
}
void Broker :: ispisiKorisnika(const Korisnik* kor)
{
    if(kor != nullptr)
    {
      std::cout<<"---------------------------------\n";
      std::cout<<"ID : "<<kor->getId() << "\n";
      std::cout<<"JMBG: "<<kor ->getJMBG()<<"\n";
      std::cout<<"Ime: "<<kor ->getIme()<<"\n";
      std::cout<<"Prezime:"<<kor -> getPrezime() <<"\n";
      auto pok2 =(_veze.nadjiDionice(kor->getId()));
      if (pok2 != nullptr)
      {
        auto itd = pok2 -> begin();
        while (itd != pok2->end())
        {
          ispisiDionicuKorisnika(*itd,kor -> getId());
          ++itd;
        }
      }
      std::cout<<"Adresa: "<<kor ->getAdresa()<<"\n";
      std::cout<<"Balans: "<<kor ->getBalans()<<"\n";
      std::cout<<"E-mail: "<<kor ->geteMail()<<"\n";
      std::cout<<"Telefon: "<<kor ->getTel()<<"\n";
      std::cout<<"---------------------------------\n";

    }
    else
    {
      std::cout<<"Korisnik nije pronadjen \n";
    }
}
void Broker :: ispisiDionicuKorisnika(const int& idD,const int& idK)
{
        auto dio = _dionice.nadjiPoId(idD);
        std::cout<<"\tNaziv: "<<dio ->getNaziv()<<"  -  "<<dio -> getSifra()<<"\n";
        auto veza = _veze.nadjiVezu(idD,idK);
        std::cout<<"\tU vlasnistvu:"<<veza ->getBrojDionica()<<" -  Prodaje:"<<veza -> getProdaja()<<"\n";  
}


void Broker :: TraziDionicePoNazivu (const std::string& naziv)
{
    auto listptr = _dionice.traziPoNazivu(naziv);
    if (listptr != nullptr)
    {
      auto it = listptr -> begin();
      while (it != listptr -> end())
      {
        auto dionica = _dionice.nadjiPoId(*it);
        std::cout<<"------------------------\n";
        std::cout<<"Naziv :"<<dionica -> getNaziv()<<std::endl;
        std::cout<<"Sifra :"<<dionica -> getSifra()<<std::endl;
        std::cout<<"Cijena:"<<dionica -> getCijena()<<std::endl;
        std::cout<<"Ukupan broj dionica :"<<dionica->getUkupno()<<std::endl;
        std::cout<<"Broj slobodnih dionica :"<<dionica->getPreostalo()<<std::endl;
        std::cout<<"\nDionice na trzistu, u vlasnistvu korisnika:"<<std::endl;

        auto korisniciptr = _veze.nadjiKorisnike(*it);
        if(korisniciptr != nullptr)
        {
          auto itIdKor = korisniciptr -> begin();
         while(itIdKor != korisniciptr -> end())
         {
            auto korisnik = _korisnici.nadjiPoId(*itIdKor);
            auto veza = _veze.nadjiVezu(*it,*itIdKor);
            if (veza == nullptr)
            { 
              std::cout<<"//\n";
              break;
            }
            std::cout<<"\tVlasnik : "<<korisnik->getPrezime()<<" "<<korisnik ->getIme()<<std::endl;
            std::cout<<"\tNa prodaju:\n\t\t"<<veza -> getProdaja()<<std::endl;
            ++itIdKor;
            std::cout<<"............................\n";
         } 
        }
        std::cout<<"------------------------\n";
        ++it;
      }
    }
    else
    {
      std::cout<<"Dionica nije pronađena\n";
    }

}
void Broker::ispisiKorisnika(const Kljuc<std::string>* kljuc)
{
  auto l = kljuc -> getListaId();
  if(l == nullptr)
  {
    return;
  }

  auto it = l->begin();
  while(it != l -> end())
  {
    auto pok = _korisnici.nadjiPoId(*it);
    ispisiKorisnika(pok);
    ++it;
  }
}

void Broker :: IspisiKorisnikePoImenu ()
{
  ispisiKorisnike(_korisnici.getPoImenu().getRoot());
}

void Broker :: IspisiKorisnikePoPrezimenu()
{
  ispisiKorisnike(_korisnici.getPoPrezimenu().getRoot());
}
void Broker :: IspisiKorisnikePoId()
{
  ispisiKorisnike(_korisnici.getKorisnici().getRoot());
}

template <typename U>
void Broker :: ispisiKorisnike(U root)
{
  if (root == nullptr)
  {
    return;
  }
  if(root -> _left != nullptr)
  {
    ispisiKorisnike(root -> _left);
  }

  ispisiKorisnika(&(root -> info));

  if(root -> _right != nullptr)
  {
    ispisiKorisnike(root -> _right);
  }
}

template <typename U>
void Broker :: IspisiDionice(U root)
{
  if(root -> _left != nullptr)
  {
    IspisiDionice(root -> _left);
  }

  ispisiDionicu(&(root -> info));

  if(root -> _right != nullptr)
  {
    IspisiDionice(root -> _right);
  }
}

void Broker :: IspisiDionicePoId ()
{
  IspisiDionice(_dionice.getDionice().getRoot());
}
void Broker :: IspisiDionicePoNazivu()
{
  IspisiDionice(_dionice.getPoNazivu().getRoot());
}

void Broker :: ispisiDionicu (const  Dionica* dionica )
{
    int idd = dionica->getId();
    std::cout<<"------------------------\n";
    std::cout<<"ID    : "<<idd<<std::endl;
    std::cout<<"Naziv : "<<dionica->getNaziv()<<std::endl;
    std::cout<<"Sifra : "<<dionica->getSifra()<<std::endl;
    std::cout<<"Cijena: "<<dionica->getCijena()<<std::endl;
    std::cout<<"Ukupan broj dionica : "<<dionica->getUkupno()<<std::endl;
    std::cout<<"Broj slobodnih dionica :"<<dionica->getPreostalo()<<std::endl;
    std::cout<<"\nDionice na trzistu u vlasnistvu korisnika:\n";
      auto korptr = _veze.nadjiKorisnike(idd);
      if(korptr == nullptr)
      {
        std::cout<<"//\n";
        return;
      }
      auto itk = korptr -> begin();
      while(itk != korptr -> end())
      {
        auto vezaptr = _veze.nadjiVezu(idd,*itk);
        if(vezaptr ==nullptr)
        {
          ++itk;
          break;
        }
        auto korisnik=_korisnici.nadjiPoId(*itk);
        std::cout<<"ID :"<<*itk<<" - "<<korisnik->getIme()<<" "<<korisnik->getPrezime()<<std::endl;
        std::cout<<"Na prodaju: "<<vezaptr->getProdaja()<<" dionica"<<std::endl;
      ++itk;
      }
    std::cout<<"------------------------\n";
}

void Broker :: ispisiDionicu(const Kljuc<std::string>* kljuc)
{
  auto l = kljuc->getListaId();
  if(l == nullptr)
  {
    return;
  }
  auto it = l -> begin();
  while (it != l -> end())
  {
    auto dio = _dionice.nadjiPoId(*it);
    if(dio != nullptr)
    {
      ispisiDionicu(dio);
    }
    ++it;
  } 

}

#endif
