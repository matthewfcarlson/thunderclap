extern int gState;
int Check(int, int);
struct Obj {
    int Do(int, int, int, int);
};
int Target(int a, int b, int c, int d) {
    gState = c;
    Obj* p = (Obj*)Check(c, 0x4a4);
    if (p)
        return p->Do(0, a, b, d);
    return 0;
}