extern "C" char DAT_003f6098[];
extern "C" char DAT_0042aec8[];
class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
class Ops {
  public:
    void a();
    void b();
};
class LoadInventory {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual LoadInventory* vfunc_2(unsigned char);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad[8];
    Ops* mA;
    Ref* mB;
};
void thunk_FUN_00267090(void*);
void thunk_FUN_00267090(LoadInventory*);
LoadInventory* LoadInventory::vfunc_2(unsigned char b) {
    Ops* p = mA;
    *(int*)this = ((int)DAT_0042aec8);
    if (p) {
        p->a();
        p->b();
        thunk_FUN_00267090((void*)p);
    }
    if (mB)
        mB->f1();
    *(int*)this = ((int)DAT_003f6098);
    if (b & 1)
        thunk_FUN_00267090(this);
    return this;
}
