#include <iostream>

using namespace std;

ostream& print_and_delete(ostream& os, char ca[], int ca_size) {
  os << "Tömb tartalma: ";
  for (int i = 0; i < ca_size; i++) os << ca[i] << endl;

  os << "Tömb mérete: " << ca_size << endl;

  return os;
}

int main() {
  char* charater_array = new char[20]{'a', 'b', 'c', 'd', 'e', 'f'};
  print_and_delete(cout, charater_array, 20);
  delete[] charater_array;

  return 0;
}
