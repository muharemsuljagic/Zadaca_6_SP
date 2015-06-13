#ifndef _LISTA_ZADATAK_2_H_
#define _LISTA_ZADATAK_2_H_
#include<stdexcept>

using namespace std;

template <class TY>
class Cvor
{

	private:
		TY info;
		Cvor* link;
	public:
		TY& getInfo() {return info;}
		Cvor* getLink() {return link;}
		void setInfo(TY T) {info=T;}
		void setLink(Cvor* L) {link=L;}
};


template <typename Type>
class linkedListType{
	public:
		const linkedListType<Type>& operator=(const linkedListType<Type>&);
		void initializeList();
		bool isEmptyList() const;
		void print() const;
		int length() const;
		void destroyList();
		Type front() const;
		Type back() const;
		virtual bool search(const Type& searchItem) const = 0;
		virtual void insertFirst(const Type& newItem) = 0;
		virtual void insertLast(const Type& newItem) = 0;
		virtual void deleteNode(const Type& deleteItem) = 0;
		linkedListType();
		linkedListType(const linkedListType<Type>& otherList);
		~linkedListType();		
    class Iterator;   
    
    Iterator begin()const;
    Iterator end()const;
    template<typename U, typename V>
    Iterator searchIt(const V& el, U f)
    {
      
      auto it=begin();
      while(it != end())
      {
        if(f(*it,el))
          return it;
        it++;
      }
      return end();
    }
    

	protected:
		int count; //varijabla za pohranu veličine liste
		Cvor<Type> *first; //pokazivač na prvi čvor u listi
		Cvor<Type> *last; //pokazivač na posljednji čvor u listi

	private:	
		void copyList(const linkedListType<Type>& otherList);
};

template<typename Type>
typename linkedListType<Type>::Iterator linkedListType<Type>::begin()const

{
     linkedListType<Type>::Iterator a (this->first);
     return a;
}
template<typename Type>
typename linkedListType<Type>::Iterator linkedListType<Type>::end()const{
     linkedListType<Type>::Iterator a (nullptr);
     return a;
}

template <typename Type>

bool linkedListType<Type>::isEmptyList() const
{
	return (first == nullptr);//lista je prazna ako je first nullptr
}

template <class Type>
linkedListType<Type>::linkedListType() //default konstruktor : rezultat first i last imaju vrijednost nullptr, a veličina je 0
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
	Cvor<Type> *temp; //pokazivač pomoću kojeg ćemo obrisati čvor

	while (first != nullptr)//dok ima čvorova u listi
	{
		temp = first;//postavi temp na trenutni čvor
		first = (*first).getLink(); //preusmjeri first na naredni čvor
		delete temp;//dealociraj memoriju zauzetu čvorom
	}

	last = nullptr; //postavi last na nullptr jer smo ispraznili listu, first je već postavljen u petlji
	count = 0;//postavi veličinu na 0 jer smo ispraznili listu
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //obriši sve čvorove iz liste
}

template <class Type>
void linkedListType<Type>::print() const
{
	Cvor<Type> *current; //pokazivač za prolazak kroz listu
	current = first; //kreni od prvog čvora

	while (current != nullptr) //dok ima elemenata
	{
		cout << (*current).getInfo();//ispiši info dio
		current = (*current).getLink();//pomjeri pokazivač na naredni čvor
	}
}//end print

template <class Type>
int linkedListType<Type>::length() const
{
	return count;//vrati veličinu liste
}

template <class Type>
Type linkedListType<Type>::front() const
{
	if(first==nullptr) throw string("There are no elements in list!");
	else return (*first).getInfo(); //ako lista nije prazna, vrati info dio prvog čvora
}//end front

template <class Type>
Type linkedListType<Type>::back() const
{

	if(last==nullptr) throw string("There are no elements in list!");
	return (*last).getInfo(); //ako lista nije prazna, vrati info dio zadnjeg čvora
}//end back


template <class Type>
void linkedListType<Type>::copyList (const linkedListType<Type>& otherList)
{
	Cvor<Type> *newNode; //pointer to create a node
	Cvor<Type> *current; //pokazivač za prolazak kroz listu
	if (first != nullptr) //ako lista nije prazna, isprazni je
		destroyList();
	if (otherList.first == nullptr) //ako je druga lista prazna, i rezultujuća treba da bude
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	else
	{
		current = otherList.first; //current pokazuje na listu iz koje kopiramo elemente, trenutno na njen prvi čvor
		count = otherList.count; //postavi veličinu rezultujuće liste 
		first = new Cvor<Type>; //kreiraj novi čvor i postavi first da pokazuje na taj čvor
		(*first).setInfo((*current).getInfo()); //kopiraj info dio
		(*first).setLink(nullptr); //postavi link dio na nullptr
		last = first; //postavi last da pokazuje na prvi čvor (novi čvor)
		current = (*current).getLink(); //pomjeri current na drugi čvor u proslijeđenoj listi
		//kopiraj ostatak liste
		while (current != nullptr) //dok ima elemenata u proslijeđenoj listi
		{
			newNode = new Cvor<Type>; //kreiraj novi čvor 
			(*newNode).setInfo((*current).getInfo()); //kopiraj info
			(*newNode).setLink(nullptr); //postavi link dio na nullptr
			(*last).setLink(newNode); //ubaci novi čvor poslije posljednjeg čvora u listi
			last = newNode; //postavi last da pokazuje na stvarni zadnji čvor (novi čvor)
			current = (*current).getLink();//pomjeri current na naredni čvor u proslijeđenoj listi

		}//end while
	}//end else
}//end copyList

template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
	destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
	first = nullptr;
	copyList(otherList);
}//end copy constructor

//overload operatora =
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
	if (this != &otherList) //izbjegni samokopiranje
	{
		copyList(otherList);
	}//end if
	return *this;
}

template <class Type>
class linkedListType<Type>::Iterator : public std::iterator<std::forward_iterator_tag, Type>
{
		public:
		Cvor<Type> * pok;

 		Iterator ():pok(nullptr){}
		Iterator (Cvor<Type> * p):pok(p){}
          
		Iterator& operator ++()
		      {
		        if(pok == nullptr)
		        throw std::out_of_range (std::string("Iterator out of range list"));

		        pok=pok->getLink();
        		return *this;
      			}

			 Iterator operator ++(int)
		      {
			        if(pok == nullptr)
			          throw std::out_of_range (std::string("Iterator out of range list"));
		        Iterator ret;
        		ret.pok=pok;
		        pok=pok->getLink();
		        return ret;
			      }

      bool operator >=(const Iterator& b)const
      {
      return pok>=b.pok;
      }
      bool operator <=(const Iterator& b)const
      {
      return pok<=b.pok;
      }
      bool operator <(const Iterator& b)const
      {
      return pok<b.pok;
      }
      bool operator >(const Iterator& b)const
      {
      return pok>b.pok;
      }
      bool operator !=(const Iterator& b)const
      {
      return pok != b.pok;
      }
      bool operator ==(const Iterator& b)const
      {
      return pok==b.pok;
      }
      const  Type& operator * () const
      {
        return (*pok).getInfo();
      }
      Type& operator * ()
      {
        return (*pok).getInfo();
      }
};
#endif

