#include <iostream>
#include <iomanip>
#include <ctime>
#include <cfloat>
#include <string>

using namespace std;


int f(int N = 999) {   
  int nMax = 0;

  for (int i = 1; i <= N; ++i)
    for (int j = i; j <= N; ++j) {
      string s = to_string(i*j);

      if (s == string(s.rbegin(), s.rend()))
        nMax = max(i*j, nMax);  
    }

  return nMax;
}


int main()
{
  const int N = 10;

  int    result  = 0;
  double timeMin = DBL_MAX;

  for (int i = 0; i < N; ++i) {
    auto t0 = clock();
    result += f();
    auto t1 = clock();
    timeMin = min(timeMin, (double)(t1-t0)/CLOCKS_PER_SEC);
  }

  cout << "CPU Time: " << fixed << setprecision(3) << timeMin << "s" << endl;
  cout << "Result: " << result/N << endl << endl;

  return 0;
}

