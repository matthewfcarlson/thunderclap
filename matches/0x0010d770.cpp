struct A { A* f0(); int f1(); };
struct B { char pad[0x14]; int a14; int a18; int a1c; int a20; };
class ButtonAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char vfunc_5(int, int);
    char pad[0x18];
    B* mB;
    A* mA;
};
char ButtonAction::vfunc_5(int p, int q) {
    if (p == 0) {
        if (!mA) return 0;
        A* r = mA->f0();
        int base = r->f1();
        int* d = (int*)(base + 0x1f58);
        d = d + mB->a14 * 3;
        d[0] = mB->a18;
        d[1] = mB->a1c;
        d[2] = mB->a20;
    }
    return 1;
}
