#include "iostream"

using namespace std;

int main() {
  cout << "Please enter your first name and age" << endl;

  string firstName;
  int age;

  cin >> firstName >> age;
  cout << "Hello, " << firstName << "! (" << age << ")" << endl;

  return 0;
}
