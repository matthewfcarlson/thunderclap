class A {
  public:
    char pad[0xc];
    int m;
    bool Set(int x);
};
bool A::Set(int x) {
    m = x;
    return true;
}
