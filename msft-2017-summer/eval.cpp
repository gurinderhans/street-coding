#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Parser
{
  private:
    int i=0;

  public:
    int get_num(string const& expr)
    {
      if(expr[i]=='(')
      {
        int res=-1;// -1 is an invalid number
        for(int j=i,bc=0;j<expr.size();++j)
        {
          if(expr[j]=='(')bc++;
          else if(expr[j]==')')bc--;

          if(bc==0)
          {
            string sub_expr=expr.substr(i+1,j-i-1);//+1,-1 to exclude brackets
            Parser p;
            res=p.parse(sub_expr);
            i+=j+1;
            break;
          }
        }
        return res;
      }
      else
      {
        int orig_i=i;
        for(;expr[i]>='0'&&expr[i]<='9';++i);

        int res=0;
        for(int j=i-1,p=0;j>=orig_i;--j,++p)
        {
          res+=pow(10,p)*(expr[j]-48);
        }
        return res;
      }
    }

    int exp(string const& expr)
    {
      int r=get_num(expr);
      while(expr[i]=='^')
      {
        i++;
        r=pow(r,get_num(expr));
      }
      return r;
    }

    int div(string const& expr)
    {
      int r=exp(expr);
      while(expr[i]=='/')
      {
        i++;
        r/=exp(expr);
      }
      return r;
    }

    int mul(string const& expr)
    {
      int r=div(expr);
      while(expr[i]=='*')
      {
        i++;
        r*=div(expr);
      }
      return r;
    }

    int add(string const& expr)
    {
      int r=mul(expr);
      while(expr[i]=='+')
      {
        i++;
        r+=mul(expr);
      }
      return r;
    }

    int sub(string const& expr)
    {
      int r=add(expr);
      while(expr[i]=='-')
      {
        i++;
        r-=add(expr);
      }
      return r;
    }

    int parse(string const& expr)
    {
      // since the last operation is subtract, we'll call subtract
      return sub(expr);
    }
};

int main()
{
  Parser p;
  cout<<p.sub("(2*(4+5))/(2*3)");
  cout << endl;

  return 0;
}
