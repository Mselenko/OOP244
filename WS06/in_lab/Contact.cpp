// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca
#include <iostream>
#include <cstring>
#include "Contact.h"


namespace sict {

    Contact::Contact() {
	m_name[0] = '\0';
	m_phone = nullptr;
	m_number = 0;
    };


    Contact::Contact(const char* name, const long long* phone, int num) {
	int i, j = 0;
	if (name != nullptr&& name[0] != '\0') {
	    strncpy(m_name, name, 20);
	    m_name[19] = '\0';
	    m_phone = new long long[num];
	    m_number= 0;
	    for (i = 0; i < num; i++) {
		if (!(phone[i] < 9999999999 || phone[i] > 9999999999990)) {
		    m_phone[j] = phone[i];
		    m_number++;
		    j++;
		};
	    };
	}
	else {
	   *this = Contact();
	};
    };


    Contact::~Contact() {
	delete[] m_phone;
    };


    void Contact::display() const {
	int i = 0;
	if (!isEmpty()) {
	    std::cout << m_name << std::endl;
	    for (i = 0; i <m_number; i++) {
		int number[12];
		digits(m_phone[i], number);
		if (m_phone[i] >= 10000000000 && m_phone[i] <= 999999999999) {
		   if (number[0] > 0)
		      std::cout << "(+" << number[0] << number[1] << ") " << number[2] << number[3] << number[4] << " " << number[5]
		      << number[6] << number[7] << "-" << number[8] << number[9] << number[10] << number[11] << std::endl;
		   else
		      std::cout << "(+" << number[1] << ") " << number[2] << number[3] << number[4] << " " << number[5]
		      << number[6] << number[7] << "-" << number[8] << number[9] << number[10] << number[11] << std::endl;
		}
	    }
	    }
	else
	    std::cout << "Empty contact!" << std::endl;
    };

    void digits(const long long number, int *numb_array) {
       long long modulus = number;
       long long b = 10000000000;
       if (number >= 10000000000 && number <= 99999999999)
       {
	  numb_array[0] = 0;
	  for (int i = 1; i < 12; i++)
	  {
	     numb_array[i] = modulus / b;
	     modulus = modulus % b;
	     b = b / 10;
	  }
       }
       else if (number >= 100000000000 && number <= 999999999999)
       {
	  for (int i = 1; i < 12; i++) {
	  numb_array[i] = modulus / b;
	  modulus = modulus % b;
	  b = b / 10;
       }
    }
    };

    bool Contact::isEmpty() const {
	return (m_name[0] == '\0');
    };
};
