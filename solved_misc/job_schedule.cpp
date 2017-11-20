#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Job
{
  int start, finish, profit;
};

unordered_map<string, int> cache;

int maxProfit(vector<Job> jobs, int ji)
{
  int currentProfit=jobs[ji].profit;

  int nextMax=0;
  for (int i=ji+1;i<jobs.size();++i)
  {
    if (jobs[i].start>=jobs[ji].finish)
    {
      char buff[10];
      sprintf(buff, "%d-%d",jobs[i].start, jobs[i].finish);
      string key(buff);

      int p;
      if (cache.find(key) != cache.end())
      {
        p=cache[key];
        cout << "p: " << p << endl;
      }
      else
      {
        p=maxProfit(jobs,i);
        cache[key]=p;
      }
      if (p>nextMax)
      {
        nextMax=p;
      }
    }
  }
  return currentProfit+nextMax;
}

int maxProfitW(vector<Job> jobs) {
  int maxv=0;
  for (int i=0;i<jobs.size();++i)
  {
    int p=maxProfit(jobs,i);
    if (p>maxv)
      maxv=p;
  }
  return maxv;
}

int main() {

  vector<Job> arr = {
    {1,5,20}, {2,5,30}, {3,8,40}, {7,10,70}, {6,10,40}, {9,12,20}, {11,13,20}, {14,20,60}
  };
  // vector<Job> arr = {{1,2,50}, {3,10,20}, {6,19,100}, {2,100,200}};

  cout << maxProfitW(arr) << endl;

  cout << "CACHE:" << endl;

  for (auto it : cache) {
    cout << it.first << " " << it.second << endl;
  }

  return 0;
}
