class C {
  public:
    char pad[16];
    int m;
    bool Set(int x);
};

bool C::Set(int x) {
    m = x;
    return true;
}
