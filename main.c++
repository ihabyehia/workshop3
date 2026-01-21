#include <iostream>
#include "CC.h"
using namespace std;
using namespace sdds;

int main() {
   CC card1;
   CC card2("John Smith",4000123412341234ull,123,10,26);
   CC card3("Bad",123,12,20,10);
   card1.display();
   card2.display();
   card3.display();

   return 0;
}
