class A {
  public:
    char pad[0x50];
    int mValue;
    bool Set(int v) throw();
};

bool A::Set(int v) throw() {
    mValue = v;
    return true;
}