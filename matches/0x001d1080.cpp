extern void F1(int, int, int);
extern int F2(int, int);
extern void F3(int, int);
extern int F4(int, int);
unsigned char __stdcall Target(int p1, int p2) {
    if (p1 == 0) return 0;
    F1(p2, (int)0xffffd8ef, p1);
    int r = F2(p2, -1);
    if (r != 1) {
        F3(p2, -2);
        return 0;
    }
    int q = F4(p2, -1);
    F3(p2, -2);
    return q != 0;
}