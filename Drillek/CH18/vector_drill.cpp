#include <iostream>
#include <vector>

using namespace std;

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> v) {
  vector<int> lv(size(v));
  for (int i = 0; i < size(v); i++) lv[i] = gv[i];
  for (auto &element : lv) cout << element << " ";
  cout << endl;

  vector<int> lv2(v);
  for (auto &element : lv2) cout << element << " ";
  cout << endl;
}

int main() {
  f(gv);

  vector<int> vv = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
  f(vv);

  return 0;
}
