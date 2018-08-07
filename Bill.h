#ifndef _RAC_
#define _RAC_

#include "Item.h"
#include "Collection.h"
#include <string>

class Bill {
private:
	string shopper;
	long date;
	Collection<Element> items;
public:
	Bill(string i, long d, int cap = 10) : items(cap), shopper(i), date(d) {}
	Bill& Add(Element& s) { items.Add(s.copy()); return *this; }
	double TotValue() const;
	friend ostream& operator<<(ostream& it, const Bill& r){
		it << "Bill: " << r.shopper << ", date: " << r.date << " bought: " << endl;
		it << r.items << r.TotValue() << endl;
		return it;
	}
};


#endif