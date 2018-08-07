#ifndef _ELEM_
#define _ELEM_

#include <iostream>
using namespace std;


class Element {
private:
	virtual void Write(ostream& it) const = 0;
	friend ostream& operator<<(ostream& it, const Element& e) {
		e.Write(it);
		return it;
	}
public:
	virtual ~Element(){}
	virtual double TotalPrice() const = 0;
	virtual Element* copy() const = 0;
};

#endif
