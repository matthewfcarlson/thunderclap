class C_35f20 {
  public:
    char pad[0x3a8];
    int a[8][0x14];
    bool f();
};
bool C_35f20::f() {
    int i = 0;
    do {
        if (a[i][0] != 0)
            return true;
        ++i;
    } while (i < 8);
    return false;
}