
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
