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
  int a[9] = {0, 1, 3, 4, 5, 7, 12, 13, 15};
  map m;
  m.parseToMap(a, 9);
  m.printMap();
  cout << "\n";

  simplifier s(m);
  
  s.run();
}