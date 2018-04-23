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
  int size;
  cout << "Number of minterms: ";
  cin >> size;

  // Dynamic array
  int *minterm = new int[size];
  if (minterm == 0) // If there was no enough space
    exit(0);
  // Get minterms and put them in an array
  cout << "Minterms: ";
  for (unsigned int i = 0; i < size; ++i)
    cin >> minterm[i];

  map map;
  map.parseToMap(minterm, size);
  // Print map
  cout << "\nK-Map:\n";
  map.printMap();
  cout << "\n";

  simplifier simplify(map);
  
  simplify.run();
}