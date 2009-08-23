#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include "datumformaten.h"
#include "datumformat.h"
#include "datum.h"


DatumFormatEN::DatumFormatEN()
{
} 
DatumFormatEN::~DatumFormatEN()
{
}

string DatumFormatEN::format(Datum* datum)
{
	ostringstream temp;
	
	temp << datum->getMonth() << "/" << datum->getDayInMonth() << "/" << datum->getYear();
	
	return temp.str();
	
}
 
Datum DatumFormatEN::parse(string StringDatum)
{
	char buffer[15];
	int tag;
	int monat;
	int jahr;
	
	DatumFormatEN *englisch = new DatumFormatEN;
	Datum temp((DatumFormat*) englisch);
	
	strncpy(buffer, StringDatum.c_str(), 15);

	monat = atoi(strtok(buffer , "."));
	tag = atoi(strtok(NULL , "."));
	jahr = atoi(strtok(NULL , "."));
	
	temp.setDatum(tag, monat, jahr);

	return temp;
}
