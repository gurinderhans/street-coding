#include <stdio.h>
#include <stdlib.h>

void rotate90Right(int **arr, int SIZE) {
  for (int layer=0; layer<SIZE/2; ++layer){
    int end=SIZE-layer-1;
    for (int offset=layer;offset<end;++offset){
      int tmp=arr[layer+offset][layer];
      arr[layer+offset][layer] = arr[end][layer+offset];
      arr[end][layer+offset]=arr[end-offset][end];
      arr[end-offset][end]=arr[layer][end-offset];
      arr[layer][end-offset]=tmp;
    }
  }
}

void printMat(int** arr, int SIZE) {
  for (int i=0; i<SIZE; ++i) {
    for (int j=0; j<SIZE; ++j) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // initialize array
  int SIZE = 8;
  int **arr = (int **) malloc(SIZE * sizeof(int *));
  for (int row = 0; row < SIZE; ++row) {
    arr[row] = (int *) malloc(SIZE * sizeof(int));
  }

  for (int i=0;i<SIZE;++i)
    for (int j=0;j<SIZE;++j)
      arr[i][j]=rand() % 10;

  printMat(arr, SIZE);
  rotate90Right(arr, SIZE);
  printf("\n");
  printMat(arr, SIZE);

  return 0;
}
