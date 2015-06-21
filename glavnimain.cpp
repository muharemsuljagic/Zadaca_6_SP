#include<iostream>
#include "pomocni_main.hxx"
#include "admin.hxx"
#include "broker.hxx"
using namespace std;

void s(int n)
{
	while(n)
	{
			cout<<"\n";
			--n;
	}
}

int main()
{		
		Broker _kuca;
		Admin a;

		int sw=-1;
		while(sw!=0)
		{
			switch(sw=pocetna())
					{
						case 1:
							{	
									s(2);
									cout<<"Prijava. " << endl;
									cout << "- - - - - - - - - - - - - - - - - - - " << endl;
									//cout<<"Prijava. " << endl;
									string acc,pw;
									cout << "Account: ";
									cin >> acc;
									cout <<"Password: ";
									cin >> pw;
									cout << "- - - - - - - - - - - - - - - - - - - " << endl;
									bool check = a.CheckAdmin(acc,pw);
									if(check)
											{	
												s(2);
												cout <<"\n";
												//cout << "- - - - - - - - - - - - - - - - - - - " << endl;
												//cout << " Admin. \n";
												int bw=-1;
												while(bw!=0)
													{	
														switch(bw=admin())
														{
															case 1:
																{
																		// Dodaj korisnika
																		string jmbg,ime,prezime,adresa,email,broj;
																		double balans;
																		s(4);
																		cout<<"Unesite podatke o novom korisniku: \n";
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		cout<<"Jmbg: ";
																		cin >>jmbg;
																		cout<<"Ime: ";
																		cin >>ime;
																		cout<<"Prezime: ";
																		cin >>prezime;
																		cout<<"Balans: ";
																		cin >> balans;
																		cout<<"Adresa stanovanja: ";
																		cin.ignore();
																		getline(cin,adresa);
																		cout<<"eMail: ";
																		cin >>email;
																		cout<<"Broj telefona: ";
																		cin >> broj;
																		Korisnik temp(jmbg,ime,prezime,balans,adresa,email,broj);
																		_kuca.DodajKorisnika(temp);
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		cout <<"Uspješno ste dodali korisnika.\n";
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		s(4);
																		break;
																}
															case 2:
																{
																		// Dodaj Dionicu
																		string sifra,naziv;
																		double cijena;
																		int ukupno;
																		s(4);
																		cout<<"Unesite podatke o dionici: \n";
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		cout <<"Naziv: ";
																		cin >> naziv;
																		cout <<"Šifra: ";
																		cin >> sifra;
																		cout <<"Cijena: ";
																		cin >> cijena;
																		cout <<"Ukupan broj dionica: ";
																		cin >>ukupno;
																		Dionica temp(sifra,naziv,cijena,ukupno);
																		_kuca.DodajDionicu(temp);
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		cout <<"Uspješno ste dodali dionicu.\n";
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		s(4);
																		break;
																		
																}
															case 3:
																{
																		//Kupi dionicu
																		s(2);
																		int cw=-1;
																		while(cw!=0)
																		{
																			switch(cw=kupovina())
																			{
																				case 1:
																				{																		
																					int idD,idK,idP;
																					cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
																					cout <<"Unesite ID dionice koju kupujete: ";
																					cin >> idD;
																					cout <<"Unesite ID korisnika koji traženu dionicu: ";
																					cin >>idP;
																					cout <<"Unesite ID korisnika koji kupuje traženu dionicu: ";
																					cin >>idK;
																					cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
																					s(2);
																					_kuca.kupiDionicu(idD,idK,idP);
																					s(3);
																					break;
																				}
																				case 2:
																				{
																						int idD,idK;
																						cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
																						cout <<"Unesite ID dionice koju kupujete: ";
																						cin >> idD;
																						cout <<"Unesite ID korisnika koji kupuje traženu dionicu: ";
																						cin >> idK;
																						cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
																						s(2);
																						_kuca.kupiDionicu(idD,idK);
																						s(3);
																						break;
																				}
																				case 0:
																					{
																						break;
																					}
																			}
																		}
																	break;
																		
																	}
															case 4:
																{
																		//Stavi dionicu na prodaju
																		s(2);
																		int idK,idD;
																		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
																		cout <<"Unesite ID korisnika koji želi prodati dionicu: ";
																		cin >>idK;
																		cout <<"Unesite ID dionice koju korisnik prodaje: ";
																		cin >> idD;
																		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
																		_kuca.staviNaProdaju(idK,idD);
																		break;
																}
															case 5:
																{
																		//Ispisi korisnik po Id
																		s(2);
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		_kuca.IspisiKorisnikePoId();
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		s(3);
																		break;
																		
																}
															case 6:
																{
																		//Ispisi korisnike po imenu
																		s(2);
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		_kuca.IspisiKorisnikePoImenu();
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		s(3);
																		break;
																}
															case 7:
																{
																		//Ispisi korisnike po prezimenu
																		s(2);
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		_kuca.IspisiKorisnikePoPrezimenu();
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		s(3);
																		break;
																}
															case 8:
																{
																		//Ispisi dionice po Id
																		s(2);
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		_kuca.IspisiDionicePoId();
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		s(3);
																		break;
																}
															case 9:
																{
																		//Ispisi dionice po nazivu
																		s(2);
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		_kuca.IspisiDionicePoNazivu();
																		cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																		s(3);
																		break;
																}
															case 10:
																{
																		//Trazi korisnike po imenu
																		s(2);
																		string ime;
																		cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
																		cout <<"Unesite ime korisnika kojeg tražite: ";
																		cin >> ime;
																		cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
																		s(2);
																		_kuca.TraziKorisnikePoImenu(ime);
																		s(3);
																		break;
																}
															case 11:
																{
																		//Trazi korisnike prezimenu
																		s(2);
																		string prezime;
																		cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
																		cout <<"Unesite prezime korisnika kojeg tražite: ";
																		cin >> prezime;
																		cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
																		s(2);
																		_kuca.TraziKorisnikePoPrezimenu(prezime);
																		s(3);
																		break;
																}
															case 12:
																{
																		//Trazi dionice po nazivu
																		s(2);
																		string ime;
																		cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
																		cout <<"Unesite ime dionice koju tražite: ";
																		cout << "- - - - - - - - - - - - - - - - - - - - " << endl;
																		cin >> ime;
																		s(2);
																		_kuca.TraziDionicePoNazivu(ime);
																		s(3);
																		break;
																}
															case 13:
																{
																		//Ucitaj iz fajla
																		s(2);
																		_kuca.UcitajIzFajla();
																		cout <<"Ucitavanje iz fajla je izvršeno. \n";
																		s(2);
																		break;
																}
															case 14:
																{
																		//Upisi u fajl
																		_kuca.PisiUFajl();
																		s(2);
																		cout<<"Upisivanje u fajl je izvršeno. \n";
																		s(2);
																		break;
																}
															case 0:
																{
																	break;
																}
																cout << "- - - - - - - - - - - - - - - - - - - " << endl;
																s(4);
														}
													}
												break;
											}
									 else
										{
											s(2);
											cout <<"\n";
											cout << "- - - - - - - - - - - - - - - - - - - " << endl;
											cout <<"Unijeli ste pogrešan account ili password.\nMolimo pokušajte ponovo.\n";
											cout << "- - - - - - - - - - - - - - - - - - - " << endl;
											s(2);
											}
											break;
										}
									
							
							case 0:
							{		
									s(2);
									cout<<"\n";
									cout << "- - - - - - - - - - - - - - - - - - - " << endl;
									cout <<"Ugodan dan i doviđenja. \n";
									cout << "- - - - - - - - - - - - - - - - - - - " << endl;
									//cout << "- - - - - - - - - - - - - - - - - - - " << endl;
									break;
							}
					}}	

		return 0;
}
