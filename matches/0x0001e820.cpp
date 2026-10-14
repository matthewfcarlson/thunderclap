class Mgr_1e820;
class Holder_1e820 {
  public:
    Holder_1e820* first();
    Mgr_1e820* second();
};
class Mgr_1e820 {
  public:
    char pad[0x1b64];
    void* ptr;
};
class Helper_1e820 {
  public:
    void run();
};
class Obj_1e820 {
  public:
    virtual void f0();
    virtual void f1();
};
Helper_1e820* __stdcall FUN_001b6580(void*);
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
    Mgr_1e820* m = ((Holder_1e820*)mA)->first()->second();
    if (m->ptr == this)
        m->ptr = 0;
    if (mB) {
        FUN_001b6580(mB)->run();
        Obj_1e820* q = (Obj_1e820*)mB;
        if (q) {
            q->f1();
            mB = 0;
        }
    }
}
