#ifndef _bstkljuc_hxx_
#define _bstkljuc_hxx_


#include "bst2.hxx"
#include <iostream>


using namespace std;

template<typename T>
class bstkljuc : public binTree<T>
{
	public:
		
	void push(const T&,int);
	
	
	
};

template <typename T>
void bstkljuc::push (const T& el,int id)
{

  if (empty())
  {
    _root=new typename binTree<T>::Node(el);
    ++ _size;
    return &(_root->info);
    
  }
  
  nd<T>* curNode=_root;
  nd<T>* prevNode;
  
  while (curNode != nullptr)
  {
    prevNode = curNode;
    if(curNode->info == el)
    {
      //ako nadje korisnika sa istim imenom, samo doda  ID u listuId.
      // curNode->info.dodajId(id);      
      return &(curNode->info);    
    }
    if(curNode->info < el)
      curNode=curNode->_right;
    else
      curNode=curNode->_left;
  }
  nd<T> * newnd = new nd<T>(el);
  if(prevNode->info < el)
    prevNode->_right=newnd;
  else
    prevNode->_left = newnd;
  ++_size;
  return &(newnd->info);
}

