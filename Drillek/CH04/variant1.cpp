#include <iostream>
#include <math.h>

using namespace std;

int main() {
  double ns [2] = { 0,0 };
  string input;

  while (cin >> ns[0] >> ns[1]) {
    if (to_string(ns[0]) == "|" || to_string(ns[1]) == "|") {
      continue;
    }

    if (ns[0] == ns[1]) {
      cout << "the numbers are equal" << endl;
      continue;
    }

    cout << "the smaller number is: " << min(ns[0], ns[1]) << endl;
    cout << "the larger number is: " << max(ns[0], ns[1]) << endl;

    if (abs(ns[0] - ns[1]) < (1.0 / 100.0)) {
      cout << "the numbers are almost equal" << endl;
    }

    ns[0] = 0; ns[1] = 0;
  }
  
  return 0;
}
