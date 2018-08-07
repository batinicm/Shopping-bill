#ifndef _GRESKE_
#define _GRESKE_

#include <iostream>
using namespace std;

class Err_Full {};

inline ostream& operator<<(ostream& it, const Err_Full&g) {
	it << "*** Collection full!***\n";
	return it;
}

class Err_Nonexistent {};

inline ostream& operator<<(ostream& it, const Err_Nonexistent&g) {
	it << "*** Invalid index!***\n";
	return it;
}


#endif
