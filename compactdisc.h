#include <string>
using namespace std;


class CD {
	private:
		string _titel;
		string _interpret;
		int _anzahllieder;
		int _laenge;
		bool _istausgeliehen;
		int _zustand;
		
	public:
		CD(string titel, string interpret, int anzahllieder, int laenge, int zustand)
		{	
			_titel = titel;
			_interpret = interpret;
			_anzahllieder = anzahllieder;
			_laenge = laenge;
			_zustand = zustand;
		};
		~CD();
		
		string getTitel(){
			return _titel;
		}
		
		string getInterpret(){
			return _interpret;
		}
		
		int getAnzahlLieder(){
			return _anzahllieder;
		}
		
		int getLaenge(){
			return _laenge;
		}
		
		void verleiheDisc(){
			_istausgeliehen = 1;
		}
		
		void gebezurueck(){
			_istausgeliehen = 0;
		}
};
