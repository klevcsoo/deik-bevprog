#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<double> temps;

  for (double temp; cin >> temp;) {
    temps.push_back(temp);
  }

  double sum = 0;
  for (double temp: temps) {
    sum += temp;
  }

  cout << "Avg. temperature: " << sum / (double)temps.size() << endl;

  sort(temps); // do something about this
  
  return 0;
}
