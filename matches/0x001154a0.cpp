class A {
  public:
    char pad[0x10];
    int m;
    bool Set(int x);
};

bool A::Set(int x) {
    m = x;
    return true;
}
