// Final Project Milestone 1
//
// Version 1.0
// Date 4/13/18
// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Date.h"

namespace AMA {

	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}


	void Date::errCode(int errorCode) {
		error = errorCode;
	}

	int Date::errCode() const {
		return error;
	}

	bool Date::bad() const {
		if (error != NO_ERROR)
			return true;
		else
			return false;
	}

	Date::Date() {
		m_year = 0;
		m_month = 0;
		m_day = 0;
		error = NO_ERROR;
		m_comp = 0;
	}

	Date::Date(int year, int month, int day) {
		Date temp;
		int monDays = mdays(month, year);
		bool x = false;
		if (year > max_year || year < min_year) {
			*this = temp;
			errCode(YEAR_ERROR);
		}
		else if (month < 1 || month >12) {
			*this = temp;
			errCode(MON_ERROR);
		}
		else if (day > monDays || day < 1) {
			*this = temp;
			errCode(DAY_ERROR);
		}
		else {
			x = true;
		}

		if (x) {
			m_day = day;
			m_month = month;
			m_year = year;
			errCode(NO_ERROR);
			m_comp = year * 372 + month * 13 + day;
		}
		else {
			//*this = temp;
			m_comp = 0;
		}
	}

	bool Date::operator==(const Date& rhs) const {
		bool notvalid = ((m_day == 0 || m_month == 0 || m_year == 0) || (rhs.m_day == 0 || rhs.m_month == 0 || rhs.m_year == 0));
		if (!notvalid) {
			if (rhs.m_day == m_day || rhs.m_month == m_month || rhs.m_year == m_year)
				return true;
			else
				return false;
		}
		else {
			return false;
		}
	}


	bool Date::operator!=(const Date& rhs) const {
		bool notvalid = ((m_day == 0 || m_month == 0 || m_year == 0) || (rhs.m_day == 0 || rhs.m_month == 0 || rhs.m_year == 0));
		if (!notvalid) {
			if (rhs.m_day != m_day || rhs.m_month != m_month || rhs.m_year != m_year)
				return true;
			else
				return false;
		}
		else {
			return false;
		}
	}


	bool Date::operator<(const Date& rhs) const {
		bool notvalid = ((m_day == 0 || m_month == 0 || m_year == 0) || (rhs.m_day == 0 || rhs.m_month == 0 || rhs.m_year == 0));
		if (!notvalid) {
			if (m_day < rhs.m_day || m_month < rhs.m_month || m_year < rhs.m_year)
				return true;
			else
				return false;
		}
		else {
			return false;
		}
	}

	bool Date::operator>(const Date& rhs) const {
		bool notvalid = ((m_day == 0 || m_month == 0 || m_year == 0) || (rhs.m_day == 0 || rhs.m_month == 0 || rhs.m_year == 0));
		if (!notvalid) {
			if (m_day > rhs.m_day || m_month > rhs.m_month || m_year > rhs.m_year)
				return true;
			else
				return false;
		}
		else {
			return false;
		}
	}

	bool Date::operator<=(const Date& rhs) const {
		bool notvalid = ((m_day == 0 || m_month == 0 || m_year == 0) || (rhs.m_day == 0 || rhs.m_month == 0 || rhs.m_year == 0));
		if (!notvalid) {
			if (m_day <= rhs.m_day || m_month <= rhs.m_month || m_year <= rhs.m_year)
				return true;
			else
				return false;
		}
		else {
			return false;
		}
	}
	bool Date::operator >=(const Date& rhs) const {
		bool notvalid = ((m_day == 0 || m_month == 0 || m_year == 0) || (rhs.m_day == 0 || rhs.m_month == 0 || rhs.m_year == 0));
		if (!notvalid) {
			if (m_day >= rhs.m_day || m_month >= rhs.m_month || m_year >= rhs.m_year)
				return true;
			else
				return false;
		}
		else {
			return false;
		}
	}

	std::istream& Date::read(std::istream& istr) {
		char slash;
		bool valid = false;
		istr >> m_year;
		if (istr.fail())
			valid = true;
		istr >> slash;
		istr >> m_month;
		if (istr.fail())
			valid = true;
		istr >> slash;
		istr >> m_day;
		if (istr.fail())
			valid= true;
		if (valid) {
			Date temp;
			*this = temp;
			errCode(CIN_FAILED);
		}
		else {
			Date temp(m_year, m_month, m_day);
			*this = temp;
		};
		return istr;
	};
		
	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << m_year << "/";
		ostr.width(2);
		ostr.fill('0');
		ostr << m_month << "/";
		ostr.width(2);
		ostr.fill('0');
		ostr << m_day;
		return ostr;
	}


	std::istream& operator>>(std::istream& is, Date& d) {
		d.read(is);
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const Date& d) {
		d.write(os);
		return os;
	}
}
