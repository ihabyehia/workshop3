#include <iostream>
#include "CC.h"
#include "cstr.h"

using namespace std;

namespace sdds {

   void CC::set() {
      clear();
      number = 0;
      cvv = 0;
      expMonth = 0;
      expYear = 0;
   }

   bool CC::isEmpty() const {
      if (name == nullptr)
         return true;
      else
         return false;
   }

   void CC::copyName(const char* src) {
      int len = strLen(src);
      name = new char[len+1];
      strCpy(name,src);
   }

   void CC::clear() {
      delete[] name;
      name = nullptr;
   }

   bool CC::valid(const char* name,unsigned long long number,short cvv,short month,short year) const {
      if (name == nullptr){
         return false;
      }
      if (strLen(name) < 3){
         return false;
      }
      if (number < 4000000000000000ull){
         return false;
      }
      if (number > 4099999999999999ull){
         return false;
      }
      if (cvv < 100){
         return false;
      }
      if (cvv > 999){
         return false;
      }
      if (month < 1){
         return false;
      }
      if (month > 12){
         return false;
      }
      if (year < 24){
         return false;
      }
      if (year > 32){
         return false;
    }
      return true;
   }

   void CC::set(const char* name,unsigned long long number,short cvv,short month,short year) {
      set();
      if (valid(name, number, cvv, month, year)) {
         copyName(name);
         this->number = number;
         this->cvv = cvv;
         expMonth = month;
         expYear = year;
      }
   }

   void CC::printNumber(unsigned long long num) const {
      cout<<num/1000000000000ull << " ";
      num=num%1000000000000ull;

      cout<<num/100000000ull << " ";
      num =num % 100000000ull;

      cout<<num /10000ull << " ";
      cout<<num% 10000ull;
   }

   void CC::printLine(const char* name,unsigned long long number, short year,short month,short cvv) const {
      char temp[31];
      strcpy(temp,name,30);
      cout<< "| ";
      cout.width(30);
      cout.setf(ios::left);
      cout <<temp<< " | ";

      printNumber(number);

      cout<<" | "<<cvv<< " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << month << "/" << year << " |" << endl;
      cout.unsetf(ios::right);
   }

   void CC::display() const {
      if (isEmpty()) {
         cout <<"Invalid Credit Card Record" << endl;
      } else {
         printLine(name,number,expYear,expMonth,cvv);
      }
   }

   CC::CC() {
      name=nullptr;
      set();
   }

   CC::CC(const char* name,unsigned long long number,short cvv,short month,short year) {
      this->name= nullptr;
      set(name,number,cvv,month,year);
   }

   CC::~CC() {
      clear();
   }

}