class C {
  public:
    char pad[0x20];
    int mValue;
    bool Set(int x);
};

bool C::Set(int x) {
    mValue = x;
    return true;
}
