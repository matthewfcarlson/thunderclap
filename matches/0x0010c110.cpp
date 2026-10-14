class X_10c110 {
  public:
    char pad[0x14];
    int m14;
    bool Set(int a);
};
bool X_10c110::Set(int a) {
    m14 = a;
    return true;
}
