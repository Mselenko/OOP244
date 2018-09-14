
// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict {

	class Passenger {
		char m_name[32];
		char m_dest[32];
		int m_year;
		int m_month;
		int m_day;
	public:
		Passenger();
		Passenger(const char*, const char*);
		Passenger(const char*, const char*, int, int, int);
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
		void display() const;

	};
}
#endif
