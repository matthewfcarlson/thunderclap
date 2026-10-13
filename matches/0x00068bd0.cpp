class A {
  public:
    char pad[0x10];
    int m10;
    bool Set(int x);
};

bool A::Set(int x) {
    m10 = x;
    return true;
}
