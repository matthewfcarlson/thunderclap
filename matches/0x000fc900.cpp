class X_fc900 {
    char pad[0x70];
    unsigned char a;
    unsigned char b;

  public:
    int f();
};
int X_fc900::f() {
    return a && b;
}