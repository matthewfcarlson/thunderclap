class C {
  public:
    char pad[0x10];
    int m10;
    bool F(int x);
};

bool C::F(int x) {
    m10 = x;
    return true;
}
