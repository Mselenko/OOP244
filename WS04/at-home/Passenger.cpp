// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca

#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;
namespace sict {
	Passenger::Passenger() {
		m_name[0] = '\0';
		m_dest[0] = '\0';
		m_year = 0;
		m_month = 0;
		m_day = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
		if (name == nullptr || destination == nullptr) {
			*this = Passenger();
		}
		else {
			strcpy(m_name, name);
			strcpy(m_dest, destination);
			m_year = 2017;
			m_month = 7;
			m_day = 1;
		}

	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool x = m_name[0] == '\0' || m_dest[0] == '\0';
		return  x;
	}

	Passenger::Passenger(const char* name, const char* destination, int year, int month, int day) {
		if (name == nullptr || destination == nullptr || year < 2017 || year > 2020 || month < 1 || month > 12 || day < 1 || day > 31) {
			*this = Passenger();
		}
		else {
			*this = Passenger(name, destination);

			m_year = year;
			m_month = month;
			m_day = day;
		}
	}
	const char* Passenger::name() const {
		return this->m_name;
	}
	bool Passenger::canTravelWith(const Passenger& pas) const {
		bool valid = strcmp(pas.m_dest, this->m_dest) == 0 && pas.m_year == this->m_year && pas.m_month == this->m_month && pas.m_day == this->m_day;
		return valid;
	}
	void Passenger::display() const {
		if (m_name[0] == '\0' || m_dest[0] == '\0') {
			cout << "No passenger!" << endl;
		}
		else {
			cout << this->m_name << " - " << this->m_dest << " on " << this->m_year << "/";
			cout.fill('0');
			cout.width(2);
			cout << this->m_month << "/" << this->m_day << endl;
		}
	}
}
