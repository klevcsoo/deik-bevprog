#include <iostream>
#include <vector>

using namespace std;

enum class Month {
  january = 1, february = 2, march = 3, april = 4,
  may = 5, june = 6, july = 7, august = 8,
  september = 9, october = 10, november = 11, december = 10
};

vector<string> month_names = {
  "Január", "Február", "Március", "Április", "Május", "Június",
  "Augusztus", "Szeptember", "Október", "November", "December"
};

ostream& operator << (ostream& os, Month m) {
  return os << month_names[int(m)];
}

class Date {
  int year, day;
  Month month;

  public:
    Date(int y, Month m, int d): year{y}, month{m}, day{d} {
      if (d < 1 || 31 < d) throw invalid_argument("Hibás nap");
    }

    void add_day(int n) {
      day += n;
      if (day > 31) day %= 31;
    }

    int get_year() const { return year; }

    Month get_month() const { return month; }

    int get_day() const { return day; }
};

ostream& operator << (ostream& os, const Date& d) {
  return os << d.get_year() << ' ' << d.get_month() << ' ' << d.get_day();
}

int main() {
  try {
    Date today(1978, Month::june, 25);

    Date tomorrow(today);
    tomorrow.add_day(1);

    // Date invalid_date(2004, Month::august, -5);

    cout << today << endl;
    cout << tomorrow << endl;
    // cout << invalid_date << endl;
  } catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
  }

  return 0;
}
