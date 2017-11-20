#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<pair<int,int>> getSiblings(int row, int col, int rows, int cols) {
  vector<pair<int,int>> siblings;

  if(row-1 >= 0) siblings.push_back({row-1,col});                 // TOP
  if(col-1 >= 0) siblings.push_back({row, col-1});                // LEFT
  if(row+1 < rows) siblings.push_back({row+1,col});               // DOWN
  if(col+1 < cols) siblings.push_back({row,col+1});               // RIGHT

  if(row-1>=0 && col-1>=0) siblings.push_back({row-1, col-1});    // TOP_LEFT
  if(row+1<rows && col-1>=0) siblings.push_back({row+1, col-1});  // BOTTOM_LEFT
  if(row+1<rows && col+1<cols) siblings.push_back({row+1,col+1}); // BOTTOM_RIGHT
  if(row-1>=0 && col+1<cols) siblings.push_back({row-1,col+1});   // TOP_RIGHT

  return siblings;
}

void print_(vector<vector<char>> &grid)
{
  for(int i=0;i<grid.size();++i)
  {
    for(int j=0;j<grid[0].size();++j)
      cout << grid[i][j]<< " ";
    cout << endl;
  }
  cout << endl;
}

int dfs(vector<vector<char>> &grid, int frm_row, int frm_col)
{
  int area=0;
  stack<pair<int,int>> ss;
  grid[frm_row][frm_col]='x';
  ss.push({frm_row,frm_col});

  while(ss.size()>0)
  {
    auto pos=ss.top();
    ss.pop();
    area++;

    auto sibs=getSiblings(pos.first, pos.second, grid.size(), grid[0].size());
    for (auto s:sibs)
    {
      if (grid[s.first][s.second]=='0' 
          || grid[s.first][s.second]=='x')
      {
        continue;
      }

      grid[s.first][s.second]='x';
      ss.push(s);
    }
  }
  return area;
}

int get_biggest_region(vector< vector<char> > &grid) {
  int largest_region=0;
  for (int row=0;row<grid.size();++row)
  {
    for (int col=0;col<grid[0].size();++col)
    {
      if (grid[row][col]=='1')
      {
        int region_count = dfs(grid,row,col);
        if (largest_region<region_count)
        {
          largest_region=region_count;
        }
      }
    }
  }
  return largest_region;
}

int main(){
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector< vector<char> > grid(n,vector<char>(m));
  for(int grid_i = 0;grid_i < n;grid_i++){
    for(int grid_j = 0;grid_j < m;grid_j++){
      cin >> grid[grid_i][grid_j];
    }
  }
  cout << get_biggest_region(grid) << endl;
  return 0;
}
