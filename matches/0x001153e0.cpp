class X {
  public:
    char pad[0xc];
    int m1c;
    bool F(int a);
};

bool X::F(int a) {
    m1c = a;
    return true;
}
