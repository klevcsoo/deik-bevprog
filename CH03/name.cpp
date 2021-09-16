#include "iostream"

using namespace std;

int main() {
  cout << "Please enter your name and age" << endl;

  string firstName;
  string lastName;
  int age;

  cin >> firstName >> lastName >> age;
  string name = firstName + ' ' + lastName;

  cout << "Hello, " << name << "! (" << age << ")" << endl;

  return 0;
}
