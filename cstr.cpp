#include "cstr.h"

namespace sdds {

   int strLen(const char* str) {
      int i = 0;
      while (str[i]!='\0') {
         i++;
      }
      return i;
   }

   void strCpy(char* des, const char* src, int len) {
      int i = 0;
      if (len < 0) {
         while (src[i]!='\0') {
            des[i] = src[i];
            i++;
         }
      } else {
         while (i<len &&src[i] !='\0') {
            des[i] = src[i];
            i++;
         }
      }

      des[i] = '\0';
   }
}
