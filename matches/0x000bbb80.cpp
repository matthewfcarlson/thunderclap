class Obj {
  public:
    int a;
    int b;
    int Fn(int x, int y);
};
int Obj::Fn(int x, int y) {
    return (b != 0) - 1;
}