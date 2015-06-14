#ifndef _bstkljuc_hxx_
#define _bstkljuc_hxx_


#include "bst2.hxx"
#include <iostream>
#include "Kljuc.hxx"


template<typename T>
class bstkljuc : public binTree<Kljuc<T>>
{
	public:
		
	void push(const T&,int);	
  const sortiranaLista<int>* findByKey(const T& el)const;  
};

template <typename T>
const sortiranaLista<int>* bstkljuc<T> :: findByKey(const T& el)const
{
  typename bstkljuc<T> :: Node* cur = this -> _root;
  

  while(cur != nullptr)
  {
    if ((cur->info).getKljuc() == el)
      return &((cur->info).getListaId());
    if ((cur->info).getKljuc() < el)
      cur = cur -> _right;
    else
      cur = cur -> _left;
  }
  return nullptr;
}

template <typename T>
void bstkljuc<T>::push (const T& el,int id)
{


  if (this->empty())
  {
   Kljuc<T> temp(el,id);
   this-> _root=new typename bstkljuc<T>::Node(temp);
    ++ this-> _size;
    return;
    
  }
  
  typename bstkljuc<T>::Node* curNode =this-> _root;
  typename bstkljuc<T>::Node*  prevNode;
  
  while (curNode != nullptr)
  {
    prevNode = curNode;
    if((curNode->info).getKljuc() == el)
    {
      //ako nadje korisnika sa istim imenom, samo doda  ID u listuId.
      curNode->info.dodajId(id);      
      return ;    
    }

    if((curNode->info).getKljuc() < el)
      curNode=curNode->_right;
    else
      curNode=curNode->_left;
  }

  Kljuc<T> temp(el,id);
  typename bstkljuc<T>::Node * newnd = new  typename bstkljuc<T>::Node(temp);
  if((prevNode->info).getKljuc() < el)
    prevNode->_right=newnd;
  else
    prevNode->_left = newnd;
  
  ++this->_size;
}
#endif
