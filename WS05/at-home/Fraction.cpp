// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca

#include <iostream>
#include"Fraction.h"
using namespace std;
// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		m_numerator = 0;
		m_denominator = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator) {
		if (numerator < 0 || denominator <= 0) {
			*this = Fraction();
		}
		else {
			m_numerator = numerator;
			m_denominator = denominator;
			reduce();
		}
	}
	// TODO: implement the max query
	int Fraction::max() const {
		return (m_denominator > m_numerator) ? m_denominator : m_numerator;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		return (m_denominator < m_numerator) ? m_denominator : m_numerator;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int a = gcd();
		m_denominator /= a;
		m_numerator /= a;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else {
			if (m_numerator % m_denominator == 0) {
				cout << m_numerator / m_denominator;
			}
			else {
				cout << m_numerator << "/" << m_denominator;
			}
		}
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool x = (m_denominator == 0) || (m_numerator == 0);
		return  x;
	}


	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction result;
		bool valid = (rhs.isEmpty() == true) && (this->isEmpty() == true);
		if (valid) {
			return result;
		}
		else {
			int x = (this->m_numerator * rhs.m_denominator) + (this->m_denominator * rhs.m_numerator);
			int y = this->m_denominator* rhs.m_denominator;
			result = Fraction(x, y);
		}
		return result;
	}

	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction result;
		bool valid = (rhs.isEmpty() == true) && (this->isEmpty() == true);
		if (valid) {
			return result;
		}
		else {
			int x = (this->m_numerator* rhs.m_numerator);
			int y = this->m_denominator* rhs.m_denominator;
			result = Fraction(x, y);
		}
		return result;
	}


	bool Fraction::operator==(const Fraction& rhs) const {
		bool valid = ((rhs.isEmpty() == true) && (this->isEmpty() == true) && (rhs.m_denominator != this->m_denominator) && (rhs.m_numerator != this->m_numerator));
		if (valid)
			return !valid;
		else
			return valid;
	}


	bool Fraction::operator!=(const Fraction& rhs) const {
		bool valid = ((rhs.isEmpty() == true) && (this->isEmpty() == true)); 
		if (!valid) {
			if (rhs.m_denominator != this->m_denominator && rhs.m_numerator != this->m_numerator)
				return valid;
			else
				return !valid;
		}
		else {
			return !valid;
		}
	}

	Fraction& Fraction::operator+=(const Fraction& rhs) {
	bool valid = ((rhs.isEmpty() == true) && (this->isEmpty() == true));
	if (!valid) {
		int x = (m_numerator * rhs.m_denominator) + (m_denominator * rhs.m_numerator);
		int y = m_denominator* rhs.m_denominator;
		*this = Fraction(x, y);

	 }
	return *this;
	}
}

