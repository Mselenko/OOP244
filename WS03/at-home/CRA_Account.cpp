/**********************************************************
// Workshop 3: Classes and Privacy
// w3_at_home.cpp
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

		int ck_sin[9] = { 0 };
		int b = 1; int c = 0;
		int sum_ev[4] = { 0 };
		int sum_odd[4] = { 0 };
		int total = 0;
		bool valid = true;
		for (int i = 8; i != -1; i--) {
			if (i == 8)
				ck_sin[i] = sin % 10;
			else
				b *= 10;
			c = sin / b;
			ck_sin[i] = c % 10;
		}
		for (int i = 0; i < 4; i++) {
			sum_ev[i] = ck_sin[(i * 2) + 1] * 2;
			total += sum_ev[i] / 10;
			total += sum_ev[i] % 10;
			sum_odd[i] = ck_sin[i * 2];
			total += sum_odd[i];
		}
		if (((total + ck_sin[8]) % 10) != 0)
			valid = false;

		if (sin > max_sin || sin < min_sin || valid == false || familyName[0] == '\0' || givenName[0] == '\0') {
			m_sin = 0;
			strcpy(name, "");
			strcpy(ac_name, "");
		}
		else {
			m_sin = sin;
			strcpy(name, familyName);
			strcpy(ac_name, givenName);
			m_year = 0;
		}
	}
	
	void CRA_Account::set(int year, double balance) {
       if (m_sin != 0 && m_year < max_yrs) {
                m_tax[m_year] = year;
				m_balance[m_year] = balance;
				m_year++;
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
			
			for (int i = 0; i < max_yrs; i++) {
				if (m_balance[i] > 2)
					cout << "Year (" << m_tax[i] << ") balance owing: " << m_balance[i] << endl;
				else if (m_balance[i] < -2)
					cout << "Year (" << m_tax[i] << ") refund due: " << m_balance[i] * -1  << endl;
				else
					cout << "Year (" << m_tax[i] << ") No balance or refund due!" << endl;
			}
		}
	}

}
