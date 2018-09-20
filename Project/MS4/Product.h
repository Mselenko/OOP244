// Date 4/13/18
// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca


#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include "ErrorState.h"
#include "iProduct.h"


namespace AMA {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double taxes = 0.13;

	class Product: public iProduct {

		char m_type;
		char m_sku[max_sku_length];
		char m_unit[max_unit_length];
		char* m_name;
		int m_needs;
		int m_qty;
		double m_price;
		bool m_tax;
		ErrorState m_error;

	protected:
		void name(const char*);
		const char* name() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:
		Product(char type = 'N');
		Product(const char* sku, const char* name, const char* unit, int qty = 0, bool tax = true, double price = 0, int need = 0);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		bool isEmpty() const;
		double total_cost() const;
		void quantity(int);
		int quantity() const;
		int qtyNeeded() const;
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		int operator+=(int);
		bool operator==(const char*) const;
		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;


		const char* sku() const;
		const char* unit() const;
		double price() const;
		bool taxed() const;

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);



	};
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
}
#endif
