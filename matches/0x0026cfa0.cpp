extern int gState_26cfa0;
int Check(int, int);
struct Obj_26cfa0 {
    int Do(int, int, int, int);
};
int Target(int a, int b, int c, int d) {
    gState_26cfa0 = c;
    Obj_26cfa0* p = (Obj_26cfa0*)Check(c, 0x4a4);
    if (p)
        return p->Do(0, a, b, d);
    return 0;
}