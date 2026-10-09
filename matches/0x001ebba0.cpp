class C {
  public:
    C* Set(int x, int y);
    int a;
    int b;
};
C* g;
C* C::Set(int x, int y) {
    g = this;
    a = x;
    b = y;
    return this;
}
