class Obj {
  public:
    void target(int, int, int, int, float, int);
    void other(int, int, int, int, int, int);
};
void Obj::target(int a, int b, int c, int d, float e, int f) {
    other(a, b, c, d, (int)e, f);
}