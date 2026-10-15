class Obj {
  public:
    void fn(int, int, int, int, int, int);
    void target(int, int, int, float, int);
};
void Obj::target(int a, int b, int c, float d, int e) {
    fn(a, b, c, 0, (int)d, e);
}