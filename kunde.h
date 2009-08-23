#include <string>
using namespace std;


class Kunde {
	private:
		string _name;
		string _vorname;
		int _alter;
		int _anzahl;
		bool _hatcd;
		
	public:
		Kunde(string name, string vorname, int alter)
		{
			_name = name;
			_vorname = vorname;
			_alter = alter;
		}
		~Kunde();
		
		string getName()
		{
			return _name;
		}
		
		string getVorname()
		{
			return _vorname;
		}
		
		int getAlter()
		{
			return _alter;
		}
		
		void leihtCD()
		{
			_anzahl++;
			if (_anzahl >= 1)
				_hatcd = 1;
		}
		
		void gibtCD()
		{
			_anzahl--;
			if (_anzahl == 0)
				_hatcd = 0;
		}
};
