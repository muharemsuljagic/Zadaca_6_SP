#ifndef BINTREEID_HXX
#define BINTREEID_HXX

#include <iostream>
#include "bst2.hxx"

template <typename T> 
class binTreeId : public binTree<T>
{
  public :

   T* searchId (const int& id)
   {
     if (this->_root == nullptr)
       return nullptr;

     typename binTreeId :: Node * current = this->_root;
     
     while(current != nullptr)
     {
       if((current->info).getId()==id)
         return &(current->info);
       if((current->info).getId() < id)
        current=current-> _right;
       else
        current = current -> _left; 
     }
     return nullptr;
   }
};

#endif
