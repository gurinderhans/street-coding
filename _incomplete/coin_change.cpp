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

long long make_change(vector<int> coins, int money) {
  // for each coin, we choose 0, 1 or N amount, and subtract the value from change we want to make
  // ex. we want to make 27c, and have {1,2,3} as the three denominations
  // we will either choose 0 pennies, 1 penny, and so on... upto maybe 27
  // then we will do the same for a 2c coin, 0|1|N, and so on.. until we have cycled through
  // all the coin denominations



  return 0;
}

int main(){
  int n;
  int m;
  cin >> n >> m;
  vector<int> coins(m);
  for(int coins_i = 0;coins_i < m;coins_i++){
    cin >> coins[coins_i];
  }
  cout << make_change(coins, n) << endl;
  return 0;
}


