class C {
  public:
    char pad[0xbc];
    int mValue;
    bool Set(int x);
};

bool C::Set(int x) {
    mValue = x;
    return true;
}
