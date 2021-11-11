// Csináljunk egy vektort, aminek elemei az 1, 2, 3, 4 és 5
// Íratsuk ki úgy, hogy out_of_range exceptiont kapjunk
// Kezeljük a hibát runetime-ban (try/catch)

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers = { 1, 2, 3, 4, 5 };

  try {
    for (int i = 0;;i++) {
    // JAVÍTÁS: for (int i = 0;i < numbers.size();i++) {
      cout << numbers.at(i) << endl;
    }
  } catch (exception& e) {
    cout << "Error with " << e.what() << endl;
    return 1;
  } catch (...) {
    cout << "Unknown error" << endl;
    return 1;
  }

  return 0;
}
