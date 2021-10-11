#include <iostream>
#include <math.h>

using namespace std;

int main() {
  double largest = INT64_MIN;
  double smallest = INT64_MAX;

  double input;

  while (cin >> input) {
    if (input > largest) {
      if (largest != INT64_MIN) {
        cout << "the largest so far" << endl;
      }
      largest = input;
    } else if (input < smallest) {
      if (smallest != INT64_MAX) {
        cout << "the smallest so far" << endl;
      }
      smallest = input;
    }
  }
  
  return 0;
}
