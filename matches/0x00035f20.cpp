class C {
  public:
    char pad[0x3a8];
    int a[8][0x14];
    bool f();
};
bool C::f() {
    int i = 0;
    do {
        if (a[i][0] != 0)
            return true;
        ++i;
    } while (i < 8);
    return false;
}