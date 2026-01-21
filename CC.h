#ifndef SDDS_CC_H
#define SDDS_CC_H

#include <iostream>

namespace sdds {

   class CC {
      char* name;
      unsigned long long number;
      short cvv;
      short expMonth;
      short expYear;

      void copyName(const char* src);
      void clear();
      bool valid(const char* name,unsigned long long number,short cvv,short month,short year)const;
      void printNumber(unsigned long long num) const;
      void printLine(const char* name,unsigned long long number,short year,short month,short cvv) const;

   public:
      CC();
      CC(const char* name,
         unsigned long long number,
         short cvv,
         short month = 12,
         short year = 26);
      ~CC();

      void set();
      void set(const char* name,unsigned long long number,short cvv,short month,short year);
      bool isEmpty() const;
      void display() const;
   };

}

#endif
