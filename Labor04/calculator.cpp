#include <iostream>

using namespace std;

int main() {
  cout << "Enter an expression (+, -, *, /)" << endl;
  cout << "Enter an x to end the expression" << endl;

  int lvar = 0, rvar = 0;
  int res;
  cin >> lvar;

  if (!cin) {
    cout << "No lvar" << endl;
    return 0;
  }

  for (char op; cin >> op;) {
    if (op != 'x') cin >> rvar;
    if (!cin) {
      cout << "No rvar" << endl;
      return 0;
    }

    switch (op)
    {
    case '+':
      res = lvar + rvar;
      break;
    case '-':
      res = lvar - rvar;
      break;
    case '*':
      res = lvar * rvar;
      break;
    case '/':
      res = lvar / rvar;
      break;
    default:
      cout << "Invalid operator" << endl;
      return 0;
    }

    cout << res << endl;
  }
  
  return 0;
}
