#include <iostream>
#include "map.h"
#include "list.h"

class simplifier
{
    private:
      int matrix[4][4];

    public:
      simplifier(map);
      ~simplifier();
      void makeCubes(superList&, int, int);
      void run();
};