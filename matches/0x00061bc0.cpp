class C {
  public:
    char pad[0x90];
    int m90;
    bool Set(int x);
};

bool C::Set(int x) {
    m90 = x;
    return true;
}
