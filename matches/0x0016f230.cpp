class X {
  public:
    char pad[0x14];
    int m14;
    bool F(int a);
};
bool X::F(int a) {
    m14 = a;
    return true;
}