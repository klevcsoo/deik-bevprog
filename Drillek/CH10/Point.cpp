class Point {
  private:
    int x, y;
  public:
    Point(): x(0), y(0) {};
    Point(int x, int y): x(x), y(y) {};

    int get_x() {
      return x;
    }

    int get_y() {
      return y;
    }
};
