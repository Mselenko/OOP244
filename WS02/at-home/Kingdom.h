/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 2/3/18
// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H
// TODO: sict namespace
namespace sict {

	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[32];
		int m_population;
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(Kingdom &kingdom);
	void display(const Kingdom* k, int);
}
#endif

