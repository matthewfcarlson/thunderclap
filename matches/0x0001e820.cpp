class Mgr;
class Holder {
  public:
    Holder* first();
    Mgr* second();
};
class Mgr {
  public:
    char pad[0x1b64];
    void* ptr;
};
class Helper {
  public:
    void run();
};
class Obj {
  public:
    virtual void f0();
    virtual void f1();
};
Helper* __stdcall FUN_001b6580(void*);
class CGrabAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4();
    char p4[0x18];
    void* mA;
    char p20[8];
    void* mB;
};
void CGrabAction::vfunc_4() {
    Mgr* m = ((Holder*)mA)->first()->second();
    if (m->ptr == this)
        m->ptr = 0;
    if (mB) {
        FUN_001b6580(mB)->run();
        Obj* q = (Obj*)mB;
        if (q) {
            q->f1();
            mB = 0;
        }
    }
}
