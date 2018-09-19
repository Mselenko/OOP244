// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables
		int m_numerator;
		int m_denominator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
	    bool operator!=(const Fraction& rhs) const;
	    Fraction& operator+=(const Fraction& rhs);
		
	};
}
#endif
