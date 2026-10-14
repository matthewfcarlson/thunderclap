class C {
  public:
    char pad[0x14];
    int m;
    bool Set(int x);
};

bool C::Set(int x) {
    m = x;
    return true;
}
