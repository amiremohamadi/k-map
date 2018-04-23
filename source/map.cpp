#include <iostream>
#include "map.h"
using std::cout;

#define SIZE 4

inline int convertToGray(int);

map::map(){};
map::~map(){};

void map::parseToMap(int arr[], int counter)
{
    for (unsigned int i = 0; i < counter; ++i)
    {
        // Using gray code
        int row = convertToGray(arr[i] / SIZE);
        int column = convertToGray(arr[i] % SIZE);
        matrix[row][column] = 1;
    }
}

void map::getMatrix(int m[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            m[i][j] = matrix[i][j];
}

void map::printMap() const
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
            cout << matrix[i][j] << " ";
        
        cout << "\n";
    }
}
// Ohhh! I found this method at stackoverflow.com :))
// Shift a bit to right and then xor with it
inline int convertToGray(int n) { return (n >> 1) ^ n; }
