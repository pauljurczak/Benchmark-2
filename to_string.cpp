#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;


int f(int N = 100000) {  
  int len = 0;

  for (int i = 0; i <= N; ++i) 
    len += to_string(i).length();

  return len;
}


int main()
{
  const int N = 10;

  auto t0 = clock();
  int  r  = 0;

  for (int i = 0; i < N; ++i)
    r += f();

  auto t1 = clock();

  cout << "CPU Time: " << fixed << setprecision(3) << (double)(t1-t0)/N/CLOCKS_PER_SEC << "s" << endl;
  cout << "Result: " << r/N << endl << endl;

  return 0;
}

