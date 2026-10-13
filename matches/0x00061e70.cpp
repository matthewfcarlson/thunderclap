class C {
    char pad[0x40];
    int m;

  public:
    bool Set(int x);
};

bool C::Set(int x) {
    m = x;
    return true;
}
