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
		int i = 0;
	if (name != nullptr && name[0] != '\0') {
	    strncpy(m_name, name, 20);
	    m_name[19] = '\0';
	    m_phone = new long long[num];
	    m_number= 0;
	    for (i = 0; i < num; i++) {
		if (!(phone[i] < 9999999999 || phone[i] > 9999999999999)) {
		    m_phone[i] = phone[i];
		    m_number++;
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
		int num_array [12];
		digits(m_phone[i], num_array);
		if (m_phone[i] >= 10000000000 && m_phone[i] <= 999999999999) {
		   if (num_array[0] > 0)
		      std::cout << "(+" << num_array[0] << num_array[1] << ") " << num_array[2] << num_array[3]
			  << num_array[4] << " " << num_array[5] << num_array[6] << num_array[7] << "-" << num_array[8] 
			  << num_array[9] << num_array[10] << num_array[11] << std::endl;
		   else
		      std::cout << "(+" << num_array[1] << ") " << num_array[2] << num_array[3] << num_array[4] << " " 
			  << num_array[5] << num_array[6] << num_array[7] << "-" << num_array[8] << num_array[9] << num_array[10] 
			  << num_array[11] << std::endl;
		}
	    }
	    }
	else
	    std::cout << "Empty contact!" << std::endl;
    };

    void Contact::digits( long long number, int *array) const {
       long long modulus = number;
       long long b = 10000000000;
       if (number >= 10000000000 && number <= 99999999999)
       {
	  array[0] = 0;
	  for (int i = 1; i < 12; i++)
	  {
	     array[i] = modulus / b;
	     modulus = modulus % b;
	     b = b / 10;
	  }
       }
       else if (number >= 100000000000 && number <= 999999999999)
       {
	  for (int i = 1; i < 12; i++) {
	  array[i] = modulus / b;
	  modulus = modulus % b;
	  b = b / 10;
       }
    }
    };

    bool Contact::isEmpty() const {
	return (m_name[0] == '\0');
    };

	Contact::Contact(const Contact& cont) {
		m_phone = nullptr;
		*this = cont;
	}
	
	Contact& Contact::operator=(const Contact& cont) {
		if (this != &cont) {
			m_number = cont.m_number;
			strncpy(m_name, cont.m_name, 20);
			m_name[19] = '\0';	
			if (cont.m_phone != nullptr && m_phone != nullptr) 
				delete[] m_phone;
				m_phone = new long long[cont.m_number];
				for (int i = 0; i < m_number; i++)
					m_phone[i] = cont.m_phone[i];
			}
			return *this;
			}
		
	
	Contact& Contact::operator+=(long long num) {
		if (!(num < 9999999999 || num > 9999999999999)) {
			long long* temp = new long long[m_number + 1];
			for (int i = 0; i < m_number; ++i)
				temp[i] = m_phone[i];
			delete[] m_phone;
			m_phone = temp;
			temp = nullptr;

			m_phone[m_number] = num;
			++m_number;
		};
		return *this;
	};

};

