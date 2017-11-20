#include <iostream>
#include <string>

using namespace std;

class Grid {
  public:
    char * buffer;
    int cx=0, cy=0;
    int sz_rows, sz_cols;
    Grid(int cols, int rows);
    void set_size(int cols, int rows);
    void add(char c);
    void add(string s);
    void print();
};

Grid::Grid(int cols, int rows) {
  set_size(cols,rows);
}

void Grid::add(char c) {
  if (cx == sz_cols) {
    cx=0;
    cy++;
  }

  buffer[cy*sz_cols + cx]=c;
  cx++;
}

void Grid::add(string s) {
  for (char c : s) {
    add(c);
  }
}

void Grid::print() {
  for (int i=0;i<sz_rows*sz_cols;++i){
    if (i>0 && (i % sz_cols) == 0){
      cout << endl;
    }
    cout << buffer[i];
  }
}

void Grid::set_size(int cols, int rows) {
  buffer = new char[cols*rows];
  std::fill_n(buffer, cols*rows, '-');

  sz_rows=rows;
  sz_cols=cols;
}

int main() {
  Grid grid(21,5);
  grid.add("C:\\> ls -al folder/");
  grid.cy++; grid.cx=0;
  grid.add("book.txt");
  grid.cy++; grid.cx=0;
  grid.add("file.pdf");
  grid.cy++; grid.cx=0;
  grid.add("C:\\> ");
  grid.print(); cout << endl;

  return 0;
}
