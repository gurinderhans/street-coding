#include <iostream>
#include <vector>
#include <tuple>
#include <ctime>
#include <cstdlib>

using namespace std;

using vi = vector<int>;
// ---------->   LOW  HIGH SUM
using tt = tuple<int, int, int>;

class MaxSubArray
{
  public:
    tt IterMaxSubArr(vi arr)
    {
      int sbegin=0, tmp_sbegin=0, send=0, gsum=INT_MIN;
      int lastSum=0;
      for (int i=0;i<arr.size();++i)
      {
        lastSum+=arr[i];
        if (lastSum < arr[i])
        {
          lastSum = arr[i];
          tmp_sbegin=i;
        }

        if (lastSum > gsum)
        {
          gsum = lastSum;
          send=i;
          sbegin=tmp_sbegin;
        }
      }

      return make_tuple(sbegin, send, gsum);
    }

    tt MaxCross(vi arr, int low, int mid, int high)
    {
      int lsum=INT_MIN;
      int lmax=0;
      int rsum=INT_MIN;
      int rmax=0;

      int tmp_sum=0;
      for (int i=mid; i>=low; --i)
      {
        tmp_sum+=arr[i];
        if (tmp_sum>lsum)
        {
          lsum = tmp_sum;
          lmax = i;
        }
      }

      tmp_sum=0;
      for(int i=mid+1; i<=high; ++i)
      {
        tmp_sum+=arr[i];
        if (tmp_sum>rsum)
        {
          rsum = tmp_sum;
          rmax = i;
        }
      }

      return make_tuple(lmax, rmax, lsum+rsum);
    }

    tt _recuversiveMaxSubArr(vi arr, int low, int high)
    {
      if (low == high)
      {
        return make_tuple(low, high, arr[low]);
      }

      int mid = (low+high) / 2;

      // - split into left subsection and find max sub array
      auto l = _recuversiveMaxSubArr(arr, low, mid);

      // - split into right subsection and find max sub array
      auto r = _recuversiveMaxSubArr(arr, mid+1, high);

      // - look at the section crossing between midpoint to check for max subarray  
      auto c = MaxCross(arr, low,mid,high);

      if (get<2>(l) > get<2>(r) && get<2>(l) > get<2>(c))
      {
        return l;
      }
      else if (get<2>(r) > get<2>(c))
      {
        return r;
      }
      else
      {
        return c;
      }
    }

    tt RecursiveMaxSubArr(vi arr)
    {
      return _recuversiveMaxSubArr(arr, 0, arr.size()-1);
    }
};

void print_vec(vi v, int low, int high)
{
  for (int i=low; i<high; ++i) cout << v[i] << " ";
  cout << endl;
}

void print_tt(tt e)
{
  cout << "left: "      << get<0>(e);
  cout << ", right: "   << get<1>(e);
  cout << ", sum: "     << get<2>(e);
  cout << endl;
}

int main()
{
  srand(time(NULL));
  clock_t t;

  vi a;
  for (int i=0; i<10000; ++i)
  {
    int random_integer = rand() % 200 + (-100);
    a.push_back(random_integer);
  }
  // print_vec(a,0,a.size());

  MaxSubArray solver;

  t = clock();
  auto r0 = solver.IterMaxSubArr(a);
  t = clock() - t;
  printf ("It took %lu clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

  t = clock();
  auto r1 = solver.RecursiveMaxSubArr(a);
  t = clock() - t;
  printf ("It took %lu clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

  cout << "Res: -----------" << endl;

  print_tt(r0);
  print_tt(r1);

  return 0;
}
