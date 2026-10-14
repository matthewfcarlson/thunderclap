class C {
  public:
    char pad[0x140];
    int m;
    bool Set(int x);
};

bool C::Set(int x) {
    m = x;
    return true;
}
