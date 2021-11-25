#include <iostream>

using namespace std;

void swap_v(int a, int b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void swap_r(int& a, int& b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

// konstansok értékét nem lehet módosítani
// void swap_cr(const int& a, const int& b) {
//   int temp;
//   temp = a;
//   a = b;
//   b = temp;
// }

int main() {
  // swap_v
  int x = 7;
  int y =9;
  swap_v(x,y);
  swap_v(7,9);
  const int cx = 7;
  const int cy = 9;
  swap_v(cx,cy);
  swap_v(7.7,9.9);
  double dx = 7.7;
  double dy = 9.9;
  swap_v(dx,dy);
  swap_v(7.7,9.9);

  // swap_r (duplikált változók)
  // int x = 7;
  // int y =9;
  // swap_r(x,y);
  // swap_r(7,9);
  // const int cx = 7;
  // const int cy = 9;
  // swap_r(cx,cy);
  // swap_r(7.7,9.9);
  // double dx = 7.7;
  // double dy = 9.9;
  // swap_r(dx,dy);
  // swap_r(7.7,9.9);

  // swap_cr (function hiba)
  // int x = 7;
  // int y =9;
  // swap_cr(x,y);
  // swap_cr(7,9);
  // const int cx = 7;
  // const int cy = 9;
  // swap_cr(cx,cy);
  // swap_cr(7.7,9.9);
  // double dx = 7.7;
  // double dy = 9.9;
  // swap_cr(dx,dy);
  // swap_cr(7.7,9.9);

  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "cx: " << cx << endl;
  cout << "cy: " << cy << endl;
  cout << "dx: " << dx << endl;
  cout << "dy: " << dy << endl;

  return 0;
}
