#ifndef bintree_hxx
#define bintree_hxx

#include<iostream>

template <typename T>
class binTree
{
 
    public:
  struct Node;
  
  binTree():_root(nullptr),_size(0){}
  binTree(const binTree&);
  binTree(binTree&&);
  binTree& operator = (const binTree&);
  binTree& operator = (binTree &&);
  ~binTree();
  const Node* getRoot() const {return _root;} 

  void freeTree();  
  const int& size(){return _size;}
  bool empty (){return _size==0;}
  void print()const;  
  T* push(const T&);
  void deleteNode(const T& );
  int numLeaf;    
    
    protected:
  
  void printTree (const Node* ) const;
  Node* copyTree(const Node * const &);  
  void destTree(Node*&);
  void deleteLeaf(Node* , Node*);   
  void deleteOneNpt(Node* , Node*);
  
  
  
  Node * _root;
  int _size;

};
template<typename T>
using nd=typename binTree<T>::Node;

template <typename T>
void binTree<T> :: freeTree ()
{
  destTree(_root);
  _size=0;
}


template <typename T>
void binTree<T> :: deleteNode (const T& el)
{
  if (empty())
    throw std::string("Tree is empty\n");
  bool f=false;
  nd<T> * Cur =_root;
  nd<T> * Prev=Cur;

  while(Cur != nullptr)
  {
   
    if(Cur->info == el)
    {
      f=true;
      break;
    }
    Prev=Cur;
    if(Cur->info < el)
      Cur = Cur -> _right;
    else
      Cur = Cur -> _left;
  }
  
  if(f==false)
    throw std::string ("Element is not in tree\n");
  
  if(Cur -> _left == nullptr && Cur -> _right == nullptr)
   deleteLeaf(Prev,Cur);
  else if(  ( Cur->_left ==nullptr && Cur -> _right != nullptr) || (Cur-> _left != nullptr && Cur -> _right == nullptr) )
    deleteOneNpt(Prev,Cur);

  else
  {
    nd<T> * Cur2 = Cur -> _left;
    Prev = Cur;
    while(Cur2 -> _right != nullptr){
      Prev=Cur2;
      Cur2 = Cur2 -> _right;
    }
    
    T temp;
    temp = Cur -> info;
    Cur -> info = Cur2 ->info;
    Cur2 -> info = temp;

    if(Cur2 -> _left == nullptr && Cur2 -> _right == nullptr)
     deleteLeaf(Prev,Cur2);
    else if(  ( Cur2 -> _left ==nullptr && Cur2 -> _right != nullptr) || (Cur2 -> _left != nullptr && Cur2 -> _right == nullptr) )
      deleteOneNpt(Prev,Cur2);
  }


}

template <typename T>
binTree<T>::~binTree()
{
  destTree(_root);
}
template <typename T>
T* binTree<T>::push (const T& el)
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
        return &(curNode->info);
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

template <typename T>
void binTree<T>::printTree(const binTree<T> :: Node*   root)const
{
  if(root==nullptr)
  {
    std::cout<<"NULL"<<std::endl;
    return;
  }
  std::cout<<root->info<<std::endl;
  binTree<T>::printTree(root->getLeft());
  binTree<T>::printTree(root->getRight());
}

template<typename T>
void binTree<T>::print()const
{
  binTree<T>::printTree(_root);
}

template <typename T>
typename binTree<T>::Node*  binTree<T>::copyTree (const binTree<T>::Node * const &  root)
{
  if(root==nullptr)
    return nullptr;
  
  typename binTree<T>::Node * ret =new typename binTree<T>::Node(root->info);
  ret->_left= binTree<T>::copyTree(root->getLeft());
  ret->_right= binTree<T>::copyTree(root->getRight());
  return ret;
}

template <typename T>
binTree<T>::binTree (const binTree<T> & el)
{
    _root=binTree<T>::copyTree(el._root);
    _size=el._size;  
}

template <typename T>
binTree<T>& binTree<T>::operator = (const binTree<T> & tree)
{
  if (this != & tree)
  {
    std::cout<<"DestTree"<<std::endl;
    destTree(_root);
    std::cout<<"copytree\n";
    _size=tree._size;
    _root=copyTree(tree._root);
  }

  return *this;
}

template <typename T>
binTree<T>::binTree (binTree<T>&& tree)
{
  _size=tree._size;
  _root=tree._root;
  tree._root=nullptr;
}

template < typename T >
binTree<T>& binTree<T> :: operator = ( binTree<T>&& tree)
{
  _size=tree._size;
  auto temp=tree._root;
  tree._root=_root;
  _root = temp;
  return *this;
}

template<typename T>
struct binTree<T>::Node
{ 
  public:
  T info;
  Node * _left;
  Node * _right;

  Node():_left(nullptr),_right(nullptr){}
  Node(const T& el):info(el),_left(nullptr),_right(nullptr){}
  Node(const T& el, const Node * &l, const Node * &r):info(el),_left(l),_right(r){}
  const Node* getLeft() const{return _left;} 
  const Node* getRight() const{return _right;}
};

template <typename T>
void binTree<T> :: destTree(binTree<T> :: Node* & root)
{
  if(root != nullptr)
  {
    if(root->_left != nullptr)
      destTree(root->_left);
    
    if(root->_right != nullptr)
      destTree(root->_right);
    
    delete root;
  }
}
template <typename T>
void binTree<T> :: deleteLeaf(binTree<T>::Node* parent,binTree<T>::Node * child)
{
  if(parent == child)
   _root = nullptr;
  else if (parent -> _left == child)
   parent -> _left = nullptr;
  else
   parent -> _right = nullptr;

 delete child; 
}

template <typename T>
void binTree<T> :: deleteOneNpt(binTree<T>::Node * parent, binTree<T>::Node * child)
{
 nd<T> * next;
 if(child -> _right == nullptr)
   next = child -> _left;
 else
   next = child -> _right;
 if(parent == child)
   _root = next;
 else if(parent -> _left == child )
   parent -> _left = next;
 else
   parent -> _right = next;
}
#endif
