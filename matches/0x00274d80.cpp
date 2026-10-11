extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b978[];
extern "C" char DAT_0042b9dc[];
class Obj {
  public:
    virtual void A();
};
class Elem {
  public:
    virtual void A();
    virtual void B();
};
extern void FUN_002705f0();
struct Target {
    int vf, p4, p8;
    Obj* pC;
    Obj* p10;
    int p14;
    Target(int, int, Obj*, int);
};
Target::Target(int a, int b, Obj* c, int d) {
    vf = ((int)DAT_0042b914);
    p4 = 0;
    FUN_002705f0();
    vf = ((int)DAT_0042b9dc);
    p8 = a;
    FUN_002705f0();
    vf = ((int)DAT_0042b978);
    pC = (Obj*)b;
    p10 = c;
    p14 = d;
    FUN_002705f0();
    p10->A();
    ((Elem*)((char*)pC + 4))->A();
    ++*(int*)((char*)pC + 0x14);
    ((Elem*)((char*)pC + 4))->B();
    pC->A();
}