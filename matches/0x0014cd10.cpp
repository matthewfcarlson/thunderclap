class A {
  public:
    char p[0x14];
    int m;
    bool Set(int v);
};
bool A::Set(int v) {
    m = v;
    return true;
}