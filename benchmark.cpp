#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;


int f(int N = 999) {  
  int nMax = 0;

  for (int i = 1; i <= N; ++i)
    for (int j = i; j <= N; ++j) {
      string digits  = to_string(i*j);
      string rDigits = digits;

      reverse(rDigits.begin(), rDigits.end());

      if (digits == rDigits)
        nMax = max(i*j, nMax);
    }

  return nMax;
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

