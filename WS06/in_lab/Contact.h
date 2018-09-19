// Student Margarita Selenko
// Student id 147393169
// Student mail mselenko@myseneca.ca

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {
   class Contact {
      char m_name[21];
      long long *m_phone;
      int m_number;

   public:
      Contact();
      Contact(const char*, const long long*, int);
      ~Contact();
      bool isEmpty() const;
      void display() const;
   };
   void digits(const long long Number, int *numb_array);
}
#endif
