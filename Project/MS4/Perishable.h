// Date 4/13/18
// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca

#ifndef AMA_PERISHABLE__H
#define AMA_PERISHABLE__H

#include <iostream>
#include "Product.h"
#include "iProduct.h"
#include "Date.h"

namespace AMA {

	class Perishable : public Product {
		Date m_date;

	public:
		Perishable();
		std::fstream& store(std::fstream&, bool newLine = true) const;
		std::fstream& load(std::fstream&);
		std::ostream& write(std::ostream&, bool) const;
		std::istream& read(std::istream&);
		const Date& expiry() const;
	};
};

#endif