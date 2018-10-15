#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>

using namespace std;

vector<string> combos(vector<string> nums, int idx)
{
  if (idx>=nums.size())
  {
    return {};
  }

  vector<string> res;
  for (char c:nums[idx])
  {
    auto cc = combos(nums,idx+1);
    if (cc.size()==0)
    {
      res.push_back(string(1,c));
    }
    else
    {
      for (string s:cc)
      {
        res.push_back(string(1,c)+s);
      }
    }
  }

  return res;
}

vector<string> letterCombinations(string digits)
{
  unordered_map<char, string> dict
  {
    {'2',"abc"},
      {'3',"def"},
      {'4',"ghi"},
      {'5',"jkl"},
      {'6',"mno"},
      {'7',"pqrs"},
      {'8',"tuv"},
      {'9',"wxyz"}
  };

  vector<string> dig_chars;
  for (char c:digits)
  {
    dig_chars.push_back(dict[c]);
  }

  return combos(dig_chars, 0);
}

vector<string> gen(string digits, unordered_map<char, string> dict, unordered_map<char, int> limit)
{
  vector<string> out;

  vector<int> looper(digits.size(), 0);
  int li = looper.size() - 1;

  looper[li]=-1;//so the first loop is 0,0,0,...

  while(1)
  {
    if (looper[li] >= limit[digits[li]])
    {
      // impl::increment(li-1):->

      // move left until we reach an element that is not above limit, and increment it
      // we already know looper[li] has reached its limit

      int it_li=li-1;
      while(looper[it_li]>=limit[digits[it_li]])
      {
        it_li--;
      }

      if (it_li<0)
        break;

      looper[it_li]++;
      for(int i=it_li+1;i<looper.size(); ++i)
      {
        looper[i]=0;
      }
      looper[looper.size()-1]=-1;
    }

    looper[li]++;

    string inst;
    for (int i=0;i<looper.size();++i)
    {
      int j=looper[i];
      char c = dict[digits[i]][j];
      inst+=c;
    }
    out.push_back(inst);
  }
  return out;
}

vector<string> lcombos(string digits)
{
  unordered_map<char, string> dict
  {
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
  };

  unordered_map<char, int> limit_map;
  for (auto el : dict)
  {
    limit_map[el.first] = el.second.size()-1;
  }

  return gen(digits, dict, limit_map);
}

int main()
{
  srand(time(NULL));
  clock_t t;

  string digits = "2345678923456";
  t = clock();
  auto res = lcombos(digits);
  t = clock() - t;
  printf ("It took %lu clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
  cout << res.size() << endl;
  // for (string s : res) cout << s << " ";
  // cout << endl;

  t = clock();
  res = letterCombinations(digits);
  t = clock() - t;
  printf ("It took %lu clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
  cout << res.size() << endl;
  // for (string s : res) cout << s << " ";
  // cout << endl;

  return 0;
}
