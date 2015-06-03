
#include <iostream>
#include "ConjAcotado.h"
#include <list>

using namespace std;

int main() {

    ConjAcotado c(10);
    c.agregar(3);
  for(auto it = c.begin(); it != c.end(); ++it)
     std::cout << *it;

   if(c.pertenece(3)) {
     c.eliminar(3);
    }



  return 0;
}
