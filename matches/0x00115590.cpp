class C {
  public:
    char pad[0x14];
    int m14;
    bool Set(int x);
};

bool C::Set(int x) {
    m14 = x;
    return true;
}
