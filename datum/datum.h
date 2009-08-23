/****************** datum.h **************************/
#ifndef _DATUM_H_                                      
#define _DATUM_H_                                      
#include <string>
using namespace std;

class DatumFormat;

class Datum {
	private:
		int _day, _month, _year;
		struct tm * _time;
		DatumFormat * _df;
		void settime(int day, int mon, int year);

	public:
		Datum(DatumFormat *f);
		~Datum();
		int getDayInYear();
		int getDayInMonth();
		int getWeekInYear();
		int getMonth();
		int getYear();
		bool isLeapYear();
		long diff(Datum *d);
		string toString();
		void setFormat(DatumFormat *f);
		void setDatum(int day, int mon, int year);

};
#endif
