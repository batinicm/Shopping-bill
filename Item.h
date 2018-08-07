#ifndef _STAVKA_
#define _STAVKA_

#include "Element.h"
#include <iomanip>
#include <string>

class Item : public Element {
private:
	string name;
	double unitPrice;
	double amount;
public:
	Item(string i, double j, double am) :name(i) { unitPrice = j; amount = am; }
	double TotalPrice() const override {
		return amount*unitPrice;
	}
	Item* copy()const override { return new Item(*this); }
	void Write(ostream& it) const override {
		it << name << '[' << unitPrice << ',' <<amount << ','<< TotalPrice() << ']';
	}
};



#endif
