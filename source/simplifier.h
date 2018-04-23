#include <iostream>
#include "map.h"
#include "list.h"

class simplifier
{
    private:
      int matrix[4][4];
      void makeCubes(superList&, int, int);
      bool subset(list, list); // Check is a group subset of another
      bool commonPair(Pair, superList, int);
      void optimize(superList &);
      string parseToExp(list);

    public:
      simplifier(map);
      ~simplifier();
      void run();
};    