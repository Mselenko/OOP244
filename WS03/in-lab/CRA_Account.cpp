/**********************************************************
// Workshop 3: Classes and Privacy
// w3_in_lab.cpp
// Version 2.1
// 2017/09/09
// Chris Szalwinski
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions

// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca
// Revision History
///////////////////////////////////////////////////////////
// Name                 Date                                     Reason
// Chris        2018/01/23            allow longer names
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;
namespace sict {



	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		if (sin > max_sin || sin < min_sin) {
			m_sin = 0;
			strcpy(name, "");
			strcpy(ac_name, "");
		}
		else {
			m_sin = sin;
			strcpy(name, familyName);
			strcpy(ac_name, givenName);
		}
	}
	bool CRA_Account::isEmpty() const {
		return m_sin == 0;
	}
	void CRA_Account::display() const {
		if (m_sin == 0) {
			cout << "Account object is empty!" << endl;
		}
		else {
			cout << "Family Name: " << name << endl;
			cout << "Given Name : " << ac_name << endl;
			cout << "CRA Account: " << m_sin << endl;
		}
	}

}
