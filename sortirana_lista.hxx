#ifndef _SORTIRANA_LISTA_ZADATAK_2_H_
#define _SORTIRANA_LISTA_ZADATAK_2_H_

#include<iostream>
#include "lista_zadatak_2.hxx"
#include <stdexcept>

template <typename T>
class sortiranaLista : public linkedListType<T>
{
  public :
  virtual bool search(const T& searchItem) const;
  virtual void insertFirst(const T& newItem);
  virtual   void insertLast(const T& newItem);
  virtual void deleteNode(const T& deleteItem);
  virtual   void insert(const T& newItem); 
  typename sortiranaLista<T>::  Iterator  inserti (const T& newItem);

friend std::ostream& operator << (ostream& out,const sortiranaLista<T> & lista)
  {
    Cvor<T> * pom = lista.first;
    while(pom != nullptr)
    {
      out<<pom->getInfo()<<" ";
      pom=pom->getLink();
    }
    return out;
  }
};

template<typename T>
typename sortiranaLista<T>::Iterator sortiranaLista<T>::inserti (const T& newItem)
{
  if(this->isEmptyList())
  {
    this->first=new Cvor<T>;
    this->first->setInfo(newItem);
    this->first->setLink(nullptr);
    ++this->count;
    this->last=this->first;
    typename  sortiranaLista<T>::Iterator a(this->first); 
    return a;
  }
  Cvor<T> * pom=this->first;
  if(newItem< pom->getInfo())
  {
   this->first=new Cvor<T>;
   this->first->setInfo(newItem);
   this->first->setLink(pom);
   typename  sortiranaLista<T>::Iterator a(this->first); 
   return a;
 
  }
  Cvor<T> * rep=pom;
  pom=pom->getLink();
  while(pom!=nullptr)
  {
    if(newItem < (pom->getInfo()))
    {
      Cvor<T> * pok = new Cvor<T>;
      rep->setLink(pok);
      pok->setInfo(newItem);
      pok->setLink(pom);
      ++this->count;
      typename   sortiranaLista<T>::Iterator a(pok);
      return a;
    }
    
   rep=pom;
   pom=pom->getLink(); 
  }
  
  Cvor<T> * pok = new Cvor<T>;
  pok->setInfo(newItem);
  pok->setLink(nullptr);
  (this->last)->setLink(pok);
  this->last=pok;
  ++this->count;
  typename sortiranaLista<T>::Iterator d(pok);
  return d;
}

template <typename T>
bool sortiranaLista<T>::search (const T& searchItem)const
{
  Cvor<T> * pom=this->first;
  while (pom != nullptr)
  {
    if(pom->getInfo ()== searchItem)
      return true;
    pom=pom->getLink();
  } 

  return false;
}

template<typename T>
void sortiranaLista<T> :: insert (const T& newItem)
{
  if(this->isEmptyList())
  {
    this->first=new Cvor<T>;
    this->first->setInfo(newItem);
    this->first->setLink(nullptr);
    ++this->count;
    this->last=this->first;
    return; 
  }
  Cvor<T> * pom=this->first;

  while(pom!=nullptr)
  {
    if(newItem < (pom->getInfo()))
    {
      Cvor<T> * pok = new Cvor<T>;
      if(pom->getLink()==nullptr){
        this->last=pok;
        (this->last)->setLink(nullptr);
        }
      pok->setInfo(pom->getInfo());
      pok->setLink(pom->getLink());
       
      pom->setLink(pok);
      pom->setInfo(newItem);
      ++this->count;
      return;
    }

   pom=pom->getLink(); 
  }
  
  Cvor<T> * pok = new Cvor<T>;
  pok->setInfo(newItem);
  pok->setLink(nullptr);
  (this->last)->setLink(pok);
  this->last=pok;
  ++this->count;
  return;
}

template <typename T>
void sortiranaLista<T>::insertFirst (const T& newItem)
{
  insert(newItem);
}
template <typename T>
void sortiranaLista<T>::insertLast (const T& newItem)
{
  insert(newItem);
}

template <typename T>
void sortiranaLista<T> :: deleteNode (const T& deleteItem)
{
  if(this->isEmptyList())
  {
    std::cout<<"Lista je prazna"<<std::endl;
    return;
  }
  Cvor<T> * pom;
  Cvor<T> * pomNext=this->first;
  if(pomNext->getInfo() == deleteItem)
  {
    --this->count;
    if(this->last==pomNext)
      this->last=nullptr;
    this->first=pomNext->getLink();
    std::cout<<"Element izbrisan"<<std::endl;
    delete pomNext;
    return;
  }
  pom=pomNext;
  pomNext=pomNext->getLink();
  while(pomNext!=nullptr)
  {
    if(pomNext->getInfo()==deleteItem)
    {
      pom->setLink(pomNext->getLink());
      if(pomNext==this->last)
        this->last=pom;
      --(this->count);
      delete pomNext;
	std::cout<<"Element izbrisan"<<std::endl;	      
	return;
    }
    pom=pomNext;
    pomNext=pomNext->getLink();
  }
  
  std:: cout<<"Element se ne nalazi u listi"<<std::endl;
}

#endif
