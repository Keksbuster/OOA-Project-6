/****************** dictionary.h **************************/
#include <iostream>
#include <sstream>
#include <iomanip>
#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
using namespace std;

template <typename T> 
class Dictionary {
	private:
		int * _keys;
		T * _values;
		int _position, _size, _last, _pusher;
		bool isFull();
		bool isEmpty();
		void increase();
		void decrease();
		int find(int key);
		
	public:
		Dictionary(int size=8);
		~Dictionary();
		T get(int key);
		void add(int key, T value);
		void deleteElement(int key);
		void pushElement(T value);
		T first();
		T next();
};

template <typename T> 
Dictionary<T>::Dictionary(int size) 
{
	_size = size;
	_keys = new int [_size];
	_values = new T [_size];
	_last = 0;
	_pusher = 0;
}

template <typename T> 
Dictionary<T>::~Dictionary()
{
	delete[] _keys;
	delete[] _values;
}

template <typename T> 
bool Dictionary<T>::isEmpty()
{
	return _last == 0;
}

template <typename T> 
bool Dictionary<T>::isFull()
{
	return _size == _last;
}

template <typename T> 
void Dictionary<T>::increase()
{
	_size *= 2;
	int * tmpk = new int [_size];
	T * tmpv = new T [_size];
	
	for(int i = 0; i < _size/2; i++)
	{
		tmpk[i] = _keys[i];
		tmpv[i] = _values[i];
	}
	delete[] _values;
	delete[] _keys;
	_keys = tmpk;
	_values = tmpv;
}

template <typename T> 
void Dictionary<T>::decrease()
{
	_size /= 2;
	int * tmpk = new int [_size];
	T * tmpv = new T [_size];
	
	for(int i = 0; i < _last-1; i++)
	{
		tmpk[i] = _keys[i];
		tmpv[i] = _values[i];
	}
	delete[] _values;
	delete[] _keys;
	_keys = tmpk;
	_values = tmpv;	
}

template <typename T> 
int Dictionary<T>::find(int key)
{
	for(int i = 0; i < _last; i++)
	{
		if(_keys[i] == key)
		{
			return i;
		}
	}
	return -1;
}

template <typename T> 
void Dictionary<T>::add(int key, T value)
{
	if(isFull())
		increase();
	int i = find(key);
	if(i > -1)
		throw "Element exist";
		
	_keys[_last] = key;
	_values[_last] = value;
	_last += 1;
}

template <typename T>
void Dictionary<T>::pushElement(T value)
{
	add(_pusher, value);
	_pusher++;
}

template <typename T> 
void Dictionary<T>::deleteElement(int key)
{
	if(isEmpty())
		throw "List empty";
	int j = find(key);
	if(j == -1)
		throw "Element does not exist";
	
	for(int i = j; i < _last; i++)
	{
		_keys[i] = _keys[i+1];
		_values[i] = _values[i+1];
	}
	_last -= 1;
	if(_last <= _size/4)
		decrease();
}

template <typename T> 
T Dictionary<T>::get(int key)
{
	if(isEmpty())
		throw "List empty";

	int i = find(key);
	if(i == -1)
		throw "Element not found";
	
	ostringstream tmp;
	
	tmp << _values[i];
	return tmp.str();
}

template <typename T> 
T Dictionary<T>::first()
{
	if(isEmpty())
		throw "List empty";
	ostringstream tmp;
	_position = 0;
	
	tmp << _keys[0] << " " << _values[0];
	return tmp.str();
}

template <typename T> 
T Dictionary<T>::next()
{
	_position += 1;
	if(_position >= _last)
		throw "No more elements";
	
	ostringstream tmp;
	
	tmp << _keys[_position] << " " << _values[_position];
	
	return tmp.str();
}

#endif
