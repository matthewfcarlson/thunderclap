class C {
  public:
    bool Set(int x);
    char pad[0x2c];
    int m2c;
};

bool C::Set(int x) {
    m2c = x;
    return true;
}
