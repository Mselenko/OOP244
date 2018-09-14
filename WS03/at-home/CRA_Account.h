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


#ifndef SICT_CPA_ACCOUNT_H
#define SICT_CPA_ACCOUNT_H
#define SIZE 1000
namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {
		char name[SIZE];
		char ac_name[SIZE];
		int m_sin;
		int m_tax[max_yrs];
		double m_balance[max_yrs];
		int m_year;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isEmpty() const;
		void display() const;
	};
 }

#endif
