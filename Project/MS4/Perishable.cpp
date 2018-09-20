// Date 4/13/18
// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca


#include <iostream>
#include"Perishable.h"


using namespace std;

namespace AMA {

	Perishable::Perishable(): Product('P'){
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {

		Product::store(file, false);
		file << ',';
		file << m_date;
		if (newLine)
			file << '\n';
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file) {
		Product::load(file);
		file.ignore();
		//std::istream& is = file;
		m_date.read(file);
		file.ignore();
		return file;

	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);
		if (Product::isClear()) {
			if (!linear) {
				os << " Expiry date: ";
			}
				m_date.write(os);    
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		Product::read(is);
		if (Product::isClear()) {

			cout << " Expiry date (YYYY/MM/DD): ";
			m_date.read(is);
		}

		switch (m_date.errCode()) {
		case CIN_FAILED:
			message("Invalid Date Entry");
			is.setstate(std::ios::failbit);
			break;
		case YEAR_ERROR:
			message("Invalid Year in Date Entry");
			is.setstate(std::ios::failbit);
			break;
		case MON_ERROR:
			message("Invalid Month in Date Entry");
			is.setstate(std::ios::failbit);
			break;
		case DAY_ERROR:
			message("Invalid Day in Date Entry");
			is.setstate(std::ios::failbit);
			break;
		}
		return is;
	}
	
	const Date& Perishable::expiry() const {
		return m_date;
	}

}