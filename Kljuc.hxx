#ifndef _kljuc_hxx_
#define _kljuc_hxx_

#include <iostream>
#include "sortirana_lista.hxx"


using namespace std;
template<typename T>
class Kljuc
{
	private:
	T _kljuc;
	sortiranaLista<int> listaId;
		
	public:
	void ispisiId() const;
	void dodajId(int);
	
  Kljuc()=default;
	Kljuc(const T& key,int a):_kljuc(key){dodajId(a);}
	
	const T getKljuc() { return _kljuc;}
	void setKljuc(const T& key) {_kljuc = key;}	
	
  const sortiranaLista<int>& getListaId (); 
	
	 bool operator > ( const Kljuc& b) const 
	 {
	   return _kljuc > b._kljuc;
	   
	 }
	
	  bool operator < ( const Kljuc& b) const 
	 {
	   return _kljuc < b._kljuc;
	   
	 }
	 
	 bool operator == ( const Kljuc& b) const 
	 {
	   return _kljuc == b._kljuc;
	   
	 }
	 
	 bool operator != ( const Kljuc& b) const 
	 {
	   return _kljuc != b._kljuc;
	   
	 }
	
};

template <typename T>
const sortiranaLista<int>& Kljuc<T>::getListaId ()
{
  return listaId;
}

template <typename T>
void Kljuc<T>::ispisiId() const
{
	listaId.print();
}

template <typename T>
void Kljuc<T>::dodajId(int Id) 
{
	listaId.insert(Id);
}

#endif
