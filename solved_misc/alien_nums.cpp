#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int parse_num(string n, string alphabet)
{
  int num_base = alphabet.size();

  int nn=0;
  for(int i=n.size()-1; i>=0; --i)
  {
    nn+=pow(alphabet.size(), n.size()-i-1) * alphabet.find(n[i]);
  }

  return nn;
}

string get_num(int ith_num, string alphabet)
{
  string out="";

  // EDGE CASE
  if (ith_num == 0) out = alphabet[0];

  else
  {
    int alpha_len = alphabet.size();

    while (ith_num) {
      int r = ith_num % alpha_len;
      out += alphabet[r];

      ith_num /= alpha_len;
    }

    reverse(out.begin(), out.end());
  }

  return out;
}

int main()
{
  int T;cin>>T;
  string n,src,trgt;
  for(int i=0; i<T;++i)
  {
    cin>>n>>src>>trgt;
    int intt = parse_num(n, src);
    string conv_num = get_num(intt, trgt);

    cout << "Case #"<<(i+1)<<": " << conv_num << endl;
  }

  return 0;
}
