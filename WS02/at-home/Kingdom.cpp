/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 2/3/18
// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/


#include <iostream>
#include "Kingdom.h"
using namespace std;
// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...)
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
