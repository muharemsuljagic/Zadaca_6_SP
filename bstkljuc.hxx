#ifndef _bstkljuc_hxx_
#define _bstkljuc_hxx_


#include "bst2.hxx"
#include <iostream>
#include "kljuc.hxx"

using namespace std;

//template<typename T>
class bstkljuc : public binTree<Kljuc<string>>           //Kljuc<T>
{
	public:
		
	void push(const string&,int);                    // push(const T&,int)
	
	
	
};


//template <typename T>
void bstkljuc::push (const string& el,int id)
{

  if (empty())
  {
      Kljuc<string> temp(el,id);
    _root=new binTree<Kljuc<string>>::Node(temp);
    ++ _size;
    return &(_root->info);
    
  }
  
  binTree<Kljuc<string>>::Node* curNode=_root;     // binTree<Kljuc<T>>::Node
  binTree<Kljuc<string>>::Node* prevNode;           // binTree<Kljuc<T>>::Node
  
  while (curNode != nullptr)
  {
    prevNode = curNode;
    if(curNode->info == el)
    {
      //ako nadje korisnika sa istim imenom, samo doda  ID u listuId.
      curNode->info.dodajId(id);      
      return &(curNode->info);    
    }
    if(curNode->info < el)
      curNode=curNode->_right;
    else
      curNode=curNode->_left;
  }
  
  //Provjeriti ovaj dio.. 
  Kljuc<string> temp(el,id);
  binTree<Kljuc<string>>::Node* newnd = new binTree<Kljuc<string>>::Node(temp);  // binTree<Kljuc<T>>::Node
  if(prevNode->info < el)
    prevNode->_right=newnd;
  else
    prevNode->_left = newnd;
  ++_size;

}
*/
