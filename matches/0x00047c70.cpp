class C {
  public:
    char pad[16];
    int mField;
    bool Set(int x);
};

bool C::Set(int x) {
    mField = x;
    return true;
}
