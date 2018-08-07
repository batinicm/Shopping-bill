#include "Bill.h"

double Bill::TotValue() const
{
	double s = 0;
	for (int i = 0; i < items.NumOfEls(); i++) s += items[i].TotalPrice();
	return s;
}

