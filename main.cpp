#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "compactdisc.h"
#include "kunde.h"
#include "dictionary.h"
#include "ausgeliehen.h"
#include "datum/datum.h"
#include "datum/datumformat.h"
#include "datum/datumformatde.h"
#include "datum/datumformaten.h"
using namespace std;


void mainmenu()
{
	cout << "+--------------------+" << endl;
	cout << "| Hauptmenü	     |" << endl;
	cout << "+--------------------+" << endl;
	cout << endl;
	cout << " (1) Daten aus einer Datei einlesen" << endl;
	cout << " (2) Daten in einer Datei abspeichern" << endl;
	cout << " (3) Stammdaten ändern" << endl;
	cout << " (4) CD verleihen" << endl;
	cout << " (5) CD zurücknehmen (inkl. Rechnung erstellen)" << endl;
	cout << " (6) CD suchen und Status anzeigen" << endl;
	cout << endl;
	cout << " (7) Programm beenden" << endl;
	cout << "---------------------------------------" << endl;
	cout << " Ihre Auswahl? ";	
}

void submenu()
{
	cout << "+--------------------+" << endl;
	cout << "|Stammdaten pflegen: |" << endl;
	cout << "+--------------------+" << endl;
	cout << endl;
	cout << " (1) neue CD in den Katalog aufnehmen" << endl;
	cout << " (2) alte CD aus dem Katalog entfernen" << endl;
	cout << " (3) neuen Kunden aufnehmen" << endl;
	cout << " (4) alten Kunden entfernen" << endl;
	cout << " (5) Kundendaten ändern" << endl;
	cout << endl;
	cout << " (6) Abbruch" << endl;
	cout << "---------------------------------------" << endl;
	cout << " Ihre Auswahl? ";
}
void go_sub(Dictionary<string> customerlist, Dictionary<string> cdlist)
{
	bool looper = true;
	int choose;
	while(looper)
	{
		int key;
		string value;
		submenu();
		cin >> choose;
		if (choose > 6 || choose <= 0)
		{
			cout << "Mehr als sechs auswahl möglichkeiten gibts nicht du ..." << endl;
			continue;
		}
			switch(choose)
		{
		case 1:
			//CD hinzufügen!
			cout << "geben sie die CD-Nummer ein!" << endl;
			cin >> key;
			cout << "geben sie den CD-Titel ein!" << endl;
			cin >> value;
			try{
				cdlist.add(key, value);
			}
			catch(char const* e){
				cout << e << endl;
			}
			break;
		case 2:
			//CD löschen!
			cout << "geben sie einen Key ein!" << endl;
			cin >> key;
			try{
				cdlist.deleteElement(key);
			}
			catch(char const* e){
				cout << e << endl;
			}
			break;
		case 3:
			//Kunden hinzufügen!
			cout << "geben sie eine Kundennummer ein!" << endl;
			cin >> key;
			cout << "geben sie ein Namen ein!" << endl;
			cin >> value;
			try{
				customerlist.add(key, value);
			}
				catch(char const* e){
				cout << e << endl;
			}
			break;
		case 4:
			//Kunden löschen!
			cout << "geben sie die Kundenummer ein!" << endl;
			cin >> key;
			try{
				customerlist.deleteElement(key);
			}
				catch(char const* e){
				cout << e << endl;
			}
			break;
		case 5:
			//Kunden ändern!
			cout << "Sorry, not here yet" << endl;
			break;
		case 6:
			//Abbrechen!
			cout << "Abbruch" << endl;
			looper = false;
			break;
		}
	}
}

int main()
{	
	Dictionary<string> customerlist;
	Dictionary<string> cdlist;
	
	bool looper = true;
	bool liste1_leer = true;
	bool liste2_leer = true;
	string value;
	int key;
	int choose;
	while(looper)
	{
		mainmenu();
		cin >> choose;
	       	if (choose > 7 || choose <= 0)
		{
			cout << "Mehr als sieben auswahl möglichkeiten gibts nicht du ..." << endl;
			continue;
		}

		switch(choose)
		{
			case 1:
				{
					//Datei auslesen!
					char buffer[512];
					ifstream file("test.txt");
					if(file.is_open()){
						
					}
					else{
						cout << "ERROR: konnte Datei nicht oeffnen" << endl;
					}
				}
				break;
			case 2:
				{ 
					//CDs in Datei speichern!
					ofstream file("cds.txt");
					if(file.is_open()){
						try{
							value = cdlist.first();
							file << value << endl;
							liste1_leer = false;
						}
						catch(char const*e)
						{
							cout << e << endl;
						}
						while(!liste1_leer){
							try{ 
								value = cdlist.next();
								file << value << endl;
							}
							catch(char const* e){
								liste1_leer = true;
								break;
							}
						}
					}
					else{
						cout << "ERROR: konnte Datei nicht oeffnen" << endl;
					}
				}
				{ 
					//Kunden in Datei speichern!
					ofstream file("kunden.txt");
					if(file.is_open()){
						try{
							value = customerlist.first();
							file << value << endl;
							liste2_leer = false;
						}
						catch(char const*e)
						{
							cout << e << endl;
						}
						while(!liste2_leer){
							try{ 
								value = customerlist.next();
								file << value << endl;
							}
							catch(char const* e){
								liste2_leer = true;
								break;
							}
						}
					}
					else{
						cout << "ERROR: konnte Datei nicht oeffnen" << endl;
					}
				}
				break;
			case 3:
				//Stammdaten ändern!
				go_sub(customerlist, cdlist);
				break;
			case 4:
				//CD ausleihen!
				cout << "CD ausleihen" << endl;
				break;
			case 5:
				//CD zurückbringen!
				cout << "CD zurückbringen" << endl;
				break;
			case 6:
				//CD suchen
				cout << "CD suchen" << endl;
				break;
			case 7:
				//Programm beenden!
				cout << "I hope you have saved, now its too late :-)" << endl;
				looper = false;
				break;
		}
	}
	return 0;
}	
