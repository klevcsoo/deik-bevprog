#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Point {
  int x, y;
};

int main() {
  const string filePath = "/Users/klevcsoo/GitHub/deik-bevprog/Drillek/CH10/mydata.txt";

  vector<Point> originalPoints;
  vector<Point> processedPoints;

  for (int i = 0; i < 7; i++) {
    int x, y;
    cin >> x >> y;
    originalPoints.push_back({x, y});
  }

  ofstream outFile(filePath);
  for (auto p : originalPoints) {
    outFile << p.x << "\t" << p.y << endl;
  }
  outFile.close();

  ifstream inFile {filePath};
  string a; inFile >> a; cout << a;

  return 0;
}
