struct Tgt {
    char pad[0x4c];
    struct Q {
        char p[0xc];
        int d;
    }* q;
};
class Params {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual Tgt* Get();
};
extern char typeA;
extern char typeB;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
class Cond {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int, Params*, int);
    int pad[2];
    int source;
    int mode;
};
bool Cond::vfunc_6(int, Params* p, int) {
    if (!FUN_00344e74(p, 0, &typeA, &typeB, 0))
        return false;
    Tgt* t = p->Get();
    if (!t)
        return false;
    if (!t->q)
        return false;
    int d = t->q->d;
    int c = 0;
    switch (mode) {
    case 0:
        c = 1;
        break;
    case 1:
        c = 5;
        break;
    }
    switch (source) {
    case 0:
        return c == d;
    case 1:
        return c != d;
    }
    return false;
}