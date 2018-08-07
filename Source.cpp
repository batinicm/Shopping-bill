#include "Bill.h"

int main() {
	string name;
	long d;
	double c, kk;
	int k;
	while (true) {
			cout << " Enter shopper name: "; cin >> name;
			cout << " Enter today's date as ddmmyyyy: "; cin >> d;
			cout << " Number of items: "; cin >> k;
			Bill* Bil=new Bill(name, d, k);
			for (int j = 0; j < k; j++) {
				cout << " Item name: "; cin >> name;
				cout << " Price: "; cin >> c;
				cout << " Amount: "; cin >> kk;
				try {
					Bil->Add(Item(name, c, kk));
				}
				catch (Err_Full g) { cout << g; }
			}
			cout << " Your bill: " << *Bil;
			delete Bil;
		}
}