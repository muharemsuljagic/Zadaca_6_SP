#ifndef BST_HXX
#define BST_HXX
#include<iostream>
#include"binarySearchTree.hxx"

template <typename T>
class BstId : public BstStablo<T>
{
  public:
  T& searchEl (const  T& src);
  int searchId (const int& srcID);
  T& insertEl (const T& el);
};
template <typename T>
T& BstId<T>::insertEl (const T& el)
{
  binaryTreeNode<T> * curNode=this->root;
  binaryTreeNode<T> * tail;
  binaryTreeNode<T> * newNode = new binaryTreeNode<T> (el);
  if(curNode==nullptr)
  {
    this->root=newNode;
    return this->root->info;
  }
  
  while(curNode != nullptr)
  {
    tail=curNode;
    if(curNode->info == el)
    {
      std::cout<<"Element alredy in list\n";
      delete newNode;
      return curNode->info;
    }
    if(curNode->info > el)
      curNode=curNode->llink;
    else
      curNode=curNode->rlink;
  }
    if(tail->info > el)
      tail->llink = newNode;
    else
      tail->rlink = newNode;
    return newNode->info;
}
template <typename T>
T& BstId<T>::searchEl (const T& src)
{
  binaryTreeNode<T> * curNode = this->root;

  if (curNode == nullptr)
    throw std::string("Tree is empty");

  while(curNode != nullptr)
  {
    if(curNode->info == src)
      return curNode->info;
    else if (curNode->info > src)
      curNode = curNode -> llink;
    else 
    curNode=curNode -> rlink;  
  }
  std::cout<<"Element is not in list"<<std::endl;
  throw std::string("Element is not in list\n");
}
template <typename T>
int BstId<T>::searchId (const int& srcID)
{
  binaryTreeNode<T> * curNode = this->root;

  if (curNode == nullptr)
    return -1;
  while(curNode != nullptr)
  {
    if(curNode->info == srcID)
      return curNode->info.getId();
    else if (curNode->info > srcID)
      curNode = curNode -> llink;
    else 
    curNode=curNode -> rlink;  
  }
  return -1;
}

#endif
