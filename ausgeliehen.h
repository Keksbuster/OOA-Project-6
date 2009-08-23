#include <string>
#include "datum/datum.h"
#include "datum/datumformat.h"
#include "datum/datumformatde.h"
#include "datum/datumformaten.h"
using namespace std;


class Ausgeliehen {
	private:
		int _kundenID;
		int _CDID;
		Datum _startdatum;
		
	public:
		Ausgeliehen(int kundenID, int CDID, Datum startdatum){
			_kundenID = kundenID;
			_CDID = CDID;
			_startdatum = startdatum;
		}
		~Ausgeliehen();
		
		int getKundenID(){
			return _kundenID;
		}
		
		int getCDID(){
			return _CDID;
		}
		
		Datum getStartDatum(){
			return _startdatum;
		}		
};
