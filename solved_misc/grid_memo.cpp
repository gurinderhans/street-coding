#include <iostream>
#include <vector>

using namespace std;

int numPaths(int matrix[5][5], int crow, int ccol) {

  if ( crow < 0 || crow > 4 || ccol < 0 || ccol > 4 )
  {
    // cout << "out of bounds -> [r: " << crow << ", c: " << ccol << "]" << endl;
    return 0;
  }

  if (crow == 4 && ccol == 4) // reached end
  {
    return 1;
  }



  return numPaths(matrix, crow+1, ccol) + numPaths(matrix, crow, ccol+1);
}

int main() {

  int matrix[5][5] = {
    {0,0,0,0,0},
    {0,1,0,0,0},
    {0,0,0,1,0},
    {0,0,1,0,0},
    {0,0,0,0,0}
  };

  cout << "num paths: " << numPaths(matrix, 0,0) << endl;

  return 0;
}
