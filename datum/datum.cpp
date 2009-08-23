/****************** datum.cpp **************************/
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "datum.h"
#include "datumformat.h"
using namespace std;

Datum::Datum(DatumFormat *f)
{
	if(f==NULL)
	{
		throw "Es muss ein Datums Format mitgegeben werden";
	}
	_time = new struct tm;
	_df=f;

	//Standart werte schreiben
	_day = 1;
	_month = 1;
	_year = 1970;
	settime(_day, _month, _year);
}

Datum::~Datum()
{
        delete _time;
}

void Datum::setFormat(DatumFormat *d)
{
	if(d==NULL)
	{
		throw "Es muss ein Datums Format mitgegeben werden";
	}
	_df=d;
}
string Datum::toString()
{
	return _df->format(this);
}

void Datum::settime(int day, int mon, int year)
{
        //und eimal _time neu generieren        
        _time->tm_year = year - 1900;
        _time->tm_mon =  mon - 1;
        _time->tm_mday = day;
        _time->tm_hour=1;
        _time->tm_min=0;
        _time->tm_sec=0;
        _time->tm_isdst=0;
        mktime(_time);
}

void Datum::setDatum(int day, int mon, int year)
{
	if(day>31 || day<1)
                throw "Dieser Tag ist kein gueltiger Tag";

	if(mon>12 || mon<1)
                throw "Dieser Monat ist kein gueltiger Monat";
	
	if(year<1900 || year>2032)
                throw "Es werden nur Daten zwischen 1900 und 2032 akzeptiert";
   
	_day = day;
	_month = mon;
   	_year = year;

	settime(_day, _month, _year);
}

int Datum::getDayInYear()
{
	return _time->tm_yday;
}

int Datum::getDayInMonth()
{
	return _day;
}

int Datum::getWeekInYear()
{
	char buffer[5];
	strftime(buffer,5,"%U",_time);
	return atoi(buffer);
}

int Datum::getMonth()
{
	return _month;
}

int Datum::getYear()
{
	return _year;
}

bool Datum::isLeapYear()
{
        if(_year%4==0 && !(_year%100==0 && _year%400!=0))
                return true;
        return false;
}

long Datum::diff(Datum *d) 
{
	double dif = 2123213;

        dif = difftime(mktime(this->_time),mktime(d->_time));
        return (long)(dif/60/60/24);
}

