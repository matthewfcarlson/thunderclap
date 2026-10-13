class A {
  public:
    char pad[32];
    int m20;
    bool Set(int x);
};

bool A::Set(int x) {
    m20 = x;
    return true;
}
