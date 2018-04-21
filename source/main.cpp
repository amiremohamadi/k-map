/*
 * Simple k-map using c++
 * AMIR MOHAMMADI
 * Under GPL v3.0 License (general public license)
 */

#include <iostream>
#include "simplifier.h"
using namespace std;

int main(void)
{
  int a[4] = {1, 2, 3, 4};
  map m;
  m.parseToMap(a, 4);
  m.printMap();
  cout << "\n";

  simplifier s(m);
  
  s.run();
  // this is main :)))
}