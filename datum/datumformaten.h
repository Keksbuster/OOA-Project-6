#ifndef _DATUMFORMATEN_H 
#define _DATUMFORMATEN_H 
 
#include <string> 
#include "datumformat.h"

class Datum; 
using namespace std; 
 
 
class DatumFormatEN: public DatumFormat
{
	public:
		DatumFormatEN(); 
		~DatumFormatEN(); 
		string format(Datum* Datum); 
		Datum parse(string StringDatum); 
};
#endif
