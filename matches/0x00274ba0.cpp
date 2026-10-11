extern void* vReq[];
extern void* vCE[];
class Obj {
  public:
    virtual void A();
};
extern void FUN_002705f0();
struct Target {
    void* vf;
    int p4;
    int p8;
    Obj* pC;
    Target(int, Obj*);
};
Target::Target(int a, Obj* b) {
    vf = vReq;
    p4 = 0;
    FUN_002705f0();
    vf = vCE;
    p8 = a;
    pC = b;
    FUN_002705f0();
    pC->A();
}
