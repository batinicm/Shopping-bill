#ifndef _ZBIRKA_
#define _ZBIRKA_

#include <iostream>
#include "Errors.h"
using namespace std;

template<typename T>
class Collection {
	T**arr;
	int cap, num;
	void copy(const Collection& z);
	void del();
	void move(Collection& z) {
		arr = z.arr;
		num = z.num;
		cap = z.cap;
		z.arr = nullptr;
	}
public:
	Collection(int k = 10) {
		arr = new T*[cap = k];
		num = 0;
	}
	Collection(const Collection& z) { copy(z); }
	Collection(Collection&& z) { move(z); }
	Collection& operator= (const Collection& z) {
		if (this != &z) { del(); copy(z); }
		return *this;
	}
	Collection& operator= (Collection&& z) {
		if (this != &z) { del(); move(z); }
		return *this;
	}
	Collection& Add(T& t) {
		if (num == cap) throw Err_Full();
		arr[num++] = new T(t); 
		return *this;
	}
	Collection& Add(T* t) {
		if (num == cap) throw Err_Full();
		arr[num++] = t; 
		return *this;
	}
	T& operator[](int x) {
		if (x >= num) throw Err_Nonexistent();
		return *arr[x];
	}
	const T& operator[](int x) const {
		return const_cast<Collection&>(*this)[x]; 
	}
	int NumOfEls() const { return num; }
	template <class U>
	friend ostream& operator<<(ostream& it, const Collection<U>& z);
};


template<typename T>
void Collection<T>::copy(const Collection&z) {
	arr = new T*[cap = z.cap];
	num = z.num;
	for (int i = 0; i < num; i++) arr[i] = new T(*z.arr[i]);
}

template<typename T>
void Collection<T>::del() {
	for (int i = 0; i< num; i++) delete arr[i];
		delete[]arr;
		arr = nullptr;
		cap = num = 0;
}

template<class U>
ostream& operator<<(ostream& it, const Collection<U>& z) {
	for (int i = 0; i <z.NumOfEls(); i++) it<< z[i] << endl; 
	return it;
}

#endif
