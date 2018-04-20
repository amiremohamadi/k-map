#include <string>
using std::string;

#define SIZE 4

class map
{
    private:
      int matrix[SIZE][SIZE] = {0}; // Map matrix
    
    public:
      map();
      ~map();
      // Parse the input data to matrix
      void parseToMap(int[], int);
      // Copy map to another matrix for some reasons :)
      void getMatrix(int m[4][4]);
      // Print
      void printMap() const;
};
