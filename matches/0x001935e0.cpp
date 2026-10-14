class X {
  public:
    char pad[0xfc];
    int m1fc;
    bool Set(int a);
};

bool X::Set(int a) {
    m1fc = a;
    return true;
}
