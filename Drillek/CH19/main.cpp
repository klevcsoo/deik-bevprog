#include <iostream>
#include <vector>

using namespace std;

template<typename T> struct S {
  explicit S(T v = 0): val{ v } { }
  S& operator=(const T&);
  T& get();
  const T& get() const;
  // void set(T v) { val = v }

private:
  T val;
};
template<typename T> T& S<T>::get() {
  return val;
}
template<typename T> const T& S<T>::get() const {
  return val;
}
template<typename T> S<T>& S<T>::operator = (const T& s) {
  val = s;
  return *this;
}
template<typename T> void read_val(T& v) {
  cin >> v;
}

int main() {
  S<int> s_int { 64 };
  S<char> s_char { 'f' };
  S<double> s_double { 213.75 };
  S<string> s_string { "Hello, World!" };
  S<vector<int>> s_vector { vector<int>{ 1, 2, 4, 8, 16, 32, 64 }  };

  cout << "S<int>: " << s_int.get() << endl;
  cout << "S<char>: " << s_char.get() << endl;
  cout << "S<double>: " << s_double.get() << endl;
  cout << "S<string>: " << s_string.get() << endl;
  cout << "S<vector<int>>: " ;
  for (const int vv : s_vector.get()) {
    cout << vv << " ";
  }; cout << endl;

  cout << "integer: ";
  int int_input; read_val(int_input);
  S<int> s_int_read {int_input};

  cout << "char: ";
  char char_input; read_val(char_input);
  S<char> s_char_read {char_input};

  cout << "double: ";
  double double_input; read_val(double_input);
  S<double> s_double_read {double_input};

  cout << "string: ";
  string string_input; read_val(string_input);
  S<string> s_string_read {string_input};

  cout << "Read S<int>: " << s_int_read.get() << endl;
  cout << "Read S<char>: " << s_char_read.get() << endl;
  cout << "Read S<double>: " << s_double_read.get() << endl;
  cout << "Read S<string>: " << s_string_read.get() << endl;

  return 0;
}
