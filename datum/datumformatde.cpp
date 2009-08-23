#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include "datumformatde.h"
#include "datumformat.h"
#include "datum.h"

DatumFormatDE::DatumFormatDE()
{
} 
DatumFormatDE::~DatumFormatDE()
{
}

string DatumFormatDE::format(Datum* datum)
{
	ostringstream temp;
	
	temp << datum->getDayInMonth() << "." << datum->getMonth() << "." << datum->getYear();
	
	return temp.str();
	
}
 
Datum DatumFormatDE::parse(string StringDatum)
{
	char buffer[15];
	int tag;
	int monat;
	int jahr;
		
	DatumFormatDE *deutsch = new DatumFormatDE;
	Datum temp((DatumFormat*) deutsch);

	strncpy(buffer, StringDatum.c_str(), 15);

	tag = atoi(strtok(buffer , "."));
	monat = atoi (strtok(NULL , "."));
	jahr = atoi(strtok(NULL , "."));
	
	temp.setDatum(tag, monat, jahr);

	return temp;
}
