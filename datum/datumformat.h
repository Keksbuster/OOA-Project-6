#include <string>
#ifndef _DATUMFORMAT_H 
#define _DATUMFORMAT_H 
 
 
class Datum; 
using namespace std; 
 
class DatumFormat{ 
public: 
     DatumFormat(); 
     ~DatumFormat(); 
     virtual string format(Datum* Datum); 
     virtual Datum parse(string StringDatum);
};
#endif
