// Date 3/21/18
// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca

#ifndef AMA_ERRORSTATE_H_
#define AMA_ERRORSTATE_H_

namespace AMA {

	class ErrorState {
		char* m_message;

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState&) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
		ErrorState& operator=(const ErrorState&) = delete;
		std::ostream& write(std::ostream& ostr) const;

	};

	std::ostream& operator<<(std::ostream& os, const ErrorState& err);

 }

#endif