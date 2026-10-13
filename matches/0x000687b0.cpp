class A {
  public:
    char Pad[0x10];
    int Value;
    bool Set(int x);
};

bool A::Set(int x) {
    Value = x;
    return true;
}
