#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

// primary template
template <typename T> T Add(T n, T m) { return n + m; }

// non type templates
template <typename T, int size> T ArraySum(T (&refArr)[size]) {
  T sum = 0;
  for (T &i : refArr) {
    sum += i;
  }
  return sum;
}

// non type templates
template <typename T, int size> T MaxArray(T (&refArr)[size]) {
  return *max_element(refArr, (refArr + size));
}

template <typename T> T Max(T n, T m) { return n > m ? n : m; }

// explicit specialization
template <> const char *Max<const char *>(const char *n, const char *m) {
  return strcmp(n, m) > 0 ? n : m;
}
// explicit instantiation
template float Add<float>(float, float);

int main(void) {

  int arr[]{1, 2, 3, 6, 5, 4, 7, 8, 9};
  double dob[]{1.1, 2, 3, 6.5, 7.1};
  cout << ArraySum(arr) << endl;
  cout << ArraySum(dob) << endl;
  cout << MaxArray(arr) << endl;
  cout << MaxArray(dob) << endl;
  cout << Add(5, 6) << endl;
  cout << Add(5.5, 9.6) << endl;
  cout << Add(5.750f, 5.45F) << endl;
  return 0;
}