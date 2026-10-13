class C {
  public:
    char pad[0x40];
    int m40;
    bool Set(int x);
};
bool C::Set(int x) {
    m40 = x;
    return true;
}
