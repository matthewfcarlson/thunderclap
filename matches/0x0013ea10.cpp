class C {
  public:
    bool Set(int x);
    char pad[0x58];
    int m;
};
bool C::Set(int x) {
    m = x;
    return true;
}