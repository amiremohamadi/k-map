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
      bool subset(list, list); // Check is a group subset of another
      void optimize(superList&);
      string parseToExp(list);
      void run();
};    