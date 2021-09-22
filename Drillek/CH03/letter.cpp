#include "iostream"

#define C_ERR "\033[1;31m"
#define C_BOLD "\033[1m"
#define C_CLR "\033[0m"

using namespace std;

void simple_error(string error_msg) {
  cout << C_ERR << error_msg << C_CLR << endl;

  // A "../../runcpp.zsh" miatt szükséges a 0 exit kód.
  exit(0);
}

int main() {
  string first_name;
  cout << "Enter the name of the person you want to write to" << endl;
  cin >> first_name;
  cout << C_BOLD << "Dear " << first_name << "," << C_CLR << endl;

  cout << C_BOLD << "\tHow are you? I am fine. I miss you." << C_CLR << endl;

  string friend_name;
  cout << "Enter the name of another friend" << endl;
  cin >> friend_name;
  cout << C_BOLD "Have you seen " << friend_name << " lately?" << C_CLR << endl;

  char friend_sex = (char)0;
  cout << "If your friend's sex ('m' for male, 'f' for female)" << endl;
  while (friend_sex != 'm' && friend_sex != 'f') {
    cin >> friend_sex;
    
    if (friend_sex != 'm' && friend_sex != 'f') {
      simple_error("Incorrect character, please try again");
    }
  }
  cout << C_BOLD << "If you see " << friend_name
    << " please ask " << ((friend_sex == 'f') ? "her" : "him")
    << " to call me." << C_CLR << endl
  ;

  int age;
  cout << "Enter the age of the recipient" << endl;
  cin >> age;
  if (age <= 0 || age >= 100) {
    simple_error("You're kidding");
  }
  cout << C_BOLD << "I hear you just had your birthday and you are "
    << age << " years old." << C_CLR << endl
  ;
  cout << C_BOLD;
  if (age < 12) {
    cout << "Next year you will be " << age + 1 << "." << endl;
  } else if (age == 17) {
    cout << "Next year, you will be able to vote." << endl;
  } else if (age > 70) {
    cout << "I hope your are enjoying retirement." << endl;
  }

  cout << "Yours sincerely,\n\n\nKeve" << C_CLR << endl;

  return 0;
}
