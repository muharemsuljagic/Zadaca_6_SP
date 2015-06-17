#include"bst2.hxx"
#include"korisnikDionica.hxx"
#include <iostream>
#include <fstream>
using namespace std;
class bstKorsnikDionica {

private:
	binTree<korisnikDionica> niz;

public:
     
       void upisiUfajl(korisnikDionica korisnik);
       void ucitajIZfajla();
       binTree<korisnikDionica> getBST(){ return niz;} 

		

}; 

void bstKorsnikDionica::ucitajIZfajla(){
        ifstream file;
	int temp;
        int i=0;
	ifstream fin("file.txt");
	if(fin.is_open()){
		korisnikDionica korisnik;
while(!fin.eof()){
						
fin.get(temp);

if(i==0){korisnik.setIDkorisnik(temp); i++;}
if(i==1){korisnik.setIDdionice(temp); i++;}
if(i==2){korisnik.setBrojDionica(temp);i++;}
if(i==3){korisnik.setProdaja(temp); i=0; niz.pushKorisnik(korisnik);}
}


void bstKorisnikDionica::upisiUfajl(korisnikDionica korisnik){
  ofstream myfile
  myfile.open ("file.txt");
  myfile <<korisnik.getIDkorisnik()>>"/n";
  myfile <<korisnik.getIDdionice()>>"/n";
  myfile <<korisnik.getBrojDionica()>>"/n";
  myfile <<korisnik.getProdaja()>>"/n";
  myfile.close();
}
