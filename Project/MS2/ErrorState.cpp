// Date 3/21/18
// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca


#include<iostream>
#include <cstring>
#include "ErrorState.h"
using namespace std;

namespace AMA {

 ErrorState::ErrorState(const char* errorMessage ) {
		if (errorMessage == nullptr) {
			m_message = nullptr;
		}
		else {
			m_message = nullptr;
			message(errorMessage);
		}
	}


	ErrorState:: ~ErrorState() {
		delete m_message;
	}

	void ErrorState::clear() {
			delete[] m_message;
			m_message = nullptr;
		
	}

	bool ErrorState::isClear() const {
		return m_message == nullptr;
	}

	void ErrorState::message(const char* str) {
		if(m_message != nullptr)
		clear();
		m_message = new char[strlen(str) + 1];
		strcpy(m_message, str);
	}

	const char* ErrorState::message()const {
		return m_message;
	}

	
	ostream& ErrorState::write(ostream& ostr) const {
		if (this->m_message != nullptr) {
			ostr << m_message;
			return ostr;
		}
		else {
			return ostr;
		}
	}

	ostream& operator<<(ostream& os, const ErrorState& err) {
		err.write(os);
		return os;
	}
}