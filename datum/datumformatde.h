#ifndef _DATUMFORMATDE_H 
#define _DATUMFORMATDE_H 
 
#include <string> 
#include "datumformat.h"

class Datum; 
using namespace std; 
 
 
class DatumFormatDE: public DatumFormat
{
	public:
		DatumFormatDE(); 
		~DatumFormatDE(); 
		string format(Datum* Datum); 
		Datum parse(string StringDatum); 
};
#endif
