#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers = {5, 8, 2, 4, 1};
  for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << endl;
  }

  vector<string> names = {"Pisti", "Kati", "Imi"};
  for (int i = 0; i < names.size(); i++) {
    cout << names[i] << endl;
  }

  vector<double> dv;
  cout << dv.size() << endl;
  dv.push_back(3.50);
  dv.push_back(1.7);
  dv.push_back(8.067);
  cout << dv.size() << endl;
  for (int i = 0; i < dv.size(); i++) {
    cout << dv[i] << endl;
  }

  return 0;
}
