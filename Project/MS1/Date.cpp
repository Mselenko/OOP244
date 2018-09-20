// Final Project Milestone 1
//
// Version 1.0
// Date 3/14/18
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
	  int monDays = mdays(month, year);
	  bool x = false;
	  if (year > max_year || year < min_year) 
		   errCode(YEAR_ERROR); 
	  else if (month < 1 || month >12)
		  errCode(MON_ERROR);
	  else if (day > monDays || day < 1)
		  errCode(DAY_ERROR);
	  else
		  x = true;

	  if(x){
		  m_day = day;
		  m_month = month;
		  m_year = year;
		  errCode(NO_ERROR);
		  m_comp = year * 372 + month * 13 + day;
	  }
	  else {
		  *this = Date();
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
	  istr >> m_year >> slash >> m_month >> slash >> m_day;
	  int day = mdays(m_month, m_year);
	  if (m_year > max_year || m_year < min_year)
		  errCode(YEAR_ERROR);
	  else if (m_month < 1 || m_month >12)
		  errCode(MON_ERROR);
	  else if (m_day > day || m_day < 1)
		  errCode(DAY_ERROR);
	  else
		  errCode(NO_ERROR);
	 
	  if (istr.fail()) {
		  errCode(CIN_FAILED);
		  return istr;
	  }
	  else {
		  return istr;
	  }
	}

  std::ostream& Date::write(std::ostream& ostr) const {
	  /*ostr.width(4);
	  ostr.fill('0');*/
	  ostr << m_year << "/";
	  ostr.width(2);
	  ostr.fill('0');
	  ostr << m_month << "/";
	  ostr.width(2);
	  ostr.fill('0');
	  ostr << m_day << std::endl;
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
