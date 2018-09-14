
#include <iostream>
#include "Kingdom.h"
using namespace std;

namespace sict {
	void display(Kingdom &kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
	void display(const Kingdom* k, int count) {
		int i;
		int total = 0;
		cout << "------------------------------" << endl
			<< "Kingdoms are" << endl
			<< "------------------------------" << endl;
			for (i = 0; i < count; i++) {
					cout <<i+1 <<". " << k[i].m_name << ", population " << k[i].m_population << endl;
				total += k[i].m_population;
			}
			    cout << "------------------------------" << endl
					 << "Total population of all Kingdoms: " << total << endl
				 << "------------------------------" << endl;
	}
}
