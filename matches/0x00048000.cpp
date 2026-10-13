class A {
  public:
    char pad[12];
    int mValue;
    bool Set(int x);
};

bool A::Set(int x) {
    mValue = x;
    return true;
}
