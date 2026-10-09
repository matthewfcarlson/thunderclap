int Conv(int);
class C {
  public:
    char pad[0x600];
    int e[128];
    void F(int a, int b);
};
void C::F(int a, int b) {
    int i = 0;
    int* p = (int*)((char*)this + 0x608);
    do {
        if (p[-2] == 0)
            goto L;
        if (p[0] == 0) {
            i = i + 1;
            goto L;
        }
        if (p[2] == 0) {
            i = i + 2;
            goto L;
        }
        if (p[4] == 0) {
            i = i + 3;
            goto L;
        }
        i = i + 4;
        p = p + 8;
    } while (i < 0x40);
    return;
L:
    if (i < 0x40) {
        e[i * 2] = Conv(a);
        e[i * 2 + 1] = b;
    }
}
