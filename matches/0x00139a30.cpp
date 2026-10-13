class C {
  public:
    char pad[0xc];
    int m;
    bool f(int x);
};

bool C::f(int x) {
    m = x;
    return true;
}