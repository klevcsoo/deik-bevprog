#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

const map<string, double> m_mappings = {
  { "cm", 1.0 / 100.0 },
  { "m", 1.0 },
  { "in", 2.54 / 100.0 },
  { "ft", (12.0 * 2.54) / 100 }
};

int main() {
  vector<double> values = {};
  string current_value, current_unit;

  while (cin >> current_value >> current_unit) {
    if (current_value.find('|') != string::npos) {
      break;
    }

    if (!m_mappings.count(current_unit)) {
      cout << "Error: Invalid symbol" << endl;
      return 0;
    }

    double current_value_in_m = m_mappings.at(current_unit) * stoi(current_value);
    values.push_back(current_value_in_m);
  }

  double largest = *max_element(begin(values), end(values));
  double smallest = *min_element(begin(values), end(values));
  cout << "Largest value: " << largest << "m" << endl;
  cout << "Smallest value: " << smallest << "m" << endl;
  cout << "Sum: " << accumulate(begin(values), end(values), 0) << "m" << endl;

  sort(begin(values), end(values));
  string values_text(begin(values), end(values));
  cout << "Values: " << values_text << endl;

  return 0;
}
