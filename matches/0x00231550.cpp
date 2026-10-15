class Obj {
  public:
    Obj(int a, int b, int c);
    void init(int);
    int x0, x4, x8;
    char xc;
    char pad[3];
    int x10, x14, x18, x1c, x20;
};
Obj::Obj(int a, int b, int c) : x0(a), x4(0), x8(0), xc(0), x10(c), x14(b), x18(0), x1c(0), x20(0) {
    init(a);
}