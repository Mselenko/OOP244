// Date 4/13/18
// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca


#include <iostream>
#include <fstream>
#include <cstring>
#include "Product.h"


using namespace std;

namespace AMA {

	void Product::name(const char* name) {
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	const char* Product::name() const {
		return m_name;
	}

	double Product::cost() const {
		if (m_tax) {
			double a = m_price * (1 + taxes);
			return a;
		}
		else {
			return m_price;
		}
	}

	void Product::message(const char* error) {
		m_error.ErrorState::message(error);
	}

	bool Product::isClear() const {
		return m_error.isClear();
	}

	Product::Product(char type) {
		m_type = type;
		m_sku[0] = '\0';
		m_unit[0] = '\0';
		m_name = nullptr;
		m_qty = 0;
		m_price = 0;
		m_tax = true;
		m_needs = 0;
		ErrorState m_error;
	}

	Product::Product(const char* sku, const char* name, const char* unit, int qty, bool tax, double price, int need) {
		strcpy(m_sku, sku);
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		m_price = price;
		m_tax = tax;
		m_qty = qty;
		strcpy(m_unit, unit);
		m_needs = need;

	}
	Product::Product(const Product& prod) {

		strcpy(m_sku, prod.m_sku);
		strcpy(m_unit, prod.m_unit);
		m_price = prod.m_price;
		m_qty = prod.m_qty;
		m_tax = prod.m_tax;
		m_needs = prod.m_needs;


		if (prod.m_name != nullptr)
		{
			m_name = new char[strlen(prod.m_name) + 1];
			strcpy(m_name, prod.m_name);

		}
		else
		{
			m_name = nullptr;
		}
	}


	Product& Product::operator=(const Product& prod) {
		if (this != &prod && prod.isEmpty() != true)
		{
			strcpy(m_sku, prod.m_sku);
			m_price = prod.m_price;
			m_qty = prod.m_qty;
			m_tax = prod.m_tax;
			m_needs = prod.m_needs;
			strcpy(m_unit, prod.m_unit);

			delete[] m_name;
			if (prod.m_name != nullptr)
			{
				m_name = new char[strlen(prod.m_name) + 1];
				strcpy(m_name, prod.m_name);

			}
			else
			{
				m_name = nullptr;
			}
		}

		return *this;
	}

	Product::~Product() {
		delete[] m_name;
	}

	bool Product::isEmpty() const {
		return (m_name == nullptr || m_price == 0.0 || m_qty == 0 || m_sku[0] == 0);
	}

	double Product::total_cost() const {
		return (cost() * m_qty);
	}

	void Product::quantity(int qty) {
		m_qty = qty;
	}

	int Product::quantity() const {
		return m_qty;
	}
	int Product::qtyNeeded() const {
		return m_needs;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& pr) {
		pr.write(os, true);
		return os;
	}
	std::istream& operator>>(std::istream& is, iProduct& pr) {
		pr.read(is);
		return is;
	}

	double operator+=(double& num, const iProduct& prod) {
		return (num += prod.total_cost());
	}


	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (isClear()) {
			if (linear) {
				
				os.fill(' ');
				os.setf(std::ios::left);
				os.width(max_sku_length);
				os << m_sku << "|";
				os.width(20);
				os << m_name << "|";
				os.setf(std::ios::fixed);
				os.unsetf(std::ios::left);
				os.precision(2);
				os.width(7);

				
				
				os << cost() << "|";

				os.width(4);
				os << m_qty << "|";
				os.unsetf(std::ios::fixed);
				os.setf(std::ios::left);

				
				os.width(10);
				os << m_unit << "|";


				os.setf(std::ios::fixed);
				os.unsetf(std::ios::left);
				os.width(4);
				os << m_needs << "|";
				//os.unsetf(std::ios::right);
				return os;
			}
			else {
				os << " Sku: " << m_sku << std::endl;
				os << " Name (no spaces): " << m_name << std::endl;
				os << " Price: " << m_price << std::endl;
				os << " Price after tax: ";
				if (m_tax) {
					os << cost() << endl;
				}
				else {
					os << "N/A" << endl;
				}
				os << " Quantity on hand: " << m_qty << ' ' << m_unit << std::endl;
				os << " Quantity needed: " << m_needs; 
				cin.ignore();//<< endl;
			}

			}else {

			cout << m_error.message();
		}
		return os;
		}
	


	std::istream& Product::read(std::istream& is) {
		char t_name[max_name_length];
		Product temp;
		bool valid = true;
		char c_tax;
		cout << " Sku: ";
		is >> temp.m_sku;
		cout << " Name (no spaces): ";
		is >> t_name;
		delete[] temp.m_name;
		if (t_name != nullptr)
		{
			temp.m_name = new char[strlen(t_name) + 1];
			strcpy(temp.m_name, t_name);

		}
		else
		{
			temp.m_name = nullptr;
		}
		cout << " Unit: ";
		is >> temp.m_unit;
		//is.ignore(2000, '\n');
		cout << " Taxed? (y/n): ";
		is >> c_tax;
		if (is.fail() || (c_tax != 'y' && c_tax != 'n' && c_tax != 'Y' && c_tax != 'N')) {
			is.std::istream::setstate(std::ios::failbit);
			message("Only (Y)es or (N)o are acceptable");
			return is;
		}
		else if (c_tax == 'Y' || c_tax == 'y') {
			temp.m_tax = true;
		}
		else {
			temp.m_tax = false;
		}
		cout << " Price: ";
		is >> temp.m_price;
		if (is.fail()) {
			message("Invalid Price Entry");
			valid = false;
			return is;
		}
		cout << " Quantity on hand: ";
		is >> temp.m_qty;
		if (is.fail()) {
			message("Invalid Quantity Entry");
			valid = false;
			return is;
		}
		cout << " Quantity needed: ";
		is >> temp.m_needs;
		if (is.fail()) {
			message("Invalid Quantity Needed Entry");
			valid = false;
			return is;
		}
		if (valid) {
			//message(nullptr);
			m_error.clear();
			*this = temp;
		}
		return is;
	}

	int Product::operator+=(int unit) {
		if (unit > 0)
			return m_qty + unit;
		else
			return m_qty;
	}

	bool Product::operator==(const char* sku) const {
		if (strcmp(m_sku, sku) == 0)
			return true;
		else
			return false;

	}

	bool Product::operator>(const char* sku) const {
		if (strcmp(m_sku, sku) > 0)
			return true;
		else
			return false;
	}

	bool Product::operator>(const iProduct& prod) const {
		if (strcmp(m_name, prod.name()) > 0)
			return true;
		else
			return false;
	}
	const char* Product::sku() const {
		return m_sku;
	}
	const char* Product::unit() const {
		return m_unit;
	}
	double Product::price() const {
		return m_price;
	}
	bool Product::taxed() const {
		return m_tax;
	}


	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		file << m_type << ',' << m_sku << ',' << m_name << ',' << m_unit << ',' <<
			(taxed() ? 1 : 0) << ',' << m_price << ',' << m_qty << ',' <<
			m_needs;
		    if(newLine) file<<endl;
		return file;
	}


	std::fstream& Product::load(std::fstream& file) {
		char sku_[max_sku_length];
		char name[max_name_length];
		char unit[max_unit_length];
		int  quantity, qtyNeeded;
		double price_;
		bool taxed_;
		char type_;
		file.getline(sku_, max_sku_length, ',');
		file.getline(name, max_name_length, ',');
		file.getline(unit, max_unit_length, ',');
		file >> taxed_;
		file.ignore();
		file >> price_;
		file.ignore();
		file >> quantity;
		file.ignore();
		file >> qtyNeeded;
	 Product p(sku_, name, unit, quantity, taxed_ , price_, qtyNeeded);
	 *this= p;
		return file;
	}
}