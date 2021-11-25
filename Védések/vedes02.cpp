#include <iostream>

using namespace std;

class Car {
  string brand;
  string type;
  int year;

  public:
    Car(string b, string t, int y) {
      brand = b; type = t; year = y;
    }

    void is_OT();
};

void Car::is_OT() {
  if ((2022 - year) > 30) {
    cout << "This car is an old-timer" << endl;
  } else {
    cout << "This car is not an old-timer" << endl;
  }
}

int main() {
  cout << "Citroen C5 2013:" << endl;
  Car car1("Citroen", "C5", 2013);
  car1.is_OT();

  cout << endl;

  cout << "Toyota Corolla 1984:" << endl;
  Car car2("Toyota", "Corolla", 1984);
  car2.is_OT();

  return 0;
}
