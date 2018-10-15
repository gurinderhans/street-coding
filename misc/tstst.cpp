#include <iostream>

using namespace std;

class Base{
  public:
  unsigned m_size;
  char * m_data;

  Base(unsigned size): m_size(size){
    m_data =new char[m_size];
    fill();
  }
  ~Base(){
    cout << "decons"<<endl;
    delete [] m_data;
    m_data = nullptr;
  }
  void print(){
    for (int i=0;i<m_size;++i){
      cout << m_data[i];
    }
    cout << endl;
  }
  protected:
  void fill(){
    for(int i=0;i<m_size;++i){
      m_data[i]=65+i;
    }
  }
};

class Derived: public Base{
  int * foo;

  public:
  Derived(unsigned n): Base(n){
    foo = new int[100];
    std::fill(foo, foo+100, 0);
  }

  ~Derived(){
    cout << "decons dervicedprint"<<endl;
    delete [] foo;
    foo = nullptr;
  }
};

int main(){
  Derived *s = new Derived(4);
  s->print();
  delete s;
  // int * mdata;
  // mdata= new int[2];
  // mdata[0]=6;
  //
  // cout << mdata[0]<<endl;
}
