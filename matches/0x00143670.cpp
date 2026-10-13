class A {
  public:
    char pad[0x18];
    int m18;
    bool Set(int x);
};

bool A::Set(int x) {
    m18 = x;
    return true;
}
